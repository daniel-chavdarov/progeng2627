#include <iostream>

int myabs(int in){
    int abs;

    if(in < 0){
        abs = -in;
    }
    else{
        abs = in;
    }
    return abs;
}

double mypow(double base, int exp){
    double result = 1; 
    bool is_neg = false;

    if(exp<0){is_neg = true;}
    exp = myabs(exp);

    for(int i=0; i<exp; i++){
        result *= base;
    }
    if(is_neg){result = 1/result;}

    return result;
}

int main(){
    std::cout << "2^3: " << mypow(2, 3) << std::endl;
    std::cout << "0.5^2: " << mypow(0.5, 2) << std::endl;
    std::cout << "1^0: " << mypow(1, 0) << std::endl;
    std::cout << "2^-3: " << mypow(2, -3) << std::endl;
    std::cout << "4^-1: " << mypow(4, -1) << std::endl;
    std::cout << "0.5^-2: " << mypow(0.5, -2) << std::endl;
}