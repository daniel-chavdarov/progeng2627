#include <iostream>

int smallest_factor(int n){
    for(int i = 2; i <= n/2; i++){
        if(n % i == 0){
            return i;
        }
    }
    return 0;
}

int main(){
    std::cout << (smallest_factor(2) == 0) << std::endl;
    std::cout << (smallest_factor(4) == 2) << std::endl;
    std::cout << (smallest_factor(28561) == 13) << std::endl;
    std::cout << (smallest_factor(17) == 0) << std::endl;

}