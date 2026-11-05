#include <iostream>
#include <vector>

int main(){
    std::vector<int> v;
    v.push_back(13);
    v.push_back(8);
    v.push_back(5);

    std::cout <<  v[0]*(v[1]+v[2]) << std::endl;

}