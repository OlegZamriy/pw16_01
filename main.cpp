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

    intList.InsertAtPosition(4, 1);
    std::cout << "After inserting at position 1: ";
    intList.Show();

    intList.DeleteAtPosition(2);
    std::cout << "After deleting at position 2: ";
    intList.Show();

    int searchResult = intList.Search(2);
    if (searchResult != -1) {
        std::cout << "Element 2 found at position " << searchResult << std::endl;
    }
    else {
        std::cout << "Element 2 not found." << std::endl;
    }

    int replaceCount = intList.Replace(1, 5);
    if (replaceCount != -1) {
        std::cout << "Replaced " << replaceCount << " occurrences of 1 with 5." << std::endl;
        std::cout << "After replacement: ";
        intList.Show();
    }
    else {
        std::cout << "Element 1 not found for replacement." << std::endl;
    }

    intList.Reverse();
    std::cout << "After reversing the list: ";
    intList.Show();

    return 0;
}
