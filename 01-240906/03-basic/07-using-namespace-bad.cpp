#include <iostream>

using namespace std;

int ranges;

int main() {
    cin >> ranges;  // OK with C++17, but in C++20 there is 'std::ranges', oops
    cout << ranges;
}
