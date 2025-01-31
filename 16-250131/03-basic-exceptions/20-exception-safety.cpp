#include <iostream>
#include <stdexcept>

struct cannot_read_int {
    cannot_read_int() {}
};

int readInt() {
    int x;
    std::cin >> x;
    if (!std::cin) {
        throw cannot_read_int();
    }
    return x;
}

struct Point {
    int x = 0, y = 0;
    void read() {  // what exception safety? (безопасность исключений)
        x = readInt();
        y = readInt();
    }
};

int main() {
    Point p;
    for (;;) {
        try {
            p.read();
        } catch (const cannot_read_int &) {
            std::cout << "Cannot read int\n";
            break;
        }
        std::cout << "Read point " << p.x << " " << p.y << "\n";
    }
    std::cout << "Last point is " << p.x << " " << p.y << "\n";
}
