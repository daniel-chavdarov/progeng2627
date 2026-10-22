#include <iostream>

double maximum(double a, double b, double c){
    double max;

    if(a>b){
        if(a>c){max = a;}
        else{max = c;}
    }
    else if(b>c){max = b;}
    else{max = c;}

    return max;
}

int main(){
    std::cout << (maximum(1, 1, 1) == 1) << std::endl;

    std::cout << (maximum(1, 1, 2) == 2) << std::endl;
    std::cout << (maximum(1, 2, 1) == 2) << std::endl;
    std::cout << (maximum(2, 1, 1) == 2) << std::endl;

    std::cout << (maximum(2, 2, 1) == 2) << std::endl;
    std::cout << (maximum(2, 1, 2) == 2) << std::endl;
    std::cout << (maximum(1, 2, 2) == 2) << std::endl;

    std::cout << (maximum(3, 2, 1) == 3) << std::endl;
    std::cout << (maximum(3, 1, 2) == 3) << std::endl;

    std::cout << (maximum(2, 3, 1) == 3) << std::endl;
    std::cout << (maximum(1, 3, 2) == 3) << std::endl;

    std::cout << (maximum(2, 1, 3) == 3) << std::endl;
    std::cout << (maximum(1, 2, 3) == 3) << std::endl;
}