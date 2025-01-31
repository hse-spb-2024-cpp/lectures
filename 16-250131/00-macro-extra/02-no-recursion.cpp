#include <iostream>

#define FOO(x) if (x > 0) { std::cout << x; FOO(x - 1) }

// Extra reading: Boost::PP (preprocessor).

// TODO: actually kind of recursion is possible, see Habr article

int main() {
    FOO(5);
}
