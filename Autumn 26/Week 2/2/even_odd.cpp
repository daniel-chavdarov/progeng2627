#include <iostream>

int main() {
    int n, rem;
    
    std::cout << "enter a number" << std::endl;
    std::cin >> n;

    rem = n % 2;
    
    if (rem==0){
        std::cout << "the number is even" << std::endl;
    }
    else{
        std::cout << "the number is odd" << std::endl;
    }
    
}