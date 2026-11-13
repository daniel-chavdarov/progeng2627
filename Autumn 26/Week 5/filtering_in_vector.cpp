#include <iostream>
#include <vector>

void filter_v(const std::vector<double>& vin, double t, std::vector<double>& vout){
    vout.clear();
    for(int i=0; i<vin.size(); i++){
        if(vin[i] < t){
            vout.push_back(vin[i]);
        }
    }
}

int main(){
    std::vector<double> v, vout;
    double t;

    v = {1, 2, 3, 4, 5, 500, 50, 5000};
    t = 5;
    filter_v(v, t, vout);
    std::cout << (vout == std::vector<double> {1, 2, 3, 4}) << std::endl;

    v = {};
    t = 5;
    filter_v(v, t, vout);
    std::cout << (vout == std::vector<double> {}) << std::endl;

    v = {-3, -4.5, 30, 300, -20.6};
    t = -4.1;
    filter_v(v, t, vout);
    std::cout << (vout == std::vector<double> {-4.5, -20.6}) << std::endl;

    v = {1, 2, 3, 4, 5, 500, 50, 5000};
    t = -60;
    filter_v(v, t, vout);
    std::cout << (vout == std::vector<double> {}) << std::endl;
}