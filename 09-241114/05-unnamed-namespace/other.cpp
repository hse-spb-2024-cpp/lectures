#include <iostream>
#include "other.hpp"

// Linkage is a property of object/reference/function/type:
// 1. No linkage: only from the current scope
// 2. External linkage: visible in all translation units
// 3. Internal linkage: visible in the current translation unit only, but in all scopes. Independent between TUs.

// "unnamed namespace"
namespace {
// internal linkage, hides any external function '::foo()'
void foo() {
    std::cout << "other foo\n";
}
}  // namespace

// default: external linkage
void do_other() {
    [[maybe_unused]] int tmp = 123;  // no linkage
    [[maybe_unused]] static int tmp_static = 456;  // no linkage
    foo();
}
