#include <iostream>

int main(){
    int a, b, q = 0;
    std::cout << "enter two numbers to divide (1st by 2nd)" << std::endl;
    std::cin >> a >> b;
    const int A = a;

    while(a >= b){
        a -= b;
        q += 1;
    }

    std::cout << A << "/" << b << " = " << q << " r" << a << std::endl; 
}