#include <iostream>

struct IntWrapper {
    int *data;  // `std::unique_ptr<int>`, or even better: `int`

    IntWrapper() noexcept : data(nullptr) {
    }

    IntWrapper(int x) : data(new int(x)) {}

    IntWrapper(const IntWrapper &other) : data(other.data ? new int(*other.data) : nullptr) {
    }

    IntWrapper(IntWrapper &&other) noexcept : data(other.data) {
        other.data = nullptr;
        // Check out `std::exchange`.
    }

    // https://stackoverflow.com/a/3279550/767632
    // copy-and-swap idiom is about making `operator=` strong exception safe AND simple
    // downside:
    // 1. `a = a` does copy.
    // 2. `a = b` will _always_ allocate memory.
    IntWrapper& operator=(IntWrapper other) /* TODO: noexcept */ {  // copy or move to the temporary
        // swap with the temporary
        std::swap(data, other.data);
        // std::swap(*this, other);  // do not work, as it calls `operator=`
        return *this;
        // destroy the temporary `other`
    }

    ~IntWrapper() /* noexcept */ {
        delete data;
    }
};

int main() {
    IntWrapper a;
    IntWrapper b = 10;
    a = std::move(b);
    std::cout << a.data << " " << b.data << "\n";
    IntWrapper c = std::move(a);
    std::cout << a.data << " " << b.data << " " << c.data << "\n";
}
