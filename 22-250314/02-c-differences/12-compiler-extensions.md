Lots of compiler-specific stuff:

https://gcc.gnu.org/onlinedocs/gcc-11.2.0/gcc/#toc-Extensions-to-the-C-Language-Family

* Nested functions in C
* `__attribute__((constructor))`
* Compound expression:
  ```
  int result =
    ({
       int y = foo();
       int z;
       if (y > 0) z = y;
       else z = - y;
       z;
    });
  ```
