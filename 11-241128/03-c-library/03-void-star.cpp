#include <cassert>
#include <iostream>

// Ignore for now, insides of some library
void call_twice(void (*f)(void*), void *arg) {
    f(arg);
    f(arg);
}

void print_int(void *arg) {
    int *real_arg = static_cast<int*>(arg);
    std::cout << *real_arg << "\n";
}

void print_string(void *arg) {
    std::string *real_arg = static_cast<std::string*>(arg);
    std::cout << *real_arg << "\n";
}

int main() {
    int x = 10;
    std::string s = "hello";
    call_twice(print_int, &x);  // print_int(&x); print_int(&x);
    call_twice(print_string, &s);  // print_int(&s); print_int(&s);
}
