#include "core/builder.h"
#include "core/runner.h"
#include "ui/ui.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("fatal error: no C file attached");
    return EXIT_FAILURE;
  }

  const char *target = argv[1];

  ui_init();
  ui_render_log_a("File Selected", target);

  while (1) {
    if (build_target(target) == 0)
      ui_render_log_a(target, "built");
    if (runner() == 0)
      ui_render_output("\n\n=============");
    if (ui_getinput() == -1)
        break;
  }

  ui_cleanup();

  return EXIT_SUCCESS;
}
