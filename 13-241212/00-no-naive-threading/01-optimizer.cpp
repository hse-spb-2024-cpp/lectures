#include <cassert>
#include <chrono>
#include <iostream>
#include <thread>

#pragma GCC optimize("-O2")

int main() {
    int data = 0;
    bool stop = false;

    std::thread t([&]() {
        while (!stop) {  // Hmm: stop is always the same => loop is either infinite or never starts.
            data++;
            std::cout << "data = " << data << ", stop = " << stop << "\n";
        }
        std::cout << "thread finished data = " << data << ", stop = " << stop << "\n";
    });

    while (data < 100) {}  // Hmm: data is always the same => loop is either infinite or never starts.
    assert(data >= 100);
    std::cout << "done " << data << "\n";
    stop = true;

    // Hmm: optimizations like this are important. The alternative is to always re-read from memory, memory is slow.

    t.join();
}
