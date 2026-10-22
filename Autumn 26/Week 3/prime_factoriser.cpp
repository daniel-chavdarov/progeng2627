#include <iostream>

int main(){
    int n;
    int divisor = 2;
    std::cout << "enter a number" << std::endl;
    std::cin >> n;


    while(n > 1){
        while(n % divisor == 0){
            std::cout << divisor << " ";
            n /= divisor;
        }
        divisor += 1;
    }
    std::cout << std::endl;
}