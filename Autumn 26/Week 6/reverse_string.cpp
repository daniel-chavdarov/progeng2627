#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>

int main(){
    std::ifstream infile; 
    infile.open("strings.txt");

    std::vector<std::string> v;

    if(!infile.is_open()){ 
        std::cout << "error opening file" << std::endl;
        return EXIT_FAILURE;
    }

    std::string tmp;

    while(infile >> tmp){
        v.push_back(tmp); 
    }

    infile.close(); 

    for(int i=0; i<v.size(); i++){
        std::cout << v[v.size()-1-i] << std::endl;
    }

}