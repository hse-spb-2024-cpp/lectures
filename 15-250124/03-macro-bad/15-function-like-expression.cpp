#include <iostream>

#define print_twice(x) (std::cout << (x), std::cout << (x))

int main() {
    if (2 * 2 == 5)
        print_twice(55);
    else
        print_twice(123);

    print_twice(10), print_twice(20);
}
