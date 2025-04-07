#ifndef A_H_
#define A_H_

#ifdef __cplusplus
extern "C" {
#endif

const int N_cpp = 100;  // C++ only
#define N_c 100  // C++ and C

struct Point {
   int x, y;
};
struct TwoPoints {
   Point a1, b1;  // C++ only
   struct Point a2, b2;  // C++ and C
};

int foo(int x = 100);  // C++ only
int foo(int x);  // C++ and C, no default arguments. At all.

#ifdef __cplusplus
}
#endif

#endif  // A_H_
