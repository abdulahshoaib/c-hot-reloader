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

  ui_init();
  ui_render_log_a("File Selected", target);
  ui_render_log("Hello ashan");

  while(1){
  if (build_target(target) == 0)
    ui_render_log_a(target, "built");
  if (runner() == 0)
    ui_render_output("\n\n=============");
  if (ui_getinput() == -1)
      break;
  }
  // threading needed across the program not working
  // just for the watcher program

  ui_render_log("x");
  stop_watcher();
  ui_cleanup();

  return EXIT_SUCCESS;
}
