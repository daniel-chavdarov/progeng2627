#include <iostream>
#include <cmath>

int main(){
    double x, n, result = 0;

    std::cout << "pick a number and then how many time to sum its powers" << std::endl;
    std::cin >> x >> n;
    for(int i = 1; i < n + 1 ; i++){
        result += std::pow(x, i);
    }
    std::cout << result << std::endl;
}