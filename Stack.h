#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <stdexcept>

// Клас винятка для переповнення стеку
class StackOverflowException : public std::overflow_error {
public:
    StackOverflowException(const std::string& message = "Stack overflow")
        : std::overflow_error(message) {}
};

// Клас винятка для спроби взяти елемент з пустого стеку
class EmptyStackException : public std::underflow_error {
public:
    EmptyStackException(const std::string& message = "Cannot pop from an empty stack")
        : std::underflow_error(message) {}
};

template <typename T, int MAX_SIZE>
class Stack {
private:
    T stack[MAX_SIZE];
    int top;

public:
    Stack() : top(-1) {}

    bool isEmpty() const {
        return top == -1;
    }

    bool isFull() const {
        return top == MAX_SIZE - 1;
    }

    void push(const T& value) {
        if (isFull()) {
            throw StackOverflowException();
        }
        stack[++top] = value;
    }

    T pop() {
        if (isEmpty()) {
            throw EmptyStackException();
        }
        return stack[top--];
    }

    int size() const {
        return top + 1;
    }

    void clear() {
        top = -1;
    }

    T topElement() const {
        if (isEmpty()) {
            throw EmptyStackException();
        }
        return stack[top];
    }

    int getTop() const {
        return top;
    }

    const T* getStack() const {
        return stack;
    }
};

template <typename T, int MAX_SIZE>
std::ostream& operator<<(std::ostream& os, const Stack<T, MAX_SIZE>& stack) {
    os << "Stack content: ";
    for (int i = stack.getTop(); i >= 0; --i) {
        os << stack.getStack()[i] << " ";
    }
    return os;
}

#endif // STACK_H

