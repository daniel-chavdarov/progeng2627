#include <iostream>

int main(){
    int n;
    bool found_factor = false;

    std::cout << "please enter an integer greater than 1" << std::endl;
    std::cin >> n;

    int cf = 2;

    while((cf < n/2) && !found_factor){
       
        if( (n % cf) == 0){ // n can be divided by cf...

            found_factor = true;
            //...it means we have found a factor!
        }

        cf++;

    }

    if(found_factor){
        std::cout << "the number is not prime" << std::endl;
    }
    else{
        std::cout << "the number is prime" << std::endl;
    }
}