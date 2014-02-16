
#include "extname.h"
#include <string.h>

const char *extname(const char *filename)
{
  const char *c = filename;

  // skip leading ./ if it exists
  if (*c != '\0')
  if (*c++ == '.')
  if (*c != '\0')
  if (*c++ == '/')
    filename = c;

  const char *slash = strrchr(filename, '/');
  const char *loc = strrchr(slash? slash : filename, '.');
  return loc? loc : "";
}
