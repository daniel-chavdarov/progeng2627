#include <iostream>
#include <vector>

int main(){
    int n, t, tmp;
    std::vector<int> v;

    std::cout << "How many numbers do you want in the vector?" << std::endl;
    std::cin >> n;

    for(int i=0; i<n; i++){
        std::cout << "Input a number" << std::endl;
        std::cin >> tmp;
        v.push_back(tmp);
    }

    std::cout << "Pick a number to filter the vector with" << std::endl;
    std::cin >> t;
    std::cout << "Numbers in the vector less than " << t << ":" << std::endl; 

    for(int i=0; i<n; i++){
        if(v[i] < t){
            std::cout << v[i] << " ";
        }
    }

    std::cout << std::endl;
}