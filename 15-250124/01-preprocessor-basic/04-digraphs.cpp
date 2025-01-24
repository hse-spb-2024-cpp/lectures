// https://en.cppreference.com/w/c/language/operator_alternative
%:include <iostream>

int main()
<%
    std::cout << "Hello World %:\n";
    if (2 * 2 == 4 and 2 * 3 == 6) {
        std::cout << "Math Probably Works\n";
    }
%>
