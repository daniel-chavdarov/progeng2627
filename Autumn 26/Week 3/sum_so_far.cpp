#include <iostream>

int main(){
    int n, s = 0;
    std::cout << "enter a number:" << std::endl;
        std::cin >> n;

    while(n != 0){
        s+=n;
        std::cout << "the sum so far is:" << std::endl << s << std::endl;

        std::cout << "enter a number:" << std::endl;
        std::cin >> n;
    }
}