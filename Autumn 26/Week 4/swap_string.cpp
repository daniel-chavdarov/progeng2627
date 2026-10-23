#include <iostream>
#include <string>

void myswap(std::string& s1, std::string& s2){
    std::string tmp;
    tmp = s1;
    s1 = s2;
    s2 = tmp;
}

int main(){
    std::string s1, s2;

    std::cout << "please enter two strings" << std::endl;
    std::cin >> s1 >> s2;

    std::cout << "you entered:" << std::endl;
    std::cout << "s1: " << s1 << std::endl;
    std::cout << "s2: " << s2 << std::endl;

    myswap(s1, s2);

    std::cout << "after swapping the values:" << std::endl;
    std::cout << "s1: " << s1 << std::endl;
    std::cout << "s2: " << s2 << std::endl;
}