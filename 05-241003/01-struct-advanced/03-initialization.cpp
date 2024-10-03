#include <iostream>
#include <vector>

// Lots of ways: https://habr.com/ru/companies/jugru/articles/469465/
// We care about syntax.

struct Point {
    int x;  // default initialization
    int y{};  // value initialization
};

int main() {
    // https://en.cppreference.com/w/cpp/language/default_initialization
    std::vector<int> v_default;  // empty vector
    int x_default;  // uninitialized value
    double d_default;  // uninitialized value
    Point p_default;  // x = uninitialized, y = 0

    // https://en.cppreference.com/w/cpp/language/value_initialization
    std::vector<int> v_value{};  // empty vector
    int x_value{};  // 0
    double d_value{};  // 0
    Point p_value{};  // x = 0, y = 0

    // https://en.cppreference.com/w/cpp/language/copy_initialization
    int x_copy = 123;
    std::vector<int> v_copy = {10, 20};  // copy list initialization
    Point p_copy = {10, 20};  // copy aggregate initialization

    // https://en.cppreference.com/w/cpp/language/direct_initialization
    int x_direct(13);
    std::vector<int> v_direct(10);  // vector of 10 elements

    // https://en.cppreference.com/w/cpp/language/list_initialization
    // aggregate initialization, or something special (`vector`)
    Point p_list{2, 3};
    std::vector<int> v_list1{1, 2, 3};  // list initialization
    std::vector<int> v_list2 = {1, 2, 3};  // copy list initialization

    // Temporary values
    auto val0 = int{};  // value initialization
    auto val1 = int(10);  // direct initialization
    auto val2 = int{10};  // list initialization
    auto val3 = static_cast<int>(10);
    auto val4 = std::vector<int>();  // value initialization + copy
    auto val5 = std::vector<int>{};  // list initialization (->value) + copy
    auto val6 = std::vector<int>{1, 2};  // list initialization + copy
}
