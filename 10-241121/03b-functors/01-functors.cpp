#include <iostream>

void print(int x) {  // function
    std::cout << x << "\n";
}

struct CountingPrinter {  // functor
    int counter = 0;
    void operator()(int x) {  // non static
        std::cout << x << "\n";
    }
};

int main() {
    print(10);
    CountingPrinter p1, p2;
    p1(11);
    p1(12);
    p2(13);
    std::cout << p1.counter << " " << p2.counter << "\n";  // 2 1
}
