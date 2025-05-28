#include "core/builder.h"
#include "core/runner.h"
#include "core/watcher.h"
#include "ui/ui.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("fatal error: no C file attached");
    return EXIT_FAILURE;
  }

  const char *target = argv[1];

  pthread_t tid_watcher;
  pthread_create(&tid_watcher, NULL, start_watcher, (void *)(target));

  ui_init();
  ui_render_log_a("File Selected", target);

  if (build_target(target) == 0)
    ui_render_log_a(target, "built");
  if (runner() == 0)
    ui_render_output("\n\n=============");
  if (ui_getinput() == -1)

  ui_render_log("x");
  stop_watcher();
  pthread_join(tid_watcher, NULL);
  ui_cleanup();

  return EXIT_SUCCESS;
}
