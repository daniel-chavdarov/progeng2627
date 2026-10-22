#include <iostream>

int main(){
    int n;
    std::cin >> n;

    for(int c2 = 1; c2 < n+1; c2++){

        for(int c = 1; c < n+1; c++){
            std::cout << c*c2 << "\t"; 
        }

        std::cout << std::endl;

    }

}