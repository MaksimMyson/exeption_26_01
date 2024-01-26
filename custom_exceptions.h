#ifndef CUSTOM_EXCEPTIONS_H
#define CUSTOM_EXCEPTIONS_H

#include <stdexcept>

// ������� ���� ��� ������������ �������
class MathException : public std::runtime_error {
public:
    MathException(const std::string& message) : std::runtime_error(message) {}
};

// ���� ��� ������� ������ �� ����
class DivisionByZeroException : public MathException {
public:
    DivisionByZeroException() : MathException("Division by zero") {}
};

// ���� ��� ������� ������ �� ��'������ �����
class NegativeRootException : public MathException {
public:
    NegativeRootException() : MathException("Square root of a negative number") {}
};

// ���� ��� ������� �� ���'����
class MemoryException : public std::bad_alloc {
public:
    MemoryException() : std::bad_alloc() {}
};

// ���� ��� ������� �� ��� ������ � �������
class FileException : public std::runtime_error {
public:
    FileException(const std::string& message) : std::runtime_error(message) {}
};

// ���� ��� ������� ������� ������� �����
class ReadFileException : public FileException {
public:
    ReadFileException() : FileException("Error reading file") {}
};

// ���� ��� ������� ������� ������ �����
class WriteFileException : public FileException {
public:
    WriteFileException() : FileException("Error writing to file") {}
};

#endif // CUSTOM_EXCEPTIONS_H
