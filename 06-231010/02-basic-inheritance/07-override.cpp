#include <cassert>
#include <iostream>
#include <string>
#include <sstream>

// Library

struct MyStream {  // "Abstract" class because of at least one "pure virtual" method.
    virtual void write(const std::string &) = 0;
    virtual void write(int) = 0;
};

struct MyCoutStream : MyStream {  // inheritance
    void write(const std::string &v) override {
        std::cout << v;
    }
    void write(int v) override {
        std::cout << v;
    }
};

struct MyStringStream : MyStream {
    std::ostringstream s;

    void write(const std::string &v) override {
        s << v;
    }
    void write(int v) override {
        s << v;
    }
};

// User code

struct Bigint {
    int x;
};

MyStream &operator<<(MyStream &s, Bigint &b) {  // `&` is important, otherwise creates new `MyStream`.
    s.write(b.x);  // "Virtual" call.
    return s;
}

int main() {
    MyCoutStream s1;
    MyStringStream s2;
    // MyStream sBad;  // does not compile.
    Bigint x{123};
    s1 << x;  // Binds `MyStream&` to `MyCoutStream`!
    s1.write("!\n");
    s2 << x;  // Binds `MyStream&` to `MyCoutStream`!
    std::cout << "|" << s2.s.str() << "|\n";
}
