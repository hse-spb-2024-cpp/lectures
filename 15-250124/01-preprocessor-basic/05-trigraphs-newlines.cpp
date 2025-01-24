// https://en.cppreference.com/w/c/language/operator_alternative
#include <iostream>
#include <vector>
int main() {
    std::vector<int> v(10);
    v??(0??) = 10;  // v[0] = 10;
    std::cout << v[0] << "\n";

    std::cout << "1\n";
    //Does the following line compiles??/
    std::cout << "2\n";
    std::cout << "3\n";
}
