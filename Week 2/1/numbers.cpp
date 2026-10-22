#include <iostream>

int main() {
    double a, b, c;

    a = 1;
    b = 2;
    c = a + b;

    std::cout << c << std::endl;
    // this line will print 3
    a = 2;
    std::cout << c << std::endl;
    // will print 3
    c = a + b;
    std::cout << c << std::endl;
    // will print 4

}
