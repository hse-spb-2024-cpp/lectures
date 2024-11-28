#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec{1, 2, 3};
    int &first = vec[0];
    std::vector<int>::iterator first_it = vec.begin();

    std::cout << first << " " << *first_it << "\n";
    vec.pop_back();  // 1 2
    std::cout << first << " " << *first_it << "\n";
    vec.push_back(4);  // 1 2 4
    std::cout << first << " " << *first_it << "\n";
    std::cout << vec.capacity() << "\n";
    vec.push_back(5);  // 1 2 4 5; invalidates both all iterators and pointers
    std::cout << vec.capacity() << "\n";
    std::cout << first << " " << *first_it << "\n";  // UB, UB
    std::cout << vec[0] << "\n";
}
