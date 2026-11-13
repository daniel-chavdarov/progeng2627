#include <iostream>
#include <vector>

int search_vector(int n, const std::vector<int>& vin){
    for(int i=0; i<vin.size(); i++){
        if(vin[i] == n){
            return i;
        }
    }
    return -1;
}

int main(){
    std::vector<int> v{1, 0, 12, -13};
    std::cout << (search_vector(-13, v) == 3) << std::endl;  

    v = {};
    std::cout << (search_vector(123, v) == -1) << std::endl;

    v = {0, 1, 2, 3, 4};
    std::cout << (search_vector(0, v) == 0) << std::endl;  

    v = {-12};
    std::cout << (search_vector(80, v) == -1) << std::endl;  

    v = {-12, 12, 2, -13, -40, 100, 2};
    std::cout << (search_vector(2, v) == 2) << std::endl;  
}