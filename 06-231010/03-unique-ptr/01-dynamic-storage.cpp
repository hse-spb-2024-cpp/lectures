#include <cassert>
#include <vector>

struct Foo {
    std::vector<int> vec;
    Foo() : vec(10) {}
};

Foo *create_foo() {
    Foo *f = new Foo;  // Dynamic storage duration for 'Foo'.
                       // "На куче" (heap), не "бинарная куча"
    f->vec.resize(20);
    return f;
}

int main() {
    Foo *f = create_foo();
    Foo &fref = *f;
    Foo *f2 = &fref;
    assert(f == f2);
    (*f).vec.resize(30);
    fref.vec.resize(30);

    delete f;  // Leak otherwise
    // delete f;  // Double-free, UB
    f = nullptr;
    delete f;  // ok

    /*{
        Foo f_automatic;  // automatic storage duration
        Foo *f_automatic_ptr = &f_automatic;
        delete f_automatic_ptr;  // UB
    }*/
}
