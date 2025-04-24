#include <iostream>

template<typename T>
struct is_reference {
    static inline const bool value = false;
};

template<typename T1>
struct is_reference</*T=*/ T1&> {  // (const U)& as well.
    static inline const bool value = true;
};

template<typename T>
const bool is_reference_v = is_reference<T>::value;

int main() {
    std::cout << is_reference_v<int> << "\n";
    std::cout << is_reference_v<int&> << "\n";  // T1=int
    std::cout << is_reference_v<const int&> << "\n";  // T1=const int
}
