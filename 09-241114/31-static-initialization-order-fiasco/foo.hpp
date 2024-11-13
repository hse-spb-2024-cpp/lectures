#ifndef FOO_HPP_
#define FOO_HPP_

struct Foo {
    int x = 10;
    Foo();
};

extern Foo f;
Foo &get_foo();

#endif  // FOO_HPP_
