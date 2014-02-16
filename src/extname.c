
#include "extname.h"
#include <string.h>

const char *extname(const char *filename)
{
  char *loc = strrchr(filename, '.');
  return loc? loc : "";
}
