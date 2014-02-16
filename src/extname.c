
#include "extname.h"
#include <string.h>

int extname(char *dest, const char *filename, size_t num)
{
  size_t copied = 0;
  char c = 0;
  char *loc = strrchr(filename, '.');

  while (loc && copied < num && (c = *loc++) != '\0') {
    dest[copied++] = c;
  }

  if (copied < num)
    dest[copied] = '\0';
  else
    return -1;

  return loc? 1 : 0;
}
