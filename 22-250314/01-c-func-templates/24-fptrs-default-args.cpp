void foo(int = 10) {}

int main() {
    void (*f1)(int) = foo;
    // f1();

    // No support for default arguments at all:

    // void (*f2)() = foo;
    // void (*f3)(int = 10) = foo;
}
