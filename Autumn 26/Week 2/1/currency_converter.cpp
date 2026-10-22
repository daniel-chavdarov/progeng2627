#include <iostream>

int main() { 
    double pounds, euros;

    std::cout << "enter the pounds you have" << std::endl;
    std::cin >> pounds;

    euros = 1.18*pounds;

    std::cout << "your pounds are worth " << euros << " euros" << std::endl;
}