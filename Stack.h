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

    StackNode<T>* clone() const;
    StackNode<T>* concatenate(const Stack<T>& other) const;
    StackNode<T>* intersection(const Stack<T>& other) const;
    bool contains(T val) const;
};

#endif // STACK_H

