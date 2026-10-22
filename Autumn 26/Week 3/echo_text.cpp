#include <iostream>
#include <string>

int main(){
    std::string s;

    std::cin >> s;

    while((s!="stop") && (s!="Stop") && (s!="STOP")){
        std::cout << s << std::endl;
        std::cin >> s;
    }
}