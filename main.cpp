#include <iostream>
#include "calculator.h"

using namespace std;

int main() {
    try {
        string input;
        cout << "Enter the character string: ";
        cin >> input;

        int result = calculateDecimalValue(input);
        cout << "Result: " << result << endl;
    }
    catch (const out_of_range& e) {
        cerr << "Error: " << e.what() << endl;
    }
    catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
    }
    catch (...) {
        cerr << "Unknown error" << endl;
    }

    return 0;
}
                