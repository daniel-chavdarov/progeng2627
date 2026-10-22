#include <iostream>

int main() {
    int n, rem;
    
    std::cout << "enter a numer" << std::endl;
    std::cin >> n;

    rem = n % 2;
    
    std::cout << "0 means even, 1 means odd: " << rem << std::endl;
    
}