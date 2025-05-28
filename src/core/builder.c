// Recompiles the target program on any change
#include "core/builder.h"
#include "ui/ui.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int build_target(const char *path) {
  pid_t pid = fork();

  if (pid == 0) {
    execlp("gcc", "gcc", path, "-o", "build/target", NULL);
    ui_render_error("[ERROR] execlp() Failed");
    exit(0);
  }

  else if (pid > 0) {
    int status;
    waitpid(pid, &status, 0);
    return WEXITSTATUS(status);
  }

  else {
    ui_render_error("[ERROR] fork() Failed");
    return -1;
  }
}
