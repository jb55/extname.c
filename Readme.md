# extname.c [![Build Status](https://secure.travis-ci.org/jb55/extname.c.png?branch=master)](https://travis-ci.org/jb55/extname.c)

extname for clib

## Installation

  Install with [clib](https://github.com/clibs/clib):

    $ clib install jb55/extname.c

## Example

```c
// build with -Ideps

#include "extname/extname.h"

strcmp(extname("some/extension.ext"), ".ext") == 0
strcmp(extname(".derp"), ".derp") == 0
strcmp(extname("."), ".") == 0
strcmp(extname("nothing"), "") == 0
```

## API

### const char *extname(const char *filename);

arguments

  * `filename` a filename

returns

  * pointer to the part of the filename which holds the extension,
    otherwise, a pointer to an empty string.

## License

  MIT


