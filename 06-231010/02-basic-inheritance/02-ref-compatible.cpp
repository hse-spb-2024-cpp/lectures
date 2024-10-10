#include <cassert>
#include <iostream>
#include <string>
#include <sstream>

// Library

struct MyStream {
};

struct MyCoutStream : MyStream {  // inheritance: `MyStream` is "base" class, `MyCoutStream` is "derived" class.
    void write(const std::string &v) {
        std::cout << v;
    }
    void write(int v) {
        std::cout << v;
    }
};

struct MyStringStream : MyStream {
    std::ostringstream s;

    void write(const std::string &v) {
        s << v;
    }
    void write(int v) {
        s << v;
    }
};

// User code

struct Bigint {
    int x;
};

MyStream &operator<<(MyStream &s, Bigint &b) {  // `&` is important, otherwise creates new `MyStream`.
    // s.write(b.x);  // No `write` method.
    static_cast<void>(b);
    return s;
}

int main() {
    MyCoutStream s1;
    MyStringStream s2;
    Bigint x{123};
    s1 << x;  // Binds `MyStream&` to `MyCoutStream`!
    s1.write("!\n");
    s2 << x;  // Binds `MyStream&` to `MyStringStream`!
    std::cout << "|" << s2.s.str() << "|\n";
}
