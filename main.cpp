#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <boost/multiprecision/cpp_int.hpp>

using boost::multiprecision::cpp_int;

int main() {

    std::string input;

    std::cout << "Enter IBAN: ";
    std::getline(std::cin, input);

    // spaces removed
    input.erase(std::remove(input.begin(), input.end(), ' '), input.end());

    size_t inputLength = input.length();
    
    // uppercase
    std::transform(input.begin(), input.end(), input.begin(),
                   [](unsigned char c) { return std::toupper(c); });

    // shift first four char positions to the end
    if (inputLength > 4) {
        std::rotate(input.begin(), input.begin() + 4, input.end());
    }

    size_t pos = 0;

    bool valid = 0;

    cpp_int characterConvertedToNumber = 0;
    while (pos < inputLength) {

        char c = input[pos];

        if (c >= '0' && c <= '9') {
            characterConvertedToNumber = characterConvertedToNumber * 10 + c - '0';
            pos++;
        }
        else if (c >= 'A' && c <= 'Z') {
            characterConvertedToNumber = characterConvertedToNumber * 100 + (c - 'A' + 10);
            pos++;
        } else {
            valid = 0; 
        }
    }
    if (characterConvertedToNumber % 97 == 1) {
        std::cout << input << " is Valid.";  
    } else {
        std::cout << input << " is Invalid.";
    }

    return 0;
}
