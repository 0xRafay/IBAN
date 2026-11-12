#include <cstddef>
#include <iostream>
#include <string>
int main() {

    std::string input;

    std::cout << "Enter IBAN: ";
    std::cin >> input;

    int sizeOfInput = input.length();

    std::cout << sizeOfInput;

    size_t pos = 0;

    while (pos < sizeOfInput) {

        char c = input[pos];

        if (c == ' ' || c == '\n' || c == '\t' || c == '-') {
            pos++;
            // idea: can detect where the dash is supposd to be
            // idea: skips on '-' when its in a valid position
            // not implemented rn, btw
        }

        if (c >= '0' && c <= '9') {
            long value = 0;
            value = value * 10 + (input[pos] - '0');

            pos++;
        }
        // just moves on and doesnt care about 
        // other cases or errors
        pos++;
    }

    return 0;
}
