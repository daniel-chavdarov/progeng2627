#include <iostream>

int main(){
    int n;
    std::cout << "please enter a number" << std::endl;
    std::cin >> n;
    int max = n, min = n;

    while(n != 0){
        if(n > max){
            max = n;
        }
        if(n < min){
            min = n;
        }

        std::cout << "the max so far is: " << max << std::endl;
        std::cout << "the min so far is: " << min << std::endl;
        std::cout << "please enter a number" << std::endl;
        std::cin >> n;
    }
}