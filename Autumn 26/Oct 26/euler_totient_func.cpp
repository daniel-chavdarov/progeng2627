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

int euler_totient(int n){
    int out = 0;
    for(int i=1; i<n; i++){
        if(gcd(i, n) == 1){
            out++;
        }
    }
    return out;
}

int main(){
    std::cout << (euler_totient(9) == 6) << std::endl;
    std::cout << (euler_totient(12) == 4) << std::endl;
    std::cout << (euler_totient(17) == 16) << std::endl;
    std::cout << (euler_totient(31) == 30) << std::endl;
    std::cout << (euler_totient(4) == 2) << std::endl;
    std::cout << (euler_totient(30) == 8) << std::endl;

    std::cout << std::endl;
    for(int i=1; i<51; i++){
        std::cout << i << ": " << euler_totient(i) << std::endl;
    }
}