#include <iostream>

int main(){
    int n, t = 0;
    double s = 0;
    std::cout << "enter a number:" << std::endl;
        std::cin >> n;

    while(n != 0){
        s+=n;
        t++;
        std::cout << "the average so far is:" << std::endl << s/t << std::endl;

        std::cout << "enter a number:" << std::endl;
        std::cin >> n;
    }
}