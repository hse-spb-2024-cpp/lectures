#include <iostream>

template<typename T, typename F>
void for_each_cpp(T *begin, T *end, F f) {
    while (begin != end)
        f(begin++);
}

// 1. `template<typename T>` --> everything by pointer
// 2. `void*` instead of `T*`
// 3. Take `elem_size` together with `void*`
void for_each_c(const void *begin, const void *end, std::size_t elem_size, void (*f)(const void*)) {
    while (begin != end) {
        f(begin);
        begin = static_cast<const char*>(begin) + elem_size;
    }
}

void print_int(const void *x_void) {
    const int *x = static_cast<const int*>(x_void);
    std::cout << " " << *x;
}

int main(void) {
    const int arr[10]{
        0, 0, 100, 0, 0,
        200, 0, 0, 0, 0
    };

    for_each_cpp(arr, arr + 10, print_int);
    std::cout << "\n";

    for_each_c(arr, arr + 10, sizeof arr[0], print_int);
    std::cout << "\n";
}
