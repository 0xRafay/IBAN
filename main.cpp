#include <algorithm>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/fwd.hpp>
#include <cctype>
#include <iostream>
#include <string>

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

    cpp_int accumulatedNumbers = 0;

    while (pos < inputLength) {

        char c = input[pos];

        if (c >= '0' && c <= '9') {
            accumulatedNumbers =
                accumulatedNumbers * 10 + (c - '0');
            pos++;
        } else if (c >= 'A' && c <= 'Z') {
            accumulatedNumbers =
                accumulatedNumbers * 100 + (c - 'A' + 10);
            pos++;
        } else {
            std::cout << "Error occured while parsing";
            return 0;
        }
    }
    if (accumulatedNumbers % 97 == 1) {
        std::cout << input << " is Valid.";
    } else {
        std::cout << input << " is Invalid.";
    }

    return 0;
}
