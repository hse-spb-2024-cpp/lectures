#include <ranges>
#include <set>
#include <iostream>
#include <algorithm>

struct vector_iterator {
    std::vector<int>& vec;
    std::size_t index;

    int operator*() {
        return vec[index];
    }
};

int main() {
    std::multiset<int> ms{3, 1, 2, 4, 2};
    std::cout << ms.size() << "\n";

    auto it = ms.begin();

    // range-based for gets expanded into:
    [[maybe_unused]] auto it2 = ms.begin();
    //        1    2   2   3   4
    //  ^     ^    ^   ^   ^   ^    ^
    // rend  begin           rbegin end
    for (auto it = ms.begin(); it != ms.end(); ++it) {  // ++it faster than it++
        std::cout << " " << *it;  // dereference (разыменование)
    }
    std::cout << "\n";
    // All operations with iterators are O(1) amortized.

    for (int m : ms) {
        std::cout << " " << m;
    }

    ms.erase(ms.find(2));
    std::cout << ms.size() << "\n";
    ms.erase(ms.find(2));
    std::cout << ms.size() << "\n";

    std::cout << (ms.find(2) == ms.end());

    std::vector<int> v;

    std::sort(v.rbegin(), v.rend());

    ms.erase(2);  // ok, no-op
    // Элемента не существует: find() == end()
    // erase(end()) - UB
    ms.erase(ms.find(2));  // UB
    std::cout << ms.size() << "\n";

    std::multiset<int> ms2;
    std::cout << (ms.end() == ms2.end()) << "\n";  // not guaranteed, may be 0
}
