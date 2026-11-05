#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>

int main(){
    std::string in_name, out_name;

    std::cout << "enter the name of the input file" << std::endl;
    std::cin >> in_name;

    std::cout << "enter the name of the output file" << std::endl;
    std::cin >> out_name;

    std::ifstream infile; 
    infile.open(in_name);

    std::vector<int> v;

    if(!infile.is_open()){ 
        std::cout << "error opening file" << std::endl;
        return EXIT_FAILURE;
    }

    int tmp;

    while(infile >> tmp){
        v.push_back(tmp); 
    }

    infile.close(); 

    std::ofstream outfile;
    outfile.open(out_name);

    for(int i=0; i<v.size(); i++){
        outfile << v[v.size()-1-i] << std::endl;
    }

    outfile.close();

}