template<typename T> struct Bar;
template<typename T>
struct Foo {
    template<typename U>
    void foo_public(Bar<U> *b);
};

template<typename U>
struct Bar {
private:
    int x;
    template<typename T>
    template<typename U_>
    friend void Foo<T>::foo_public(Bar<U_> *b);
};

template<typename T>
template<typename U>
void Foo<T>::foo_public(Bar<U> *b) {
    b->x++;
}

int main() {
    Foo<int> f;
    Bar<char> b;
    f.foo_public(&b);
}
// TODO: what about specializations, etc?
