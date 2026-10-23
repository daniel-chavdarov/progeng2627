#include <iostream>

void intdiv(int a, int b, int& q, int& r){
    q = 0;
    while(a > b){
        a -= b;
        q++;
    }
    r = a;
}

int main(){
    int a = 10, b = 3, q, r;
    intdiv(a, b, q, r);
    std::cout << (q == 3 && r == 1);
}