#include <iostream>

// Extra reading: https://isocpp.org/wiki/faq/multiple-inheritance#mi-not-evil
struct IntWriter {
    virtual void write(int value) = 0;
    virtual ~IntWriter() {}
};
struct IntReader {
    virtual int read() = 0;
    virtual ~IntReader() {}
};

// Implements single interface
struct Printer : IntWriter {
    void write(int value) override { std::cout << value; }
};
// Implements single interface
struct Scanner : IntReader {
    int read() override {
        int value;
        std::cin >> value;
        return value;
    }
};
// Implements multiple interfaces
struct Variable : IntWriter, IntReader {
private:
    int m_value = 0;
public:
    void write(int value) override { m_value = value; }
    int read() override { return m_value; }
};

void readAndPrint(IntReader &r) {
    std::cout << r.read() << "\n";
}

int main() {
    std::cout << sizeof(IntWriter) << "\n";  // vptr
    std::cout << sizeof(IntReader) << "\n";  // vptr
    std::cout << sizeof(Variable) << "\n";
    /*                            
    ┌──────────────────────────────┐
    │┌─────────┐                   │
    ││IntReader│                   │
    ││+vptr    │                   │
    │└─────────┘                   │
    │Scanner                       │
    │                              │
    └──────────────────────────────┘
    ┌──────────────────────────────┐
    │┌─────────┐┌─────────┐        │
    ││IntWriter││IntReader│        │
    ││+vptr    ││+vptr    │        │
    │└─────────┘└─────────┘        │
    │Variable                      │
    │                      +m_value│
    └──────────────────────────────┘
    */
    Scanner s;  // vptr
    readAndPrint(s);

    Variable v;
    v.write(10);
    readAndPrint(v);
}
