#include <stdint.h>
#include <stdio.h>

typedef struct {
  uint8_t *title;
  uint8_t *script;
  uint8_t *run_on_failure;
  uint8_t stop_on_failure;
  uint8_t *depends_on;
  uint8_t skip_if_dependency_fails;
} Step;

typedef Step **Steps;

Steps parse(FILE *f);
void run(Steps s);
