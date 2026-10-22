#include <iostream>

int main(){
    int n, c = 0, c2 = 0;
    std::cin >> n;

    while(c2 < n){
        c = 0;
        while(c < n){
            std::cout << "*"; 
            c++;
        }

        std::cout << std::endl;
        c2++;
    }

}