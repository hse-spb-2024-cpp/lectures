#include <iostream>

int main() {
    int *x;
    {
        int data = 123;
        x = &data;
    }
    std::cout << *x << "\n";  // UB
}
