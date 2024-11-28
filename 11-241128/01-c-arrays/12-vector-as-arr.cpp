#include <iostream>
#include <vector>
#include <set>

void print_all(const int *beg, const int *en) {
    // Just like iterators
    for (const int *it = beg; it != en; it++) {
        std::cout << *it << "\n";
    }
}

int main() {
    std::vector<int> vec(10);
    // Requires non-empty vec
    print_all(&vec[0], &vec[0] + vec.size());
    // print_all(vec.begin(), vec.begin() + vec.size());
    print_all(&*vec.begin(), &*vec.begin() + vec.size());

    // Works even with empty vec
    print_all(vec.data(), vec.data() + vec.size());
    std::cout << vec.data() << "\n";
    vec.clear();
    std::cout << vec.data() << "\n";
    vec.shrink_to_fit();
    std::cout << "after shrink_to_fit(): " << vec.data() << "\n";

    std::set<int> s{1, 2, 3};

    std::set<int>::iterator it_1 = s.begin();
    it_1++;  // ok

    // UB:
    print_all(&*s.begin(), &*s.begin() + 3);
    const int *s_it2 = &*s.begin();
    s_it2++;  // UB
}
