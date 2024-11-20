#include <iostream>

struct MoveOnly {
    MoveOnly() {}

    // Alternative: make both `private`,
    //              no definition (and get "undefined reference" linkage error), or
    //              run-time assert
    MoveOnly(const MoveOnly &) = delete; /*{
        assert(false);
        std::cout << "copy ctor\n";
    }*/
    MoveOnly &operator=(const MoveOnly &) = delete;/*{
        std::cout << "copy assign\n";
        return *this;
    }*/

    MoveOnly(MoveOnly &&) {
        std::cout << "move ctor\n";
    }
    MoveOnly &operator=(MoveOnly &&) {
        std::cout << "move assign\n";
        return *this;
    }
};

int main() {
    MoveOnly a;
    MoveOnly b;
    a = b;
    a = std::move(b);
}
