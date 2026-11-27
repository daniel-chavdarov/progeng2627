#include <iostream>
#include <vector>
#include <string>
#include <utility>  // for pair

std::string char_to_string(char c){
    std::string s;
    s.push_back(c);
    // we can use push_back as we would do with std::vector
    return s;
}

bool search_vector(std::string s, const std::vector<std::string>& vin){
    for(int i = 0; i < vin.size(); i++){
        if(s == vin[i]){
            return true;
        }
    }
    return false;
}

void difference_vector(const std::vector<std::string>& vin1, const std::vector<std::string>& vin2, std::vector<std::string>& vout){
    for(int i = 0; i < vin1.size(); i++){
        if(!search_vector(vin1[i], vin2)){
            vout.push_back(vin1[i]);
        }
    }
}

void make_col(const std::vector<std::string>& grid, std::string& col, int index){
    col = {};

    for(int i = 0; i < grid.size(); i++){
        col.push_back(grid[i][index]);
    }
}

bool check_word(std::string check, std::string word, int& loc){ // check is what we are looking for the word in
                                                                // loc is the index of the first letter of the word
    int n = 0;  // n is the number of correct consecutive letters found -1 (index of current letter of word being checked)
    for(int i = 0; i < check.size(); i++){

        if(check[i] == word[n]){
            
            if(n == 0){
                loc = i;
            }
            n += 1;

            if(n == word.size() - 1){
                return true;
            }
        }
        else{
            n = 0;
            loc = -1;
            if(check[i] == word[0]){    // this is for the case that the first letter of the word is repeated twice in a row
                n += 1;                 // for example if the word being searched for is "apple" and check begins with "aa..."
            }                           // this will count the second a as the beginning of a possible "apple"
        }
    }

    return false;
}

void replace_row(std::string word, int r, int c, std::vector<std::string>& solution){
    solution[r].erase(c, word.size());
    solution[r].insert(c, word);
}

void replace_col(std::string word, int r, int c, std::vector<std::string>& solution){
    for(int i = 0; i < word.size(); i++){
        solution[r + i].erase(c, 1);
        solution[r + i].insert(c, char_to_string(word[i]));
    }
}



void find_words(
    const std::vector<std::string>& grid, 
    const std::vector<std::string>& words,
    std::vector<std::string>& solution,
    std::vector<std::string>& not_found
){
    std::string hash = "#", sol_row;
    for(int i = 0; i < grid[0].size(); i++){
        sol_row.push_back(hash[0]);
    }
    for(int i = 0; i < grid.size(); i++){
        solution.push_back(sol_row);
    }


    std::vector<std::pair<std::string, std::vector<int>>> in_row, in_col;   // str is the word, vector holds coords of first letter
    std::vector<std::string> in_sol;                                        // separated into row and col so that we know words orientation
    std::string col;                                                        
    int loc;

    for(int w = 0; w < words.size(); w++){
        for(int i = 0; i < grid.size(); i++){

            if(check_word(grid[i], words[w], loc)){
                in_row.push_back({words[w], {i, loc}});
                in_sol.push_back(words[w]);
            }

            make_col(grid, col, i);
            if(check_word(col, words[w], loc)){
                in_col.push_back({words[w], {loc, i}});
                in_sol.push_back(words[w]);
            }            
        }
    }

    for(int i = 0; i < in_row.size(); i++){
        replace_row(in_row[i].first, in_row[i].second[0], in_row[i].second[1], solution);
    }

    for(int i = 0; i < in_col.size(); i++){
        replace_col(in_col[i].first, in_col[i].second[0], in_col[i].second[1], solution);
    }

    difference_vector(words, in_sol, not_found);
}



int main(){

    std::vector<std::string> grid = {
        "xappleg",
        "dzeazkg",
        "zwazzbx",
        "dxnqzoy",
        "qyueytp",
        "pythtyg"
    };

    std::vector<std::string> words = {"peanut", "bot", "mango", "apple", "cinnamon"};
    std::vector<std::string> solution;
    std::vector<std::string> not_found;

    find_words(grid, words, solution, not_found); 

    std::vector<std::string> expected_solution = {
        "#apple#",
        "##e####",
        "##a##b#",
        "##n##o#",
        "##u##t#",
        "##t####"
    };

    std::vector<std::string> expected_not_found = {"mango", "cinnamon"};

    if( (solution == expected_solution) && (not_found == expected_not_found) ){
        std::cout << "test passed" << std::endl;
    }
    else{
        std::cout << "test failed" << std::endl;
    }

    std::cout << "solution:" << std::endl;
    for(int i = 0; i < solution.size(); i++){
        std::cout << solution[i] << std::endl;
    }

    std::cout << "not found:" << std::endl;
    for(int i = 0; i < not_found.size(); i++){
        std::cout << not_found[i] << std::endl;
    }

}