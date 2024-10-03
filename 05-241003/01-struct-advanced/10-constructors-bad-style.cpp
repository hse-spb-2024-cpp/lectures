#include <iostream>

struct ratio {
    int num;
    int denom;
    std::vector<int> unused_vector;
    ratio() {  // default constructor (default initialization/value initialization)
        num = 0;
        denom = 1;
        unused_vector.resize(1);
        std::cout << "Default constructor\n";
    }
    ratio(int value) {  // non-default constructor (direct/list initialization)
        num = value;
        denom = 1;
        unused_vector.resize(2);
        std::cout << "ratio(int)\n";
    }
};

int main() {
    {
        ratio r;  // default initialization
        std::cout << r.num << "\n";
        std::cout << r.denom << "\n";

        ratio r2{};  // value initialization
        std::cout << r2.num << "\n";
        std::cout << r2.denom << "\n";

        std::cout << ratio{}.num << "\n";
        std::cout << ratio().num << "\n";
    }

    {
        ratio r(10);  // direct initialization
        std::cout << r.num << "\n";
        std::cout << r.denom << "\n";

        ratio r2{10};  // direct list initialization
        std::cout << r2.num << "\n";
        std::cout << r2.denom << "\n";

        std::cout << ratio{10}.num << "\n";
        std::cout << ratio(10).num << "\n";
    }
}
