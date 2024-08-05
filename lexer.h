#ifndef LEXER_H
#define LEXER_H

typedef struct {
  char *buffer;
  char current_char;
  int current_position;
  int read_position;
  int current_line;
} Lexer;

Lexer *new_lexer(char *buffer, int current_line);

void free_lexer(Lexer *l);

void read_char(Lexer *l);

void skip_whitespace(Lexer *l);

char peek(Lexer *l);

#endif // !LEXER_H
