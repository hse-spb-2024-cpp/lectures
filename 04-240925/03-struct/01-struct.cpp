#include <iostream>

struct Point {
    // non-static data members (jargon: fields, поля)
    int x, y;  // default initialization (e.g. nothing for `int`, empty `vector`)

    // member function (jargon: methods, методы)
    int dist2() {  // no `self` like in Python
        return x * x + y * y;
    }

    void operator+=(const Point &other) {  // operator overload
        x += other.x;
        y += other.y;
    }
};  // important semicolon!

void foo(const Point &p) {
}

int main() {
    Point p;
    //std::cout << p.x << " " << p.y << "\n";  // UB: not initialized
    p.x = 10;
    p.y = 20;
    std::cout << p.x << " " << p.y << "\n";
    std::cout << p.dist2() << "\n";

    Point p2;
    p2.x = 5;
    p2.y = 6;

    p += p2;
    p.operator+=(p2);
    std::cout << p.x << " " << p.y << "\n";
}
