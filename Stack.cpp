#include<iostream>
#include "Stack.h"

template <typename T>
Stack<T>::Stack() : top(nullptr) {}

template <typename T>
Stack<T>::~Stack() {
    while (!isEmpty()) {
        pop();
    }
}

template <typename T>
void Stack<T>::push(T val) {
    StackNode<T>* newNode = new StackNode<T>(val);
    newNode->next = top;
    top = newNode;
}

template <typename T>
T Stack<T>::pop() {
    if (isEmpty()) {
        throw std::out_of_range("Stack is empty");
    }

    T poppedValue = top->data;
    StackNode<T>* temp = top;
    top = top->next;
    delete temp;

    return poppedValue;
}

template <typename T>
bool Stack<T>::isEmpty() const {
    return top == nullptr;
}

template <typename T>
StackNode<T>* Stack<T>::clone() const {
    Stack<T> clonedStack;
    StackNode<T>* current = top;

    while (current != nullptr) {
        clonedStack.push(current->data);
        current = current->next;
    }

    return clonedStack.top;
}

template <typename T>
StackNode<T>* Stack<T>::concatenate(const Stack<T>& other) const {
    Stack<T> resultStack = *this;
    StackNode<T>* current = other.top;

    while (current != nullptr) {
        resultStack.push(current->data);
        current = current->next;
    }

    return resultStack.top;
}

template <typename T>
StackNode<T>* Stack<T>::intersection(const Stack<T>& other) const {
    Stack<T> resultStack;
    StackNode<T>* current = top;

    while (current != nullptr) {
        if (other.contains(current->data)) {
            resultStack.push(current->data);
        }
        current = current->next;
    }

    return resultStack.top;
}

template <typename T>
bool Stack<T>::contains(T val) const {
    StackNode<T>* current = top;

    while (current != nullptr) {
        if (current->data == val) {
            return true;
        }
        current = current->next;
    }

    return false;
}

template class Stack<int>;
template class Stack<double>;
