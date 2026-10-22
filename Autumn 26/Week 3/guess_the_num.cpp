#include <iostream>
#include <string>

int main(){
    std::cout << "think of a number between 0 and 100 and i will guess your number" << std::endl;
    std::cout << "i will guess then you have to tell me higher or lower" << std::endl;
    int guess = 50, ubound = 100, lbound = 0;
    std::string input;

    while((input!= "yes")&&(input!= "Yes")&&(input!= "YES")){
        std::cout << "my guess is: " << guess << "\nam i correct or is it higher or lower" << std::endl;
        std::cin >> input;
        
        if((input == "higher")||(input == "Higher")||(input == "HIGHER")){
            lbound = guess;
        }
        else if ((input == "lower")||(input == "Lower")||(input == "LOWER")){
            ubound = guess;
        }

        guess = (ubound+lbound)/2;

        if(ubound-lbound == 0){
            std::cout << "your number is " << guess << std::endl;
            input = "yes";
        }
        
    }
    
}