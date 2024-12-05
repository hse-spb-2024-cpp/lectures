#include <cassert>
#include <iostream>
#include <thread>

#pragma GCC optimize ("O0")

const int N = 500'000'000;
const int M = 1000;

int main() {
    int data = 0;
    auto worker = [&]() {
        for (int i = 0; i < N; i++) {
            data++;
        }
    };
    std::thread t(worker);
    for (int i = 0; i < M; i++) {
        if (data % 2 == 0) {  // TOCTOU problem: https://en.wikipedia.org/wiki/Time-of-check_to_time-of-use
            assert(data % 2 == 0);
            // Consequence: NEVER read values in multithreaded environment!
            // E.g. with filesystems it's fragile, but everyone ignores it:
            // https://www.reddit.com/r/cpp/comments/s8ok0h/comment/hti8jyt/
            // Rust does not ignore: https://blog.rust-lang.org/2022/01/20/cve-2022-21658.html
            std::cout << "data is " << data << " (in progress)\n";
        }
    }
    t.join();
    std::cout << "data is " << data << "\n";
    return 0;
}
