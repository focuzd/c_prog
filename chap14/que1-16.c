#include <stdio.h>

#define INDENT(x) PRAGMA(indent #x)
#define PRAGMA(x) _Pragma(#x)

INDENT(foo)