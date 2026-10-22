#include <iostream>
int main(){
    int n, rem;

    std::cout << "please enter a number" << std::endl;
    std::cin >> n;

    rem = n % 3;

    if (rem == 0){
        std::cout << "your number is divisible by 3" << std::endl;
    }
    else{
        std::cout << "your number isn't divisible by 3" << std::endl;
    }
}