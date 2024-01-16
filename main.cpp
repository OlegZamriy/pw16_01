#include <iostream>
#include "Stack.h"

int main() {
    Stack<int> intStack;
    intStack.push(10);
    intStack.push(20);
    intStack.push(30);

    while (!intStack.isEmpty()) {
        std::cout << intStack.pop() << " ";
    }

    return 0;
}
