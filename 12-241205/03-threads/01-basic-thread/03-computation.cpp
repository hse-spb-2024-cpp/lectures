#include <chrono>
#include <iostream>
#include <thread>
#include <vector>

std::vector<unsigned long long> results;

void worker(long long begin, long long end, int t) {
    unsigned long long sum = 0;
    for (int i = begin; i < end; i++) {
        sum += i * i / 2;
    }
    results[t] = sum;
}

int main() {
    const long long N = 10'000'000'000;
    const int K = 100;

    auto start = std::chrono::steady_clock::now();

    results.resize(K);
    std::vector<std::thread> ts;
    for (int i = 0; i < K; i++) {
        std::thread t(worker, N * i / K, N * (i + 1) / K, i);
        ts.emplace_back(std::move(t));  // note: std::thread cannot be copied
    }
    for (auto &t : ts) {
        t.join();
    }

    unsigned long long result = 0;
    for (auto r : results) {
        result += r;
    }
    std::cout << result << "\n";
    std::cout << "Elapsed "
              << std::chrono::duration_cast<std::chrono::milliseconds>(
                     std::chrono::steady_clock::now() - start
                 )
                     .count()
              << "ms\n";
}
