#include <cassert>
#include <vector>

// 'Владеющий' vs 'невладеющий' указатели

struct Foo { int x; };

Foo *make_foo_1(int x) {  // Возвращает 'владеющий' указатель: надо delete, можно заменить на unique_ptr
   return new Foo{x};
}

std::vector<Foo> foos;
Foo *make_foo_2(int x) {  // Возвращает 'невладеющий' указатель: не надо delete, им владеет vector
    foos.push_back(Foo{x});
    return &foos.back();
}
void clear_foo_2() {
    foos.clear();
}

int main() {
    Foo *f1 = make_foo_1(123);
    assert(f1->x == 123);

    Foo *f2 = make_foo_1(456);
    assert(f2->x == 456);

    Foo *f3 = make_foo_2(789);
    assert(f3->x == 789);

    Foo *f4 = make_foo_2(12);
    assert(f4->x == 12);
}
