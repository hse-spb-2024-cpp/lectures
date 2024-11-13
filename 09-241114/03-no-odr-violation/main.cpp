#include <vector>
// These are two independent overloads.
void foo(std::vector<int>&);
void foo(int);
void foo() {
}

int main() {
    foo();
    foo(10);
    std::vector<int> v{1,2,3};
    foo(v);
}
