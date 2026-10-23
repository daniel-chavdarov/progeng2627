#include <iostream>

void perim_area(double l, double w, double& area, double& perimeter){
    area = l * w;
    perimeter = 2 * (l + w);
}

int main(){
    double l = 12, w = 10, area, perimeter;
    perim_area(l, w, area, perimeter);
    std::cout << (area == 120 && perimeter == 44) << std::endl;
}