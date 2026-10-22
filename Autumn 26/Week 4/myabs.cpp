#include <iostream>

double myabs(double in){
    double abs;

    if(in < 0){
        abs = -in;
    }
    else{
        abs = in;
    }
    return abs;
}

int main(){
    double n;
    std::cout << "please enter a nummber" << std::endl;
    std::cin >> n;
    std::cout << "|" << n << "|" << " = " << myabs(n) << std::endl;
}