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

int count(const std::vector<std::string>& text, std::string reference){
    int count = 0;
    for(int i=0; i<text.size(); i++){
        if(text[i] == reference){
            count++;
        }
    }
    return count;
}


int main(){
    std::vector<std::string> text{}, reference{};
    std::vector<int> counter{};

    std::ifstream text_file, reference_file;

    std::string text_name, reference_name;
    std::cout << "name of the text file" << std::endl;
    std::cin >> text_name;      //text.txt
    std::cout << "name of the reference file" << std::endl;
    std::cin >> reference_name; //words.txt

    text_file.open(text_name);
    if(!text_file.is_open()){ 
        std::cout << "error opening file" << std::endl;
        return EXIT_FAILURE;
    }

    reference_file.open(reference_name);
    if(!reference_file.is_open()){ 
        std::cout << "error opening file" << std::endl;
        return EXIT_FAILURE;
    }

    file2vector(text_file, text);
    file2vector(reference_file, reference);

    text_file.close();
    reference_file.close();

    for(int i=0; i<reference.size(); i++){
        counter.push_back(count(text, reference[i]));
    }

    std::ofstream outfile;
    outfile.open("count_words.txt");

    for(int i=0; i<reference.size(); i++){
        outfile << reference[i] << ": " << counter[i] << std::endl;
    }
    outfile.close();
}