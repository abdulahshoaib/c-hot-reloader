// forks and exec target binaries

#include "ui/ui.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int runner(void) {
  char *binary_path = "./target";
  int fd[2];
  pipe(fd);
  if (pipe(fd) == -1) {
    ui_render_error("pipe Failed");
    return -1;
  }

  pid_t pid = fork();

  if (pid == 0) {
    close(fd[0]); // not reading

    dup2(fd[1], STDOUT_FILENO);
    dup2(fd[1], STDERR_FILENO);

    close(fd[1]);

    execlp(binary_path, binary_path, NULL);
    ui_render_error("execlp() Failed");
    exit(1);
  }

  else if (pid > 0) {
    close(fd[1]); // not writting

    // 8KB of charachter data
    char buffer[8192];

    ssize_t total_bytes = 0;
    ssize_t bytes_read;
    const ssize_t buffer_size = sizeof(buffer);

    while ((bytes_read = read(fd[0], buffer + total_bytes,
                              buffer_size - total_bytes - 1)) > 0) {
      total_bytes += bytes_read;
      if (total_bytes >= buffer_size - 1) {
        break;
      }
    }

    close(fd[0]);

    if (bytes_read < 0) {
      ui_render_error("Pipe Read Failed");
      return -1;
    }

    buffer[total_bytes] = '\0';

    ui_render_output("=============\n\n");
    if (total_bytes > 0) {
      ui_render_output(buffer);
    }

    int status;
    waitpid(pid, &status, 0);
    return WEXITSTATUS(status);
  }

  else {
    ui_render_error("fork() Failed");
    return -1;
  }
}
