#include <vector>

namespace foo_ns {
void foo() {
    std::vector<int> v;
#define add(x) v.push_back(x)
    add(10);
    add(20);
    add(30);
    add(40);
// #undef add
};
}

/*int add(int a, int b) {
    return a + b;
}*/
int add(int a) {
    return a + 10;
}

int main() {
    foo_ns::foo();
}
