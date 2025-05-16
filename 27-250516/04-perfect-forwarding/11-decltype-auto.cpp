int x;

auto foo() {  // int
    return x;
}

auto &foo_ref() {  // int&
    return x;
}

auto foo_ref_caller_bad() {  // int
    return foo_ref();
}

decltype(auto) foo_ref_caller_bad() {  // int& ~ decltype(foo_ref())
    return foo_ref();
}

decltype(auto) bar() {  // int ~ decltype(x)
    return x;
}

decltype(auto) baz() {  // int& ~ decltype((x))
    return (x);
}

int main() {
}
