#include <iostream>

int main(){
    int n;

    std::cin >> n;

    while((-11 < n) && (n < 11)){
        std::cout << n << std::endl;
        std::cin >> n;
    }
}