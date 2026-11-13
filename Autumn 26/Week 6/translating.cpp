#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>

void file2vector(std::ifstream& file, std::vector<std::string>& v){
    std::string tmp;
    while(file >> tmp){
        v.push_back(tmp);
    }
}

int search_vector(std::string s, const std::vector<std::string>& vin){
    for(int i=0; i<vin.size(); i++){
        if(s == vin[i]){
            return i;
        }
    }
    return -1;
}

int main(){
    std::string ad_name, sheet_name;
    std::cout << "What is the name of the file with the advert?" << std::endl;
    std::cin >> ad_name;
    std::cout << "What is the name of the file with the translator?" << std::endl;
    std::cin >> sheet_name;

    std::ifstream ad_file, sheet_file;
    ad_file.open(ad_name);

    if(!ad_file.is_open()){
        std::cout << "failed to open file" << std::endl;
        return EXIT_FAILURE;
    }

    sheet_file.open(sheet_name);

    if(!sheet_file.is_open()){
        std::cout << "failed to open file" << std::endl;
        return EXIT_FAILURE;
    }

    std::vector<std::string> ad_v{}, temp{}, word{}, translation{}, output{};
    file2vector(ad_file, ad_v);
    file2vector(sheet_file, temp);
    ad_file.close();
    sheet_file.close();

    for(int i=0; i<(temp.size()/2); i++){
        word.push_back(temp[2*i]);
        translation.push_back(temp[2*i+1]);
    }

    for(int i=0; i<ad_v.size(); i++){
        int index = search_vector(ad_v[i], word);
        if(index > -1){
            output.push_back(translation[index]);
        }
        else{
            output.push_back(ad_v[i]);
        }
    }

    std::ofstream output_file;
    output_file.open("translation.txt");
    for(int i=0; i<output.size(); i++){
        output_file << output[i] << " ";
    }
    output_file << std::endl;
    output_file.close();
}