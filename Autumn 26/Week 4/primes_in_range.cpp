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
    int n1, n2;
    std::cin >> n1 >> n2;

    for(int i = 0; i < n2+1-n1; i++){
        if(smallest_factor(n1+i) == 0){
            std::cout << n1+i << std::endl;
        }
    }
}