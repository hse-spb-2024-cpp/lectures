#include <memory>

struct Base {
   int x = 10;

   Base() {}
   Base(const Base &other) = delete;
   Base &operator=(const Base &other) = delete;

   virtual std::unique_ptr<Base> clone() const {
       auto result = std::make_unique<Base>();
       result->x = x;
       return result;
   }
};
struct Derived1 : Base {
   int y = 20;

   std::unique_ptr<Base> clone() const override {
       auto result = std::make_unique<Derived1>();
       result->x = x;
       result->y = y;
       return result;
   }
};
struct Derived2 : Base {
   int z = 30;

   std::unique_ptr<Base> clone() const override {
       auto result = std::make_unique<Derived2>();
       result->x = x;
       result->z = z;
       return result;
   }
};

void foo([[maybe_unused]] Base &b) {
    std::unique_ptr<Base> b_copy = b.clone();
}

int main() {
    Derived1 d1;
    Derived2 d2;
    foo(d1);
    foo(d2);
}
