#include <iostream>
#include <string>

void for_each_c(void *begin, void *end, std::size_t elem_size, void (*f)(void*)) {
    while (begin != end) {
        f(begin);
        begin += elem_size;  // GCC extension: arithmetics for `void*` is same as for `char*`
    }
}

void print_int(int *x) {  // GCC extension `-fpermissive`: function pointers are compatible. Sometimes.
    std::cout << " " << *x;
}

void print_string(std::string *x) {
    std::cout << " " << *x;
}

int main(void) {
    int arr[10]{};
    arr[3] = 100;
    arr[5] = 200;

    for_each_c(arr, arr + 10, sizeof arr[0], print_int);
    std::cout << "\n";

    std::string arr2[]{"hello", "world"};
    for_each_c(arr2, arr2 + 2, sizeof arr2[0], print_string);
    std::cout << "\n";
}
