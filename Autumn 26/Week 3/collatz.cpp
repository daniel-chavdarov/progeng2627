#include <iostream>

int main(){
    int n, counter = 0;
    std::cout << "enter a number" << std::endl;
    std::cin >> n;
    std::cout << std::endl;
    std::cout << n << " ";
    int max = n;

    while(n != 1){
        if(n%2 == 0){
            n = n/2;
        }
        else{
            n = 3*n + 1;
            if(n > max){
                max = n;
            }
        }

        counter += 1;
        std::cout << n << " ";
    }
    std::cout << std::endl;
    std::cout << "it took " << counter << " steps" << std::endl;
    std::cout << "the largest number in this sequence was " << max << std::endl;
}