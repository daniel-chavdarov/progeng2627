#include <iostream>
#include <fstream>
#include <cstdlib> 
#include <string>

int main(){
    std::string file;

    std::cout << "which file would you like to open" << std::endl;
    std::cin >> file;

    std::ifstream infile;
    infile.open(file);

    if(!infile.is_open()){
        std::cout << "error opening file" << std::endl;
        return EXIT_FAILURE;
    }

    
    int tmp, sum = 0;

    while(infile >> tmp){
        std::cout << tmp << std::endl;
        sum += tmp;
    }

    infile.close();

    std::cout << "the sum is " << sum <<std::endl;
        

    infile.close();
}