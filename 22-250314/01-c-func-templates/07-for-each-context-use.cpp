#include <iostream>
#include <string>

void for_each_c(
        void *begin,
        void *end,
        std::size_t elem_size,
        void (*f)(void * /*farg*/, void* /*element*/),
        void *farg
) {
    while (begin != end) {
        f(farg, begin);
        begin = static_cast<char*>(begin) + elem_size;
    }
}

void print_int(void *farg, void *x_void) {
    bool *first = static_cast<bool*>(farg);
    int *x = static_cast<int*>(x_void);

    if (!*first) {
        std::cout << " ";
    }
    std::cout << *x;
    *first = false;
}

void print_string(void *farg, void *x_void) {
    bool *first = static_cast<bool*>(farg);
    std::string *x = static_cast<std::string*>(x_void);

    if (!*first) {
        std::cout << " ";
    }
    std::cout << *x;
    *first = false;
}

int main(void) {
    int arr[10]{};
    arr[3] = 100;
    arr[5] = 200;

    {
        bool first = true;
        for_each_c(arr, arr + 10, sizeof arr[0], print_int, &first);
        std::cout << "\n";
    }

    std::string arr2[]{"hello", "world"};

    {
        bool first = true;
        for_each_c(arr2, arr2 + 2, sizeof arr2[0], print_string, &first);
        std::cout << "\n";
    }
}
