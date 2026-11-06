#include <iostream>
#include <vector>

void merge_vectors_int(const std::vector<int>& v1, const std::vector<int>& v2, std::vector<int>& merged){
    int i=0, j=0;       //use i to count through v1 and j for v2
    while((i < v1.size()) && (j < v2.size())){      //this will take us to either the end of v1 or v2
        if(v1[i] < v2[j]){
            merged.push_back(v1[i]);
            i++;
        }
        else{
            merged.push_back(v2[j]);
            j++;
        }
    }
    while(i < v1.size()){           //these next 2 while loops will finish off adding v1 or v2
        merged.push_back(v1[i]);    //only one of these loops will ever add elements to merged
            i++;
    }
    while(j < v2.size()){
        merged.push_back(v2[j]);
            j++;
    }
}


int main(){

    std::vector<int> v1;
    std::vector<int> v2;
    std::vector<int> out;

    std::vector<int> expected_output;

    out = {};
    v1 = {1, 3, 5, 6};
    v2 = {4, 6, 10};
    expected_output = {1, 3, 4, 5, 6, 6, 10};

    merge_vectors_int(v1, v2, out);

    if(out == expected_output){
        std::cout << "passed" << std::endl;
    }
    else{
        std::cout << "not passed" << std::endl;
    }

    out = {};
    v1 = {1, 10, 10, 10, 18};
    v2 = {4, 6, 10, 14, 20, 60};
    expected_output = {1, 4, 6, 10, 10, 10, 10, 14, 18, 20, 60};

    merge_vectors_int(v1, v2, out);

    if(out == expected_output){
        std::cout << "passed" << std::endl;
    }
    else{
        std::cout << "not passed" << std::endl;
    }

    out = {};
    v1 = {1, 2, 3, 4, 5, 20};
    v2 = {5, 6, 7, 8, 9};
    expected_output = {1, 2, 3, 4, 5, 5, 6, 7, 8, 9, 20};

    merge_vectors_int(v1, v2, out);

    if(out == expected_output){
        std::cout << "passed" << std::endl;
    }
    else{
        std::cout << "not passed" << std::endl;
    }
}