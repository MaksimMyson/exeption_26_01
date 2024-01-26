#include "Stack.h"
#include <iostream>

int main() {
    Stack<int, 5> intStack;
    intStack.push(1);
    intStack.push(2);
    intStack.push(3);

    std::cout << intStack << std::endl;

    while (!intStack.isEmpty()) {
        try {
            std::cout << "Popped element: " << intStack.pop() << std::endl;
        }
        catch (const EmptyStackException& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    Stack<double, 3> doubleStack;
    doubleStack.push(1.5);
    doubleStack.push(2.5);

    std::cout << doubleStack << std::endl;

    return 0;
}
