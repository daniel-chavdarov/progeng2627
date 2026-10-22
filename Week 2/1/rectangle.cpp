#include <iostream>

int main() { 
    double length, width, perimeter, area;

    std::cout << "length of rectangle" << std::endl;
    std::cin >> length;

    std::cout << "width of rectangle" << std::endl;
    std::cin >> width;

    perimeter = 2*(length + width);
    area = length*width;

    std::cout << "perimeter: " << perimeter << std::endl;
    std::cout << "area: " << area << std::endl;

}