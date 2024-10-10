#include <cassert>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

// Library

struct MyStream {  // "Abstract" class because of at least one "pure virtual" method.
    virtual void write(const std::string &) = 0;
    virtual void write(int) = 0;
};

struct MyCoutStream : MyStream {  // inheritnace
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
    s.write(b.x);  // "Virtual" call.
    return s;
}

int main() {
    std::vector<MyStream*> streams = {
        new MyCoutStream{},
        new MyStringStream{}
    };
    Bigint x{123};
    for (auto &s : streams) {
        (*s) << x;
        (*s).write("\n");
    }
    // TODO: delete, or even `vector<unique_ptr<MyStream>>`
}
