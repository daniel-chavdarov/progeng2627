#include <iostream>
#include <vector>

int main(){
    int n, s, tmp, occurences = 0;
    std::vector<int> v, indic;

    std::cout << "How many numbers do you want in the vector?" << std::endl;
    std::cin >> n;

    for(int i=0; i<n; i++){
        std::cout << "Input a number" << std::endl;
        std::cin >> tmp;
        v.push_back(tmp);
    }

    std::cout << "Pick a number to see the number of occurences of" << std::endl;
    std::cin >> s;

    for(int i=0; i<n; i++){
        if(v[i] == s){
            occurences++;
            indic.push_back(i);
        }
    }

    if (occurences > 0){
        std::cout << "there are " << occurences << " occurences of " << s << " at indices:" << std::endl;

        for(int i=0; i<indic.size(); i++){
            std::cout << indic[i] << std::endl; 
        }
    }
    else{
        std::cout << "there are no occurences of " << s << std::endl;
    }
}