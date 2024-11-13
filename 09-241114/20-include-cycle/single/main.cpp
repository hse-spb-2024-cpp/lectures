#include <vector>

struct Bar;

struct Foo {
    std::vector<Bar> bs;

    void doit();
    friend void foo_friend();
};

struct Bar {
    Foo f;
};
