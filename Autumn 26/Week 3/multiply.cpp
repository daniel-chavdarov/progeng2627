#include <iostream>

int main(){

    double x, acc = 0;
    int n, i = 0;

    std::cin >> x >> n;

    while(i < n){
        acc += x;
        i = i + 1;
    }

    std::cout << x << "*" << n <<  " = " << acc << std::endl;

}