#include <iostream>

void foo(int, int = 10) {
    std::cout << "1\n";
}

void foo(double) {
    std::cout << "2\n";
}

//void foo(int) {
//    std::cout << "3\n";
//}

int main() {
    foo(10, 20);
    foo(30);
    foo(30.0);
}
