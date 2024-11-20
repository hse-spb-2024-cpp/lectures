#include <iostream>

#define DECLARE_OPTION(T) \
struct Optional ## T { \
private: \
    T value; \
    bool exists; \
public: \
};

DECLARE_OPTION(int)
DECLARE_OPTION(std::string)  // struct Optionalstd::string

struct Optionalint {
private:
    int value;
    bool exists;
public:

};

int main() {
}
