#include <vector>

template<typename> struct TD;  // "Type Display" in a compilation error

int& foo();
int&& bar();

int main() {
    int x = 10;
    int &y = x;
    int &&z = std::move(y);

    // decltype() has two modes:
    // 1. decltype(expression)
    TD<decltype(10)>();  // int
    TD<decltype(std::move(10))>();  // int&&
    TD<decltype( (x) )>();  // int&
    TD<decltype( (y) )>();  // int&
    TD<decltype( (z) )>();  // int&
    TD<decltype( x + 20 )>();  // int
    TD<decltype( foo() )>();  // int&
    TD<decltype( bar() )>();  // int&&
    // Returns depending on value category: T (prvalue), T& (lvalue), T&& (xvalue)
    // Reminder: rvalue = prvalue || xvalue

    // 2. decltype(name) - a variable/field/argument with no parens
    TD<decltype(x)>();  // int
    TD<decltype(y)>();  // int&
    TD<decltype(z)>();  // int&&
    // Returns: the declaration of `name`

    // In either mode: nothing is evaluated:
    std::vector<int> v;
    decltype(*v.begin()) v_value = 10;
}
