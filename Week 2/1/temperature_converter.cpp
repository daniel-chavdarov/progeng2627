#include <iostream>
int main() {
    double c, f;
    //c - celcius, f - fahrenheit

    std::cout << "what's the temperature in celcius?" << std::endl;
    std::cin >> c;

    f = 1.8*c + 32;

    std::cout << "that is " << f << " fahrenheit" << std::endl;
}