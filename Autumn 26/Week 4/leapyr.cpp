#include <iostream>

// we can define a function that returns a bool

bool leap_year(int year){
    bool ly;
    if( (year % 4) == 0){ 

        if( (year % 100) == 0){ 

            if( (year % 400) == 0){
                ly = true;
            }
            else{
                ly = false;
            }

        }
        else{   
            ly = true;
        }
    }
    else{
        
        ly = false;
    }

    return ly;
}

int main(){
    
    std::cout << (leap_year(1600) == true) << std::endl;
    std::cout << (leap_year(2000) == true) << std::endl;
    std::cout << (leap_year(1700) == false) << std::endl;
    std::cout << (leap_year(1800) == false) << std::endl;
    std::cout << (leap_year(1900) == false) << std::endl;
    std::cout << (leap_year(2100) == false) << std::endl;
    std::cout << (leap_year(2200) == false) << std::endl;
    std::cout << (leap_year(2300) == false) << std::endl;
    std::cout << (leap_year(2500) == false) << std::endl;
    std::cout << (leap_year(2600) == false) << std::endl;
    std::cout << (leap_year(2700) == false) << std::endl;
    std::cout << (leap_year(2900) == false) << std::endl;
    std::cout << (leap_year(3000) == false) << std::endl;
    std::cout << (leap_year(2400) == true) << std::endl;
    std::cout << (leap_year(2800) == true) << std::endl;

    //testing ^^

    int input_year;

    std::cout << "please enter a year" << std::endl;
    std::cin >> input_year;

    if(leap_year(input_year)){
        std::cout << "it's a leap year" << std::endl;
    }
    else{
        std::cout << "it's not a leap year" << std::endl;
    }
}
