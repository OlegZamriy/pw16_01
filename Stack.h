#ifndef STACK_H
#define STACK_H

template <typename T>
class StackNode {
public:
    T data;
    StackNode* next;

    StackNode(T val) : data(val), next(nullptr) {}
};

template <typename T>
class Stack {
private:
    StackNode<T>* top;

public:
    Stack();
    ~Stack();

    void push(T val);
    T pop();
    bool isEmpty() const;
};

#endif // STACK_H
