#include <iostream>
#include <vector>
#include <utility>
#include <string>

int main() {
    std::pair<int, std::string> p(50, "hello");
    std::cout << p.first << " " << p.second << "\n";

    std::vector<std::pair<int, std::string>> v;

    // Extra reading: emplace_back() works as well, but involves implicit conversions
    // https://abseil.io/tips/112

    v.push_back(std::pair<int, std::string>(10, "x20"));
    v.push_back(std::make_pair(10, "x20"));
    v.push_back(std::pair(10, "x20"));  // C++17
    v.push_back(std::pair{10, "x20"});  // C++17
    v.push_back({10, "x20"});  // Not always

    v.emplace_back(20, "x30");  // v.push_back(std::pair<int, std::string>(20, "30"));
    std::cout << "v:";
    for (const auto &x : v) {
        std::cout << " (" << x.first << " " << x.second << ")";
    }
    std::cout << "\n";
}
