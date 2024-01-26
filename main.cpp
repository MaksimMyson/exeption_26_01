#include <iostream>
#include <cmath>
#include "custom_exceptions.h"

int main() {
    try {
        // Спроба ділення на нуль
        int a = 10, b = 0;
        if (b == 0) {
            throw DivisionByZeroException();
        }
        int result = a / b;
        std::cout << "Result: " << result << std::endl;
    }
    catch (const DivisionByZeroException& e) {
        std::cerr << "Math Error: " << e.what() << std::endl;
    }

    try {
        // Спроба взяття кореня від від'ємного числа
        double x = -5;
        if (x < 0) {
            throw NegativeRootException();
        }
        double result = sqrt(x);
        std::cout << "Result: " << result << std::endl;
    }
    catch (const NegativeRootException& e) {
        std::cerr << "Math Error: " << e.what() << std::endl;
    }

    try {
        // Спроба виділення пам'яті недостатньої кількості
        int* arr = new(std::nothrow) int[100000000];  // тут тепер використовується nothrow
        if (!arr) {
            throw MemoryException();
        }
        delete[] arr;
    }
    catch (const MemoryException& e) {
        std::cerr << "Memory Error: " << e.what() << std::endl;
    }

    return 0;
}
