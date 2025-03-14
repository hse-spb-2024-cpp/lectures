#include <iostream>
#include <string>

template<typename T, typename F>
void for_each_cpp(T *begin, T *end, F f) {
    while (begin != end)
        f(begin++);
}

// 1. `template<typename T>` --> everything by pointer
// 2. `void*` instead of `T*`
// 3. Take `elem_size` together with `void*`
void for_each_c(void *begin, void *end, std::size_t elem_size, void (*f)(void*)) {
    while (begin != end) {
        f(begin);
        begin = static_cast<char*>(begin) + elem_size;
    }
}

void print_int(void *x_void) {
    int *x = static_cast<int*>(x_void);
    std::cout << " " << *x;
}

void print_string(void *x_void) {
    std::string *x = static_cast<std::string*>(x_void);
    std::cout << " " << *x;
}

int main(void) {
    int arr[10]{};
    arr[3] = 100;
    arr[5] = 200;

    for_each_cpp(arr, arr + 10, print_int);
    std::cout << "\n";

    for_each_c(arr, arr + 10, sizeof arr[0], print_int);
    std::cout << "\n";

    std::string arr2[]{"hello", "world"};

    for_each_cpp(arr2, arr2 + 2, print_string);
    std::cout << "\n";

    for_each_c(arr2, arr2 + 2, sizeof arr2[0], print_string);
    std::cout << "\n";

    // UB
    for_each_cpp(arr2, arr2 + 2, print_int);
    std::cout << "\n";

    // UB
    for_each_c(arr2, arr2 + 2, sizeof arr2[0], print_int);
    std::cout << "\n";
}
