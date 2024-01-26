#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <iostream>
#include <stdexcept>

template <typename T>
class Node {
public:
    T data;
    Node<T>* next;
    Node<T>* prev;

    Node(const T& value) : data(value), next(nullptr), prev(nullptr) {}
};

class EmptyListException : public std::logic_error {
public:
    EmptyListException(const std::string& message = "List is empty") : std::logic_error(message) {}
};

class MemoryAllocationException : public std::exception {
private:
    std::string errorMessage;

public:
    MemoryAllocationException(const std::string& message = "Memory allocation failed") : errorMessage(message) {}

    const char* what() const noexcept override {
        return errorMessage.c_str();
    }
};

template <typename T>
class DoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void AddToHead(const T& value);
    void AddToTail(const T& value);
    void DeleteFromHead();
    void DeleteFromTail();
    void DeleteAll();
    void Show() const;
};

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr) {}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    DeleteAll();
}

template <typename T>
void DoublyLinkedList<T>::AddToHead(const T& value) {
    Node<T>* newNode = new(std::nothrow) Node<T>(value);
    if (!newNode) {
        throw MemoryAllocationException();
    }

    if (!head) {
        head = tail = newNode;
    }
    else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

template <typename T>
void DoublyLinkedList<T>::AddToTail(const T& value) {
    Node<T>* newNode = new(std::nothrow) Node<T>(value);
    if (!newNode) {
        throw MemoryAllocationException();
    }

    if (!tail) {
        head = tail = newNode;
    }
    else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

template <typename T>
void DoublyLinkedList<T>::DeleteFromHead() {
    if (!head) {
        throw EmptyListException();
    }

    Node<T>* temp = head;
    head = head->next;

    if (!head) {
        tail = nullptr;
    }
    else {
        head->prev = nullptr;
    }

    delete temp;
}

template <typename T>
void DoublyLinkedList<T>::DeleteFromTail() {
    if (!tail) {
        throw EmptyListException();
    }

    Node<T>* temp = tail;
    tail = tail->prev;

    if (!tail) {
        head = nullptr;
    }
    else {
        tail->next = nullptr;
    }

    delete temp;
}

template <typename T>
void DoublyLinkedList<T>::DeleteAll() {
    while (head) {
        DeleteFromHead();
    }
}

template <typename T>
void DoublyLinkedList<T>::Show() const {
    Node<T>* current = head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

#endif
