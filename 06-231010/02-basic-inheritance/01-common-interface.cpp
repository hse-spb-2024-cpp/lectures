#include <cassert>
#include <iostream>
#include <string>
#include <sstream>

// Library

struct MyCoutStream {
    void write(const std::string &v) {
        std::cout << v;
    }
    void write(int v) {
        std::cout << v;
    }
};

struct MyStringStream {
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

MyCoutStream &operator<<(MyCoutStream &s, Bigint &b) {  // Duplication?
    s.write(b.x);
    return s;
}

MyStringStream &operator<<(MyStringStream &s, Bigint &b) {  // Duplication?
    s.write(b.x);
    return s;
}

int main() {
    MyCoutStream s1;
    MyStringStream s2;
    Bigint x{123};
    s1 << x;
    s1.write("!\n");
    s2 << x;
    std::cout << "|" << s2.s.str() << "|\n";
}
