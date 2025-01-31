#include <iostream>
#include <vector>

struct err1 {};
struct err2 {};

int main() {
    try {
        // throw err1();
        // throw err2();
        std::vector<int> vec(9000000000000000000LL);

        // int x = 1 / 0;
        // std::cout << "OK " << x << "\n";
    } catch (const err1 &) {
        std::cout << "1\n";
    } catch (const err2 &) {
        std::cout << "2\n";
    } catch (...) {  // Exceptions only. Not UB, not assertions!
        std::cout << "3\n";
    }
}
