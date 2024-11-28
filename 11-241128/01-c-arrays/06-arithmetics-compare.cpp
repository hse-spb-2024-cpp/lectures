#include <iostream>

void print_eq(int *a, int *b) {
    std::cout << "print_eq " << a << " " << b << " " << (a == b) << "\n";
}

int main() {
    int a[]{1, 2, 3, 4};
    int b[]{10, 20, 30, 40};

    int *p1 = a + 1;  // &a[1]
    int *p2 = a + 4;  // one-past-end
    int *p3 = b;      // &b[0]
    int *p4 = b + 2;  // &b[2]

    std::cout << "Always valid:\n";
    std::cout << (p1 == p2) << "\n";  // false
    std::cout << (p1 < p2) << "\n";  // true
    std::cout << (p1 > p2) << "\n";  // false

    std::cout << (p3 == p4) << "\n";  // false
    std::cout << (p3 < p4) << "\n";  // true

    std::cout << (p1 == nullptr) << "\n";  // false
    std::cout << (p3 == nullptr) << "\n";  // false

    std::cout << "Always valid:\n";
    std::cout << (p1 == p3) << "\n";  // false
    std::cout << (p1 == p4) << "\n";  // false

    // Not UB, but weird.  "Unspecified" behavior if one of pointers is one-past-end.  Not even documented.
    std::cout << "Unspecified:\n";
    std::cout << p2 << "\n";
    std::cout << p3 << "\n";
    std::cout << "== " << (p2 == p3) << "\n";
    std::cout << "!= " << (p2 != p3) << "\n";
    print_eq(p2, p3);  // ???? may be sometimes '==', sometimes '!='
    std::cout << *p2 << "\n";  // UB

    // Unspecified behavior.  Not documented.
    std::cout << ":\n";
    std::cout << (p1 < p3) << "\n";  // can be true
    std::cout << (p1 < p3) << "\n";  // can be false
    std::cout << (p1 > p3) << "\n";  //

    // Well-defined, used by `std::sort`, `std::set`...
    std::cout << std::less{}(p2, p3) << "\n";  // ?????
    std::cout << std::less{}(p3, p2) << "\n";  // ?????
}
