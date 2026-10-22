#include <iostream>
int main (){
    double n, absv;
    std::cout << "enter a number" << std::endl;
    std::cin >>n;

    if (n<0){
        absv = -n;
    }
    else{
        absv = n;
    }

    std::cout << "|" << n << "|" << " = " << absv << std::endl;
}