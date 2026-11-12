#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
int main() {

    std::string input;

    std::cout << "Enter IBAN: ";
    std::getline(std::cin, input);

    size_t inputLength = input.length();

    input.erase(std::remove(input.begin(), input.end(), ' '), input.end());

    std::transform(input.begin(), input.end(), input.begin(),
                   [](unsigned char c) { return std::toupper(c); });

    if (inputLength > 4) {
        std::rotate(input.begin(), input.begin() + 4, input.end());
    }

    std::cout << input;

    return 0;
}
