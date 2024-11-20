#include <iostream>
#include <utility>

struct Foo {
    int *x_ptr;

    Foo() : x_ptr(new int(10)) {
        std::cout << "Foo() " << this << "\n";
    }

    // Outdated: https://en.cppreference.com/w/cpp/language/rule_of_three
    //
    // Rule of zero: do not implement any of these.
    // https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#Rc-zero
    //
    // Rule of five: if one is implemented, implement all five.
    // https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#c21-if-you-define-or-delete-any-copy-move-or-destructor-function-define-or-delete-them-all
    Foo(const Foo &other) : x_ptr(new int(*other.x_ptr)) {  // copy constructor: direct init, copy init...
        std::cout << "Foo(const Foo&) " << this << " <- " << &other << "\n";
        // /* lvalue */ other;
    }

    Foo(Foo &&other) {  // move constructor: same, but initialized from rvalue
        x_ptr = new int(*other.x_ptr);
        if (false) {
            // moved-from state?  FIXME: all other methods do not consider it.
            x_ptr = other.x_ptr;  // see `std::exchange`
            other.x_ptr = nullptr;
        }

        std::cout << "Foo(Foo&&) " << this << " <- " << &other << "\n";
        // /* lvalue */ other;
    }

    Foo& operator=(const Foo &other) {
        *x_ptr = *other.x_ptr;
        std::cout << "operator=(const Foo&) " << this << " = " << &other << "\n";
        return *this;
    }

    Foo& operator=(Foo &&other) {
        *x_ptr = *other.x_ptr;
        std::cout << "operator=(Foo&&) " << this << " = " << &other << "\n";
        return *this;
    }

    ~Foo() {
        std::cout << "~Foo() " << this << "\n";
        delete x_ptr;
    }
};

void call_by_value(Foo f) {
    std::cout << "call_by_value " << &f << "\n";
}

Foo create_foo() {
    Foo f;
    std::cout << "create_foo " << &f << "\n";
    return f;  // `f` is local variable => considered rvalue, please do not std::move it, details later.
}

Foo passthrough(Foo x) {
    std::cout << "passthrough " << &x << "\n";
    return x;
}

int main() {
    Foo a;
    Foo b(/* lvalue */ a);  // Foo b = a
    Foo c(/* xvalue */ std::move(a));  // Foo c = std::move(a);
    Foo d;

    b = /* lvalue */ d;
    b = /* xvalue */ std::move(d);
    b = /* xvalue */ static_cast<Foo&&>(d);
    b = /* prvalue*/ Foo{};

    std::cout << "===== call 1 =====\n";
    call_by_value(/* lvalue */ a);

    std::cout << "===== call 2 =====\n";
    call_by_value(/* xvalue */ std::move(a));

    // Copy elision: copies/moves may be optimized out even if there are side effects, details are for later.
    std::cout << "===== call 3 =====\n";
    call_by_value(/* prvalue */ create_foo());

    // Copy elision is not that powerful
    std::cout << "===== call 4 =====\n";
    call_by_value(passthrough(create_foo()));

    std::cout << "===== dtors =====\n";
}
