
# cextname

extname for clib

## Installation

  Install with [clib](https://github.com/clibs/clib):

    $ clib install jb55/cextname

## Example

```c
#include "extname.h"

// ...

char buffer[20];
int res = extname(&buffer[0], "some/extension.ext", sizeof(buffer))
// buffer contains ".ext"
// res is 1
```

## API

### int extname(char *dest, const char *filename, size_t num);

arguments

  * `dest` destination buffer to hold the extension
  * `filename` source buffer which reads the filename
  * `num` size of the destination buffer

returns

  * `1` match succeeded
  * `0` no extension found
  * `-1` buffer overflowed

## License

  MIT
