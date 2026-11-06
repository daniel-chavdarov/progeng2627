#include <iostream>

int gcd(int a, int b){
    int divisor, dividend, remainder;
    if(a > b){
        dividend = a;
        divisor = b;
    }
    else{
        dividend = b;
        divisor = a;
    }

    remainder = dividend % divisor;

    while(remainder > 0){
        dividend = divisor;
        divisor = remainder;
        remainder = dividend % divisor;
    }

    return divisor;
}

int main(){
    std::cout << (gcd(48, 18) == 6) << std::endl;
    std::cout << (gcd(1071, 462) == 21) << std::endl;
    std::cout << (gcd(101, 101) == 101) << std::endl;
    std::cout << (gcd(360, 396) == 36) << std::endl;

}