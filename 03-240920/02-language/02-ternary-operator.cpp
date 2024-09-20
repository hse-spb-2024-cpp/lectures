#include <iostream>

int main() {
    int x;
    std::cin >> x;

    if (x == 4) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
    }

    // OK
    std::cout << (x == 4 ? "YES\n" : "NO\n");
    // print("YES\n" if x == 4 else "NO\n")  # Python

    // Not really OK
    x == 4 ? (std::cout << "YES\n") : (std::cout << "NO\n");

    // Not really OK
    int a = 10;
    int b = x == 4 ? a++ : --a;
    std::cout << a << " " << b << "\n";  // 1
}
