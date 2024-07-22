#include "marie.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *err_message;
const char *valid_properties[5] = {"script", "run_on_failure",
                                   "continue_on_failure", "depends_on",
                                   "skip_if_dependency_fails"};

Step **parse(FILE *f) {
  char line[256];
  Step **s = (Step **)calloc(10, sizeof(Step *));
  if (s == NULL) {
    err_message = "Error while allocating memory";
    return NULL;
  }
  int parsing_step = 0;
  while (fgets(line, sizeof(line), f)) {
    char *t = strtok(line, " ");
    if (strcmp(t, "#") == 0) {
      // line is a comment, skip
      continue;
    }
  }
  return NULL;
}

void run(Step **s) {}

int main(int argc, char **argv) {
  if ((argc == 3) && (strcmp(argv[1], "run") == 0)) {
    FILE *f;
    f = fopen(argv[2], "r");
    if (f == NULL) {
      perror("Error while reading file: ");
      return 1;
    }
    Step **s = parse(f);
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
