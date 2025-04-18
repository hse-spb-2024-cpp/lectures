// https://stackoverflow.com/questions/76863864/why-is-assigning-a-containers-element-to-the-container-not-a-well-defined-c

#include <iostream>
#include <string>
#include <utility>
#include <vector>
struct Foo {
    std::string s = "hello world very long string";
    std::vector<Foo> children;
};
int main() {
    std::vector<Foo> f(4);
    f[0].children.resize(2);
    /*
    f[0]      f[1]       f[2]      f[3]
    |
    f[0].children[0]
    f[0].children[1]
    */

    f = f;  // easy mode, special `if`
    f = f[0].children;  // (1)
    // auto tmp = f[0].children; f = std::move(tmp);  // (2)
    std::cout << f.size() << "\n";
}
