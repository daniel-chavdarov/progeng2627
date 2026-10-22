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

double sop(double x, double n){
    double result = 0;

    for(int i = 1; i < n + 1 ; i++){
        result += mypow(x, i);
    }
    return result;
}

int main(){
    std::cout << (sop(2,3) == 14) << std::endl;
    std::cout << (sop(-3,5) == -183) << std::endl;
    std::cout << (sop(4,12) == 22369620) << std::endl;
}