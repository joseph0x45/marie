#include <stdint.h>
#include <stdio.h>

typedef struct {
  uint8_t *title;
  uint8_t *script;
  uint8_t *run_on_failure;
  uint8_t stop_on_failure;
  uint8_t *depends_on;
  uint8_t skip_if_dependency_fails;
  uint8_t failed;
} Step;

Step **parse(FILE *f);
void run(Step **s);

