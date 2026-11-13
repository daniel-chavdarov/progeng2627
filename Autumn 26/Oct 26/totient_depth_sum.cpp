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

int totient_sum(int n, int &depth){
    int sum = 0;
    depth = 0;
    while(n != 1){
        n = euler_totient(n);
        depth++;
        sum += n;
    }
    return sum;
}

int main(){
    int depth = 0;
    std::cout << (totient_sum(30, depth) == 15) << " " << (depth == 4) << std::endl;
    depth = 0;
    std::cout << (totient_sum(12, depth) == 7) << " " << (depth == 3) << std::endl;
    depth = 0;
    std::cout << (totient_sum(49, depth) == 61) << " " << (depth == 5) << std::endl;
}