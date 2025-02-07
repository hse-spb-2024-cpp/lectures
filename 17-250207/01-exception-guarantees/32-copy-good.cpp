#include <iostream>

// move constructor/assignment operator can (and should) almost always be noexcept

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

    IntWrapper& operator=(const IntWrapper &other) {
        if (this == &other) {
            return *this;
        }
        if (!other.data) {
            delete data;
            data = nullptr;
        } else {
            // The only operation that may throw.
            int *new_data = new int(*other.data);
            // Operations that do not throw.
            delete data;
            data = new_data;
        }
        return *this;
    }

    IntWrapper& operator=(IntWrapper &&other) noexcept {
        if (!other.data) {
            delete data;  // noexcept
            data = nullptr;
        } else {
            if (data) {
                *data = *other.data;
            } else {
                data = other.data;
                other.data = nullptr;
            }
        }
        return *this;
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
