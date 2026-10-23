#include <iostream>

void myswap(double& n1, double& n2){
    double tmp;
    tmp = n1;
    n1 = n2;
    n2 = tmp;
}

void sort_three_numbers(double& s1, double& s2, double& s3){
    if(s1 > s2){
        myswap(s1, s2);
    }
    if(s2 > s3){
        myswap(s2, s3);
    }
    if(s1 > s2){
        myswap(s1, s2);
    }
}

int main(){
    double n1 = 3, n2 = 2, n3 = 1;
    sort_three_numbers(n1, n2, n3);
    std::cout << (n1 == 1 && n2 == 2 && n3 == 3) << std::endl;
}