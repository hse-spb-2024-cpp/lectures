# Alternatives
* `*_cast` --> C-style-cast `(float)1`.
* `int a{}` --> `int a = 0;`
* `nullptr` --> `NULL`/`0` from the standard library: https://en.cppreference.com/w/c/types/NULL (no troubles with overloads: no overloads)
* namespaces --> prepend library name to all functions
* references --> pointers
* `bool` --> `int` + `0`/`1` OR `<stdbool.h>`
* `using pint = int*` --> `typedef int *pint;`
* `new`/`delete` --> `malloc`/`free`
* move/copy constructor/assignment operator --> `memcpy` or custom functions
* templates --> function pointers, `void*`, complicated macros

# Fully missing
* functions: overloading, default parameters
   * partially emulated: macro (`_Generic` and other magic)
* `std::vector`
* exceptions --> return code
