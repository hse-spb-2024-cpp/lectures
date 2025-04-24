#include <iostream>
#include <utility>

 // Template parameter pack, but of values instead of types.
template<int ...Ns>
std::pair<int, int> sum() {
    return {(Ns + ...), sizeof...(Ns)};
}

int main() {
    auto p = sum<1, 2, 3, 4>();
    std::cout << p.first << " " << p.second << "\n";  // 10 4
}
