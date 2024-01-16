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

template class Stack<int>;
template class Stack<double>;
