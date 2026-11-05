#include <iostream>
#include <vector>

int min_vector_element(const std::vector<double>& vin){
    if(vin.size() == 0){
        return -1;
    }
    int min = vin[0], index = 0;

    for(int i=1; i<vin.size(); i++){
        if(vin[i] < min){
            index = i;
        }
    }

    return index;
}



int main(){
    std::vector<double> v{1, 0.5, 12, -13};
    std::cout << (min_vector_element(v) == 3) << std::endl;  

    v = {};
    std::cout << (min_vector_element(v) == -1) << std::endl;

    v = {0, 1, 2, 3, 4};
    std::cout << (min_vector_element(v) == 0) << std::endl;  

    v = {-12};
    std::cout << (min_vector_element(v) == 0) << std::endl;  

    v = {-12, 12, 2, -13, -40, 100, 2};
    std::cout << (min_vector_element(v) == 4) << std::endl;  
}