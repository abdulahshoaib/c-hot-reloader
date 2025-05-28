#include "ui/ui.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("fatal error: no C file attached");
    return EXIT_FAILURE;
  }

  ui_init();
  ui_render_log("Moniterring Changes...");
  ui_render_error("error");

  while (1) {
    if (ui_getinput() == -1)
      break;
  }

  ui_cleanup();
  system("clear");

  printf("argument: %s", argv[1]);

  return EXIT_SUCCESS;
}
