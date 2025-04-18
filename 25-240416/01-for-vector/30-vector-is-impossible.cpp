#include <iostream>
#include <memory>
#include <string>
#include <vector>

struct Person {
    std::string first_name, last_name;

    Person() : first_name(10'000, 'x') {
        std::cout << "Person created\n";
    }
};

int main() {
    Person *people = std::allocator<Person>().allocate(4);

    Person *a = new (people) Person();

    // Technically UB before C++20: `people` is not a pointer to an array.
    // "Raw memory" (e.g. by an allocator) is not the same as "Array of `T`".
    // Hence, you cannot do pointer arithmetics with `T*` pointing inside "raw memory".
    // Same with `char*`.
    // Fixed in C++20: https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2020/p0593r6.html#dynamic-construction-of-arrays
    // Worked in practice in C++03 as well, so we do that.
    //
    // Do not try placement new of arrays: https://github.com/Nekrolm/ubbook/blob/master/pointer_prominence/array_placement_new.md
    Person *b = new (people + 1) Person();
    Person *c = new (people + 2) Person();

    c->~Person();
    b->~Person();
    a->~Person();

    std::allocator<Person>().deallocate(people, 4);

    // Other weird stuff: `std::launder` and `const`s inside `Person`
    // https://wg21.link/P0532R0
    // More recent: https://stackoverflow.com/a/70419156/767632
    // https://miyuki.github.io/2016/10/21/std-launder.html
    // One can also try changing type of the object: https://gcc.gnu.org/bugzilla/show_bug.cgi?id=86908
}
