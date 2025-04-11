#include <chrono>
#include <iostream>
#include <string>

struct Person {
    std::string full_name;

    void set_full_name(std::string_view new_full_name) {
        full_name = new_full_name;
    }
};
        
// Some people recommend against: "CppCon 2014: Herb Sutter "Back to the Basics! Essentials of Modern C++ Style", 1:03:19
// https://youtu.be/xnqTKD8uD64?si=_VsyLzuxBrHQxC5X&t=3799

int main() {
    Person p;
    constexpr int N = 1'000'000;

    auto start = std::chrono::steady_clock::now();

    for (int i = 0; i < N; ++i) {
         p.set_full_name("Hubert Blaine Wolfeschlegelsteinhausenbergerdorff Sr.");
    }

    std::cout << "Elapsed "
              << std::chrono::duration_cast<std::chrono::milliseconds>(
                     std::chrono::steady_clock::now() - start
                 )
                     .count()
              << "ms\n";
}
