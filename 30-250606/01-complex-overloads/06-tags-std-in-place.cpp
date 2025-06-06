#include <iostream>
#include <optional>
#include <utility>

int main() {
    // Constructors do not have a name.
    std::optional<std::pair<int, int>> opt(std::in_place, 10, 20);
    std::cout << opt->first << "\n";
    std::cout << opt->second << "\n";
}
