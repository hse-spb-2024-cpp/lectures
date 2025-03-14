#include <iostream>

template<typename F>
void for_each_cpp(int *begin, int *end, F f) {
    while (begin != end)
        f(*begin++);
}

void for_each_c(int *begin, int *end, void (*f)(int)) {
    while (begin != end)
        f(*begin++);
}

void print_int(int x) {
    std::cout << " " << x;
}

int main(void) {
    int arr[10]{};
    arr[3] = 100;
    arr[5] = 200;

    for_each_cpp(arr, arr + 10, print_int);
    std::cout << "\n";

    for_each_cpp(arr, arr + 10, [](int x) { std::cout << " " << x; });
    std::cout << "\n";

    for_each_cpp(arr, arr + 10, [first = true](int x) mutable {
        if (!first) std::cout << " ";
        std::cout << x;
        first = false;
    });
    std::cout << "\n";

    for_each_c(arr, arr + 10, print_int);
    std::cout << "\n";

    for_each_c(arr, arr + 10, [](int x) { std::cout << " " << x; });
    std::cout << "\n";

    /*for_each_c(arr, arr + 10, [first = true](int x) mutable {
        if (!first) std::cout << " ";
        std::cout << x;
        first = false;
    });
    std::cout << "\n";*/
}
