#include <iostream>
int main(){ 
    double height, weight, bmi;
    std::cout << "what is your height in m" << std::endl;
    std::cin >> height;

    std::cout << "what is your weight in kg" << std::endl;
    std::cin >> weight;

    bmi = weight/(height*height);

    std::cout << "your bmi is " << bmi << std::endl;
}