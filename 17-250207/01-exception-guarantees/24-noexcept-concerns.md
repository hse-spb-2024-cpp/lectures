Pros:

1. `noexcept` in function signature: better documentation
2. `noexcept` in function signature: can be checked in compile-time and adjusted for (e.g. algorithmically)
3. May be (or not) be faster: https://stackoverflow.com/questions/16104057/does-noexcept-improve-performance

Cons:

1. `noexcept` in function signature: compiler does not force anything, but happily terminates the program
2. Impossible to do "negative testing" that the function catches errors as expected: https://bloomberg.github.io/bde-resources/doxygen/bde_api_prod/group__bsls__asserttest.html#4.1
3. `noexcept` is kind of a "wide contract"

See ["The (John) Lakos Rule"](https://quuxplusone.github.io/blog/2018/04/25/the-lakos-rule/).

What we do in this course for training:

1. Specify `noexcept` everywhere where there are no exceptions including `bad_alloc`.
2. Strive for more `noexcept`.
3. In some lab:

```
#if ....
#define LAB_NOEXCEPT noexcept
#else
#define LAB_NOEXCEPT
#endif

void foo() LAB_NOEXCEPT {
   // ...
}
```
