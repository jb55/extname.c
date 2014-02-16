
#include "extname.h"
#include "assert.h"
#include <string.h>
#include <stdio.h>

#define BLEN 50

int main()
{
  char buffer[BLEN];
  int ret = 0;
  int test = 1;
  int tests = 10;

  printf("1..%i\n", tests);

  extname(&buffer[0], "/home/derp/something.ext", BLEN);
  assert(strcmp(&buffer[0], ".ext") == 0);
  printf("ok %i /home/derp/something.ext matches .ext\n", test++);

  extname(&buffer[0], ".ext", BLEN);
  assert(strcmp(&buffer[0], ".ext") == 0);
  printf("ok %i .ext matches .ext\n", test++);

  extname(&buffer[0], ".", BLEN);
  assert(strcmp(&buffer[0], ".") == 0);
  printf("ok %i . matches .\n", test++);

  extname(&buffer[0], "", BLEN);
  assert(strcmp(&buffer[0], "") == 0);
  printf("ok %i nothing matches nothing\n", test++);

  ret = extname(&buffer[0], ".", 2);
  assert(strcmp(&buffer[0], ".") == 0);
  assert(ret == 1);
  printf("ok %i '.' with size 2 doesnt overflow\n", test++);

  ret = extname(&buffer[0], ".", 1);
  assert(strcmp(&buffer[0], ".") == 0);
  assert(ret == -1);
  printf("ok %i '.' with size 1 overflows\n", test++);

  ret = extname(&buffer[0], "", 1);
  assert(strcmp(&buffer[0], "") == 0);
  assert(ret == 0);
  printf("ok %i '' with size 1 doesnt overflow\n", test++);

  ret = extname(&buffer[0], "", 0);
  assert(ret == -1);
  printf("ok %i '' with size 0 overflows\n", test++);

  ret = extname(&buffer[0], "/no/extension", 1);
  assert(strcmp(&buffer[0], "") == 0);
  assert(ret == 0);
  printf("ok %i '/no/extension' finds nothing\n", test++);

  ret = extname(&buffer[0], "/no/extension", 0);
  assert(strcmp(&buffer[0], "") == 0);
  assert(ret == -1);
  printf("ok %i '/no/extension' with size 0 overflows\n", test++);

}
