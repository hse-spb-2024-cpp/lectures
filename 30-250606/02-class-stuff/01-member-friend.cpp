struct Bar;
struct Foo {
private:
    void foo_private(Bar *b);
public:
    void foo_public(Bar *b);
    void foo_other(Bar *b);
};

struct Bar {
private:
    int x;
    // friend void Foo::foo_private(Bar *b);  // cannot see Foo::foo_private
    friend void Foo::foo_public(Bar *b);
};

void Foo::foo_public(Bar *b) {
    b->x++;
}

void Foo::foo_other([[maybe_unused]] Bar *b) {
    // b->x++;  // is not a friend
}

int main() {}
