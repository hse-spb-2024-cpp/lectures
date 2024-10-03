#include <iostream>
#include <set>

struct Point {
    int x;
    int y;

    int dist2() const {
        // We only use either `*this` or `this->` currently.
        // We do not know much about pointers yet.
        const Point &self = *this;
        return this->x * this->x + self.y * self.y;
        // return (*this).x
    }
};

int main() {
    std::cout << Point{3, 4}.dist2() << "\n";

    std::list<Point> l{Point{4, 5}};
    typename std::list<Point>::iterator lit = l.begin();
    std::cout << (*lit).x << "\n";
    std::cout << lit->x << "\n";
}
