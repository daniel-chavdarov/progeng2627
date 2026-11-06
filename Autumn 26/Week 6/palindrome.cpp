#include <iostream>
#include <string>
#include <vector>
#include <utility>

std::string char_to_string(char c){
    std::string s;
    s.push_back(c);
    return s;
}

bool is_palindrome(std::string s){
    std::string nospace = "", flip = "";

    for(int i=0; i<s.size(); i++){
        if(char_to_string(s[i]) != " "){
            nospace.push_back(s[i]);
        }
    }

    for(int i=nospace.size()-1; i>-1; i--){
        flip.push_back(nospace[i]);
    }
    
    if(nospace == flip){
        return true;
    }
    return false;
}

int main(){

    std::vector<std::pair<std::string, bool>> test_cases = 
    {
        {"a man a plan a canal panama", true}, 
        {"a man plan a canal panama", false},
        {"a toyota", true},
        {"never odd or even", true},
        {"never even or odd", false}
    };

    for(int i = 0; i < test_cases.size(); i++){

        bool test = is_palindrome(test_cases[i].first);

        if(test == test_cases[i].second){
            std::cout << "passed" << std::endl;
        }
        else{
            std::cout << "FAILED" << std::endl;
            std::cout << test_cases[i].first << std::endl;
            std::cout << "expected: " << test_cases[i].second << std::endl;
            std::cout << "got: " << test << std::endl;
        }
    }
}