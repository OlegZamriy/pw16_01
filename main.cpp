#include <iostream>
#include "Stack.h"

int main() {
    Stack<int> stack1;
    stack1.push(10);
    stack1.push(20);
    stack1.push(30);

    Stack<int> stack2;
    stack2.push(20);
    stack2.push(30);
    stack2.push(40);

    StackNode<int>* clonedStack = stack1.clone();
    StackNode<int>* concatenatedStack = stack1.concatenate(stack2);
    StackNode<int>* intersectedStack = stack1.intersection(stack2);

    std::cout << "Cloned Stack: ";
    while (clonedStack != nullptr) {
        std::cout << clonedStack->data << " ";
        clonedStack = clonedStack->next;
    }

    std::cout << "\nConcatenated Stack: ";
    while (concatenatedStack != nullptr) {
        std::cout << concatenatedStack->data << " ";
        concatenatedStack = concatenatedStack->next;
    }

    std::cout << "\nIntersected Stack: ";
    while (intersectedStack != nullptr) {
        std::cout << intersectedStack->data << " ";
        intersectedStack = intersectedStack->next;
    }

    return 0;
}
