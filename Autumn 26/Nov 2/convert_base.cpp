#include <iostream>
#include <vector>
#include <utility>

std::string read_key(int n, const std::vector<std::pair<int, std::string>>& key){
    for(int i=0; i<key.size(); i++){
        if(key[i].first == n){
            return key[i].second;
        }
    }
    return "";
}

int reverse_read_key(std::string s, const std::vector<std::pair<int, std::string>>& key){
    for(int i=0; i<key.size(); i++){
        if(key[i].second == s){
            return key[i].first;
        }
    }
    return -1;
}

bool digits_in_base(int num, int base, std::vector<int>& digits){
    if(!(1 < base && base < 17)){
        return false;
    }
    digits = {};
    std::vector<int> remainder={};
    remainder.push_back(num % base);
    while(num / base != 0){
        num = num / base;
        remainder.push_back(num % base);
    }
    for(int i=remainder.size()-1; i>-1; i--){
        digits.push_back(remainder[i]);
    }
    return true;
}

void print_digits_as_number(const std::vector<int>& digits){
    std::vector<std::pair<int, std::string>> key = {
        {10, "A"}, {11, "B"}, {12, "C"}, {13, "D"}, {14, "E"}, {15, "F"}
    };
    for(int i=0; i<digits.size(); i++){
        if(digits[i] < 10){
            std::cout << digits[i];
        }
        else{
            std::cout << read_key(digits[i], key);
        }
    }
    std::cout << std::endl;
}

int power(int base, int power){
    int res = 1;
    for(int i=0; i<power; i++){
        res *= base;
    }
    return res;
}

int digits_to_decimal(const std::vector<int>& digits, int base){
    int decimal = 0;
    for(int i=0; i<digits.size(); i++){
        decimal += digits[i] * power(base, digits.size() - 1 - i);
    }
    return decimal;
}

bool convert_base(const std::vector<int>& digits_in, int base_in, int base_out, std::vector<int>& digits_out){
    if(!((1 < base_in && base_in < 17) && (1 < base_out && base_out < 17))){
        return false;
    }
    int decimal = digits_to_decimal(digits_in, base_in);
    digits_out = {};
    return (digits_in_base(decimal, base_out, digits_out));
}


struct TestCase {
    std::vector<int> digits_in;
    int base_in;
    int base_out;
    std::vector<int> expected_digits;
    bool expected_success;
};

int main() {
    std::vector<TestCase> test_cases = {
        // Octal 372 = hexadecimal FA
        {{3, 7, 2}, 8, 16, {15, 10}, true},

        // Binary to decimal-style base 10
        {{1, 0, 1, 0}, 2, 10, {1, 0}, true},

        // Decimal 250 to hexadecimal
        {{2, 5, 0}, 10, 16, {15, 10}, true},

        // Hexadecimal FA to binary
        {{15, 10}, 16, 2, {1, 1, 1, 1, 1, 0, 1, 0}, true},

        // Same base: octal remains unchanged
        {{7, 3, 2}, 8, 8, {7, 3, 2}, true},

        // Same base: hexadecimal remains unchanged
        {{10, 11, 12}, 16, 16, {10, 11, 12}, true},

        // Base 3: 1020 = 33 decimal = 113 in base 5
        {{1, 0, 2, 0}, 3, 5, {1, 1, 3}, true},

        // Base 5: 1000 = 125 decimal = 1111101 in base 2
        {{1, 0, 0, 0}, 5, 2, {1, 1, 1, 1, 1, 0, 1}, true},

        // Invalid input base
        {{1, 0, 0}, 1, 10, {}, false},

        // Invalid output base
        {{1, 0, 0}, 10, 17, {}, false},

        // Both bases invalid
        {{1, 0, 0}, 1, 17, {}, false}
    };

    for (const TestCase& test : test_cases) {
        std::vector<int> digits_out;
        bool result = convert_base(
            test.digits_in,
            test.base_in,
            test.base_out,
            digits_out
        );

        bool passed = (result == test.expected_success);

        if (result && test.expected_success) {
            passed = passed && (digits_out == test.expected_digits);
        }

        std::cout << "Input: ";
        print_digits_as_number(test.digits_in);
        std::cout << " (base " << test.base_in << ") -> base "
                  << test.base_out << ": ";

        if (result) {
            print_digits_as_number(digits_out);
        } else {
            std::cout << "conversion failed";
        }

        std::cout << (passed ? " [PASS]" : " [FAIL]") << std::endl;
    }

    return 0;
}
