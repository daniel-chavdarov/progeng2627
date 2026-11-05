#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>

bool search_vector(std::string s, const std::vector<std::string>& vin){
    for(int i=0; i<vin.size(); i++){
        if(s == vin[i]){
            return true;
        }
    }
    return false;
}

void union_vector(const std::vector<std::string>& vin1, const std::vector<std::string>& vin2, std::vector<std::string>& vout){
    vout = vin1;
    for(int i=0; i<vin2.size(); i++){
        if(!search_vector(vin2[i], vin1)){
            vout.push_back(vin2[i]);
        }
    }
}

void intersection_vector(const std::vector<std::string>& vin1, const std::vector<std::string>& vin2, std::vector<std::string>& vout){
    for(int i=0; i<vin1.size(); i++){
        if(search_vector(vin1[i], vin2)){
            vout.push_back(vin1[i]);
        }
    }
}

int main(){
    std::string in1, in2;

    std::cout << "what is the name of the first file" << std::endl;
    std::cin >> in1;

    std::cout << "what is the name of the second file" << std::endl;
    std::cin >> in2;

    std::ifstream infile1; 
    infile1.open(in1);

    if(!infile1.is_open()){ 
        std::cout << "error opening file" << std::endl;
        return EXIT_FAILURE;
    }

    std::ifstream infile2; 
    infile2.open(in2);

    if(!infile2.is_open()){ 
        std::cout << "error opening file" << std::endl;
        return EXIT_FAILURE;
    }

    std::vector<std::string> v1 = {}, v2 = {}, vintersect = {}, vunion = {};
    
    std::string tmp;

    while(infile1 >> tmp){
        v1.push_back(tmp); 
    }
    infile1.close();

    while(infile2 >> tmp){
        v2.push_back(tmp); 
    }
    infile2.close();

    intersection_vector(v1, v2, vintersect);

    std::ofstream intersect;
    intersect.open("intersection.txt");

    for(int i=0; i<vintersect.size(); i++){
        intersect << vintersect[i] << std::endl;
    }
    intersect.close();

    union_vector(v1, v2, vunion);

    std::ofstream unions;
    unions.open("union.txt");

    for(int i=0; i<vunion.size(); i++){
        unions << vunion[i] << std::endl;
    }
    unions.close();

}