#include <iostream>
#include <thread>

#pragma GCC optimize ("O0")

const int N = 50'000'000;
const int M = 10'000;

int main() {
    int data = 0;
    auto worker = [&]() {
        for (int i = 0; i < N; i++) {
            data++;   // load - compute - store
            /*
            data   T1      T2
             0    tmp=0
             0    tmp=1
             1
             1            tmp=1
             1            tmp=2
             2

            data   T1      T2
             0
             0    tmp=0   tmp=0
             0    tmp=1   tmp=1
             1            tmp=1
             1
            */
        }
    };
    std::thread t1(worker);
    std::thread t2(worker);
    for (int i = 0; i < M; i++) {
        int data_snapshot = data;
        if (data_snapshot % 2 == 0) {
            std::cout << "data is " << data_snapshot << " (in progress)\n";
        }
    }
    t2.join();
    t1.join();
    std::cout << "data is " << data << "\n";
    return 0;
}
