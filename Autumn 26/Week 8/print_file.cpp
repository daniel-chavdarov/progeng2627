#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

// argc is the number of command line arguments
// argv is an array of C-style strings
// we'll see what this means more in detail later on

int main(int argc, char* argv[]){
    if(argc != 2){
        std::cout << "not correct input" << std::endl;
        return 0;
    }

    std::ifstream text;
    text.open(argv[1]);
    if(!text.is_open()){
        std::cout << "error opening file" << std::endl;
        return EXIT_FAILURE;
    }

    std::string tmp;
    while(text >> tmp){
        std::cout << tmp << std::endl;
    }

    text.close();

}