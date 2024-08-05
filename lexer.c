#include "lexer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Lexer *new_lexer(char *buffer, int current_line) {
  Lexer *l = (Lexer *)malloc(sizeof(Lexer));
  if (l == NULL) {
    perror("Error while allocating memory for lexer: ");
    return NULL;
  }
  l->buffer = buffer;
  size_t len = strlen(buffer);
  l->current_char = buffer[0];
  l->current_position = 0;
  l->read_position = 0;
  l->current_line = current_line;
  return l;
}

void free_lexer(Lexer *l) {
  if (l != NULL) {
    if (l->buffer != NULL) {
      free(l->buffer);
    }
    free(l);
  }
}

void read_char(Lexer *l) {
  if (l == NULL) {
    return;
  }
  if (l->read_position >= strlen(l->buffer)) {
    l->current_char = 0;
  } else {
    l->current_char = l->buffer[l->read_position];
  }
  l->current_position = l->read_position;
  l->read_position += 1;
}

char peek(Lexer *l) {
  if (l->current_position >= strlen(l->buffer)) {
    return 0;
  }
  return l->buffer[l->read_position];
}

void skip_whitespace(Lexer *l) {
  char c;
  while (l->current_char == ' ' || l->current_char == '\n' ||
         l->current_char == '\t' || l->current_char == '\r') {
    read_char(l);
  }
}
