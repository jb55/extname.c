
#include "extname.h"
#include "assert.h"
#include <string.h>
#include <stdio.h>

#define BLEN 50

int main()
{
  int test = 1;
  int tests = 5;

  printf("1..%i\n", tests);

  assert(strcmp(extname("/home/derp/something.ext"), ".ext") == 0);
  printf("ok %i /home/derp/something.ext matches .ext\n", test++);

  assert(strcmp(extname(".ext"), ".ext") == 0);
  printf("ok %i .ext matches .ext\n", test++);

  assert(strcmp(extname("."), ".") == 0);
  printf("ok %i . matches .\n", test++);

  assert(strcmp(extname(""), "") == 0);
  printf("ok %i nothing matches nothing\n", test++);

  assert(strcmp(extname("/no/extension"), "") == 0);
  printf("ok %i '/no/extension' finds nothing\n", test++);

  assert(strcmp(extname("./no/extension"), "") == 0);
  printf("ok %i './no/extension' finds nothing\n", test++);

}
