#ifndef OTHER_HPP_
#define OTHER_HPP_

#include <string>

extern int global_var;  // external linkage
const int TEN = 10;  // internal linkage
const std::string HELLO = "hello";  // internal linkage

void do_other();

#endif  // OTHER_HPP_