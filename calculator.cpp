#include "calculator.h"
#include <cmath>
#include <stdexcept>

using namespace std;

int calculateDecimalValue(const string& input) {
    // Check for presence of characters in the string
    if (input.empty()) {
        throw invalid_argument("Empty string");
    }

    // Initialize variable to store the result
    int result = 0;

    // Check for negative number
    int sign = 1;
    size_t startIndex = 0;
    if (input[0] == '-') {
        sign = -1;
        startIndex = 1;
    }

    // Calculate decimal value
    for (size_t i = startIndex; i < input.size(); ++i) {
        char digit = input[i];
        if (isdigit(digit)) {
            result = result * 10 + (digit - '0');

            // Check for overflow of int range
            if (result < 0) {
                throw out_of_range("Value goes beyond the int range");
            }
        }
        else {
            throw invalid_argument("String contains invalid characters");
        }
    }

    return result * sign;
}
