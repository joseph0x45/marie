#include "marie.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char err_message[256];

Steps parse(FILE *f) {
  char line[256];
  while (fgets(line, sizeof(line), f)) {
    printf("%s", line);
  }
  return NULL;
}

void run(Steps s) {}

int main(int argc, char **argv) {
  if ((argc == 3) && (strcmp(argv[1], "run") == 0)) {
    FILE *f;
    f = fopen(argv[2], "r");
    if (f == NULL) {
      perror("Error while reading file: ");
      return 1;
    }
    Steps s = parse(f);
    if (s == NULL) {
      printf("%s\n", err_message);
      return 1;
    }
    run(s);
    fclose(f);
    return 0;
  }
  printf("Usage: marie run <file>\n");
  return 0;
}
