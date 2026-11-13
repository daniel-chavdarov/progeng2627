#include <iostream>
#include <vector>

void append_vectors(const std::vector<int>& vin1, const std::vector<int>& vin2, std::vector<int>& vout){
    vout = vin1;
    for(int i=0; i<vin2.size(); i++){
        vout.push_back(vin2[i]);
    }
}

int main(){
    std::vector<int> v1, v2, vout{};

    v1 = {1, 2, 3, 4};
    v2 = {1, 2, 3, 4};
    append_vectors(v1, v2, vout);
    std::cout << (vout == std::vector<int> {1, 2, 3, 4, 1, 2, 3, 4}) << std::endl;

    v1 = {3, 4};
    v2 = {1, 2};
    append_vectors(v1, v2, vout);
    std::cout << (vout == std::vector<int> {3, 4, 1, 2}) << std::endl;

    v1 = {};
    v2 = {};
    append_vectors(v1, v2, vout);
    std::cout << (vout == std::vector<int> {}) << std::endl;

    v1 = {1, 2, 3, 4};
    v2 = {};
    append_vectors(v1, v2, vout);
    std::cout << (vout == std::vector<int> {1, 2, 3, 4}) << std::endl;

    v1 = {};
    v2 = {1, 2, 3, 4};
    append_vectors(v1, v2, vout);
    std::cout << (vout == std::vector<int> {1, 2, 3, 4}) << std::endl;

}