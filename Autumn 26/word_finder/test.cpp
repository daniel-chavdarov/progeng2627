#include <iostream>
#include <vector>
#include <string>

int main(){
    std::string s = "abcdefghijklm";
    s.erase(3, 4);

    std::cout << s << std::endl;
}