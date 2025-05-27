#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("fatal error: no C file attached");
    return EXIT_FAILURE;
  }

  printf("argument: %s", argv[1]);

  return EXIT_SUCCESS;
}
