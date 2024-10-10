#/bin/bash
g++ -c main.cpp -O2 -DDEBUG -std=c++20
g++ -c print_hello.cpp -O2 -DDEBUG -std=c++20
g++ main.o print_hello.o -O2 -std=c++20 -o main-02
