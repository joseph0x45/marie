#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char *script;
  int continue_on_failure;
  char *run_on_failure;
  char *depends_on;
  int skip_if_dependency_failed;
} Step;

typedef enum {
  OPEN_BRACKET,
  CLOSING_BRACKET,
  SCRIPT,
  RUN_ON_FAILURE,
  CONTINUE_ON_FAILURE,
  DEPENDS_ON,
  SKIP_IF_DEPENDENCY_FAILED,
  HASHTAG,
  EQUALS,
} TokenType;

typedef struct {
  TokenType type;
  char *value;
} Token;

void print_usage() { printf("Usage: marie run <file>\n"); }

int main(int argc, char **argv) {
  if (argc <= 2 || argc > 3) {
    print_usage();
    return EXIT_SUCCESS;
  }
  if (strcmp(argv[1], "run") != 0) {
    print_usage();
    return EXIT_SUCCESS;
  }
  FILE *f = fopen(argv[2], "r");
  if (f == NULL) {
    perror("Error while opening file");
    return EXIT_FAILURE;
  }
  char *line = NULL;
  size_t len = 0;
  size_t nread = 0;
  int parsing_step = 0; // false by default
  int line_number = 0;
  while ((nread = getline(&line, &len, f)) != -1) {
    line_number++;
    char *t = strtok(line, " ");
    int token_is_newline = strcmp(t, "\n") == 0;
    if (t == NULL || token_is_newline) {
      printf("Token is null or is new line");
      continue;
    }
  }
  fclose(f);
  return EXIT_SUCCESS;
}
