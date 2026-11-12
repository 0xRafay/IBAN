#include <algorithm>
#include <iostream>
#include <string>
int main() {

    std::string input;

    std::cout << "Enter IBAN: ";
    std::getline(std::cin, input);

    input.erase(std::remove(input.begin(), input.end(), ' '), input.end());

    std::rotate(input.begin(), input.begin() + 4, input.end());

    std::cout << input;

    return 0;
}
