#include <iostream>
#include <vector>


void from_1_to_n(int n, std::vector<int>& vout){

    for(int i = 0; i < n; i++){
        vout.push_back(i+1);
    }

}

int main(){
    // this program will not work as expected...
    std::vector<int> v;

    for(int n = 3; n < 7; n++){
        from_1_to_n(n, v);

        std::cout << "printing vector:" << std::endl;
        for(int i = 0; i < v.size(); i++){
            std::cout << v[i] << std::endl;
        }
    }
} // will print numbers from 1 to 3 then 1 to 4 then 1 to 5 then 1 to 6