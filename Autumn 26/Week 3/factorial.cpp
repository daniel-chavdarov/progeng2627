#include <iostream>

int main(){
    int x, result = 1;
    std::cout << "a number" << std::endl;
    std::cin >> x;

    for(int i = 0; i<x; i++){
        result *= (x-i);
    }

    std::cout << x << "!" << " = " << result << std::endl;
}