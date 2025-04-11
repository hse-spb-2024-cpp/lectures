template<typename T>
struct Foo {
private:
    int x = 0;

    friend struct Bar;
};

struct Bar {
    void bar() {
        Foo<T> f;
        f.x = 10;

        Foo<void> g;
        g.x = 10;
    }
};

int main() {
    Bar().bar();
}
