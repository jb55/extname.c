
#include "extname.h"
#include "assert.h"
#include <string.h>
#include <stdio.h>

#define BLEN 50

int main()
{
  int test = 1;
  int tests = 11;

  printf("1..%i\n", tests);

  assert(strcmp(extname("/home/derp/something.ext"), ".ext") == 0);
  printf("ok %i /home/derp/something.ext matches .ext\n", test++);

  assert(strcmp(extname("filename.txt"), ".txt") == 0);
  printf("ok %i 'filename.txt' matches '.txt'\n", test++);

  assert(strcmp(extname(".ext"), ".ext") == 0);
  printf("ok %i '.ext' matches '.ext'\n", test++);

  assert(strcmp(extname("."), ".") == 0);
  printf("ok %i '.' matches '.'\n", test++);

  assert(strcmp(extname(""), "") == 0);
  printf("ok %i nothing matches nothing\n", test++);

  assert(strcmp(extname("/no/extension"), "") == 0);
  printf("ok %i '/no/extension' finds ''\n", test++);

  assert(strcmp(extname("./no/extension"), "") == 0);
  printf("ok %i './no/extension' finds ''\n", test++);

  assert(strcmp(extname("./.no/extension"), "") == 0);
  printf("ok %i './.no/extension' finds ''\n", test++);

  assert(strcmp(extname("./.no/extension.txt"), ".txt") == 0);
  printf("ok %i './.no/extension.txt' finds '.txt'\n", test++);

  assert(strcmp(extname(".no/"), "") == 0);
  printf("ok %i '.no/' finds ''\n", test++);

  assert(strcmp(extname(".no/."), ".") == 0);
  printf("ok %i '.no/.' finds '.'\n", test++);

}
