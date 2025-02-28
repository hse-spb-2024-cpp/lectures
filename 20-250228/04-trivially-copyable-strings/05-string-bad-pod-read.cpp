#include <string>
#include <iostream>
#include <fstream>

struct Person {
    std::string first_name;
    std::string last_name;
};

int main() {
    Person p;
    {
        std::ifstream f("04.bin", std::ios::binary);
        f.read(reinterpret_cast<char*>(&p), sizeof p);  // UB
    }
    std::cout << p.first_name << "\n";
    std::cout << p.last_name << "\n";
}
