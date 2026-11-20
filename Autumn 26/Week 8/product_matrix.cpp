#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

std::vector<double> line_to_vector(std::string s){

    std::stringstream ss;
    std::string tmp;
    std::vector<double> out;

    ss << s;
    while(ss >> tmp){
        out.push_back(std::stod(tmp));
    }
    return out;
}

std::vector<std::vector<double>> read_matrix_from_file(std::string input_file){

    std::ifstream infile;
    infile.open(input_file);
    if(!infile.is_open()){
        std::cout << "error opening file " << input_file << std::endl;
        std::exit(EXIT_FAILURE);
    }

    std::string line;
    std::vector<std::vector<double>> out;

    while(std::getline(infile, line)){
        out.push_back(line_to_vector(line));
    }

    return out;
}

std::string matrix_to_string(std::vector<std::vector<double>> m){

    std::stringstream out;
    out << std::fixed << std::setprecision(2);

    for(int i=0; i<m.size(); i++){
        for(int j=0; j<m[0].size(); j++){
            out << (m[i][j]) << "\t";
        }
        out << "\n";
    }

    return out.str();
}

double dot_product(const std::vector<double>& v1, const std::vector<double>& v2){
    double out = 0;
    for(int i=0; i<v1.size(); i++){
        out += v1[i] * v2[i];
    }
    return out;
}

std::vector<double> select_column(std::vector<std::vector<double>> m, int column){
    std::vector<double> out;
    
    for(int i=0; i<m.size(); i++){
        out.push_back(m[i][column]);
    }
    return out;
}



std::vector<std::vector<double>> matrix_product //outputs m1 * m2 in that order
(
    const std::vector<std::vector<double>>& m1,
    const std::vector<std::vector<double>>& m2
)
{
    std::vector<std::vector<double>> out;

    for(int i=0; i<m1.size(); i++){ // counts through number of rows of m1

        out.push_back({});

        for(int j=0; j<m2[0].size(); j++){ // counts through the number of columns of m2 ---> so if 1 item is added at each cycle, the output will have rows of m1 by columns of m2 output dimensions

            out[i].push_back(dot_product(m1[i], select_column(m2, j)));

        }
    }

    return out;

}

int main(int argc, char* argv[]){

    if(argc != 3){
        std::cout << "two arguments needed" << std::endl;
        return EXIT_FAILURE;
    }

    std::vector<std::vector<double>> m1 = read_matrix_from_file(argv[1]);
    std::vector<std::vector<double>> m2 = read_matrix_from_file(argv[2]);

    std::vector<std::vector<double>> m3 = matrix_product(m1, m2);

    std::cout << matrix_to_string(m1) << std::endl;
    std::cout << "*" << std::endl << std::endl;
    std::cout << matrix_to_string(m2) << std::endl;
    std::cout << "=" << std::endl << std::endl;
    std::cout << matrix_to_string(m3) << std::endl;

}