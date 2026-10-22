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
    double x, n, result = 0;

    std::cout << "pick a number and then how many time to sum its powers" << std::endl;
    std::cin >> x >> n;
    for(int i = 1; i < n + 1 ; i++){
        result += mypow(x, i);
    }
    std::cout << result << std::endl;
}