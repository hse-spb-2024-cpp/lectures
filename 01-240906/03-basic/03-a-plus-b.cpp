#include <iostream>

int main() {
    /* variable declaration: type of a variable is always fixed
       type is a pair of (possible values, possible operations) */
    int a /* comment here */, b;
    a = 5;  // ok
    std::cin >> a >> b;
    std::cout << a + b << std::endl;  // like "\n", but flushes buffer, much slower

    // std::cout << s << std::endl;  // compilation error: 's' is undefined

    // Alternative
    int s = a + b;  // declare variable right before it's needed please!
    std::cout << s << std::endl;
}
