#ifndef PRINT_HPP_
#define PRINT_HPP_

#include <iostream>

// `inline` means "ignore ODR", but all definitions should be exactly the same (incl. names)
inline void print(int value) {
    std::cout << "print(" << value << ")\n";
}

struct Printer {
    int value;

    static void newline();

    // `inline` is implicit
    /*inline*/ void print() {
        std::cout << "Printer.print(), value=" << value;
        newline();
    }

    void foo();
};

inline void Printer::newline() {
    std::cout << "\n";
}

/*void Printer::print() {
    std::cout << "Printer.print(), value=" << value << "\n";
}*/

#endif  // PRINT_HPP_
