#include <iostream>
#include <vector>
#include <utility>

std::string read_key(int n, const std::vector<std::pair<int, std::string>>& key){
    for(int i=0; i<key.size(); i++){
        if(key[i].first == n){
            return key[i].second;
        }
    }
    return "";
}

bool digits_in_base(int num, int base, std::vector<int>& digits){
    if(!(1 < base && base < 17)){
        return false;
    }
    digits = {};
    std::vector<int> remainder={};
    remainder.push_back(num % base);
    while(num / base != 0){
        num = num / base;
        remainder.push_back(num % base);
    }
    for(int i=remainder.size()-1; i>-1; i--){
        digits.push_back(remainder[i]);
    }
    return true;
}

void print_digits_as_number(const std::vector<int>& digits){
    std::vector<std::pair<int, std::string>> key = {
        {10, "A"}, {11, "B"}, {12, "C"}, {13, "D"}, {14, "E"}, {15, "F"}
    };
    for(int i=0; i<digits.size(); i++){
        if(digits[i] < 10){
            std::cout << digits[i];
        }
        else{
            std::cout << read_key(digits[i], key);
        }
    }
    std::cout << std::endl;
}


int main() {
    std::vector<std::vector<int>> test_cases = {
        {0, 2}, {1, 2}, {7, 2}, {8, 2}, {10, 2}, {15, 2}, {16, 2}, {64, 2}, {100, 2}, {255, 2},
        {10, 8}, {63, 8}, {64, 8}, {80, 8},
        {125, 5},
        {100, 3},
        {10, 16}, {15, 16}, {16, 16}, {26, 16}, {61, 16}, {62, 16}, {63, 16}, {64, 16}, {250, 16}, {255, 16}, {256, 16}, {1000, 16},
        {1023, 2}, {1024, 2},
    };
    std::vector<int> digits;

    for(int i=0; i<test_cases.size(); i++){
        if (digits_in_base(test_cases[i][0], test_cases[i][1], digits)) {
            print_digits_as_number(digits);
        } else {
            std::cout << "Invalid base" << std::endl;
    }
    }
    return 0;
}