#ifndef CUSTOM_EXCEPTIONS_H
#define CUSTOM_EXCEPTIONS_H

#include <stdexcept>

// Базовий клас для математичних помилок
class MathException : public std::runtime_error {
public:
    MathException(const std::string& message) : std::runtime_error(message) {}
};

// Клас для обробки ділення на нуль
class DivisionByZeroException : public MathException {
public:
    DivisionByZeroException() : MathException("Division by zero") {}
};

// Клас для обробки кореня від від'ємного числа
class NegativeRootException : public MathException {
public:
    NegativeRootException() : MathException("Square root of a negative number") {}
};

// Клас для проблем із пам'яттю
class MemoryException : public std::bad_alloc {
public:
    MemoryException() : std::bad_alloc() {}
};

// Клас для проблем під час роботи з файлами
class FileException : public std::runtime_error {
public:
    FileException(const std::string& message) : std::runtime_error(message) {}
};

// Клас для обробки помилки читання файлу
class ReadFileException : public FileException {
public:
    ReadFileException() : FileException("Error reading file") {}
};

// Клас для обробки помилки запису файлу
class WriteFileException : public FileException {
public:
    WriteFileException() : FileException("Error writing to file") {}
};

#endif // CUSTOM_EXCEPTIONS_H
