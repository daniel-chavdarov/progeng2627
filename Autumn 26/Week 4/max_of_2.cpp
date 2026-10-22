#include <iostream>

double maximum(double a, double b){
    double max;

    if(a>b){max = a;}
    else{max = b;}

    return max;
}

int main(){
    std::cout << (maximum(1, 2) == 2) << std::endl;
    std::cout << (maximum(50.2, -3) == 50.2) << std::endl;
    std::cout << (maximum(-1, -2) == -1) << std::endl;
    std::cout << (maximum(10, 10) == 10) << std::endl;
}