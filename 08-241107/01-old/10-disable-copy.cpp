struct Base {
   int x = 10;

   Base() {}
   Base(const Base &other) = delete;
   Base &operator=(const Base &other) = delete;
};
struct Derived1 : Base {
   int y = 20;
};
struct Derived2 : Base {
   int z = 30;
};

void foo([[maybe_unused]] Base &b) {
    //Base b2 = b;   // not copy, slicing!
    //Base &b2 = b;   // not copy, reference to the same object!
    //Base *b2 = &b;   // not copy, pointer to the same object!

    Base b3;
    //b3 = b;  // not copy, slicing!
}

int main() {
    Derived1 d1;
    Derived2 d2;
    foo(d1);
    foo(d2);
    //Base copy_d1 = d1;

    Derived1 copy_d1 = d1;
}
