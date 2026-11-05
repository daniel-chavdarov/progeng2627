#include <iostream>
#include <fstream>

int main(){
    std::ifstream infile; 

    infile.open("input.txt");
    if(infile.is_open()){ 

        int tmp, sum = 0;

        while(infile >> tmp){
            std::cout << tmp << std::endl;
            sum += tmp;
        }

        infile.close();

        std::cout << "the sum is " << sum <<std::endl;
        
    }
    else{
        std::cout << "error opening file" << std::endl;
    }
}