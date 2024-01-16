#include "LinkedList.h"

int main() {
    LinkedList<int> intList;

    intList.AddToTail(1);
    intList.AddToTail(2);
    intList.AddToHead(0);
    intList.AddToTail(3);

    std::cout << "Original List: ";
    intList.Show();

    intList.DeleteFromHead();
    std::cout << "After deleting from head: ";
    intList.Show();

    intList.DeleteFromTail();
    std::cout << "After deleting from tail: ";
    intList.Show();

    intList.DeleteAll();
    std::cout << "After deleting all: ";
    intList.Show();

    return 0;
}
