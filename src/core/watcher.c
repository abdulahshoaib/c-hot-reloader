// detection of changes in files
#include "core/builder.h"
#include "core/runner.h"
#include "ui/ui.h"
#include <stdlib.h>
#include <sys/inotify.h>
#include <unistd.h>

int fd, wd;
int sig = 0;

void *start_watcher(void *target) {
  char *target_s = (char *)(target);
  fd = inotify_init();

  if (fd < 0) {
    ui_render_error("inotify_init() Failed");
    exit(1);
  }

  wd = inotify_add_watch(fd, target_s, IN_MODIFY | IN_CLOSE_WRITE);
  if (wd < 0) {
    ui_render_error("inotify_add_watch() Failed");
    exit(1);
  }

  char buffer[4096];
  struct inotify_event *event;

  while (!sig) {
    int len = read(fd, buffer, sizeof(buffer));
    if (len < 0) {
      ui_render_error("read() Failed");
      break;
    } else {
      ui_render_log_b("read() Success", len);
    }

    for (int i = 0; i < len;) {
      event = (struct inotify_event *)&buffer[i];
      // ui_render_log_a(target, "changed");
      if (event->mask & IN_MODIFY || event->mask & IN_CLOSE_WRITE) {
      }
      i += sizeof(struct inotify_event) + event->len;
      ui_render_log_a(target, "changed");
    }
  }

  return NULL;
}

void stop_watcher(void) {
  sig = 1;
  inotify_rm_watch(fd, wd);
  close(fd);
}
