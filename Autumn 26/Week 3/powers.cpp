#include <iostream>

int main(){
    int x, n, result = 1;
    std::cout << "a number" << std::endl;
    std::cin >> x;

    std::cout << "a power" << std::endl;
    std::cin >> n;

    for(int i=0; i<n; i++){
        result *= x;
    }

    std::cout << x << "^" << n << " = " << result << std::endl;
}