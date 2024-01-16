#include "LinkedList.h"

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr) {}

template <typename T>
LinkedList<T>::~LinkedList() {
    DeleteAll();
}

template <typename T>
void LinkedList<T>::AddToHead(T val) {
    Node<T>* newNode = new Node<T>(val);
    if (!head) {
        head = tail = newNode;
    }
    else {
        newNode->next = head;
        head = newNode;
    }
}

template <typename T>
void LinkedList<T>::AddToTail(T val) {
    Node<T>* newNode = new Node<T>(val);
    if (!head) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
}

template <typename T>
void LinkedList<T>::DeleteFromHead() {
    if (head) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
}

template <typename T>
void LinkedList<T>::DeleteFromTail() {
    if (head) {
        if (head == tail) {
            delete head;
            head = tail = nullptr;
        }
        else {
            Node<T>* temp = head;
            while (temp->next != tail) {
                temp = temp->next;
            }
            delete tail;
            tail = temp;
            tail->next = nullptr;
        }
    }
}

template <typename T>
void LinkedList<T>::DeleteAll() {
    while (head) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
}

template <typename T>
void LinkedList<T>::Show() {
    Node<T>* current = head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

template <typename T>
void LinkedList<T>::InsertAtPosition(T val, int position) {
    if (position < 0) return;

    Node<T>* newNode = new Node<T>(val);

    if (position == 0) {
        newNode->next = head;
        head = newNode;
        if (!tail) {
            tail = head;
        }
    }
    else {
        Node<T>* current = head;
        for (int i = 0; i < position - 1 && current; ++i) {
            current = current->next;
        }

        if (current) {
            newNode->next = current->next;
            current->next = newNode;

            if (!newNode->next) {
                tail = newNode;
            }
        }
    }
}

template <typename T>
void LinkedList<T>::DeleteAtPosition(int position) {
    if (position < 0 || !head) return;

    if (position == 0) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;

        if (!head) {
            tail = nullptr;
        }
    }
    else {
        Node<T>* current = head;
        for (int i = 0; i < position - 1 && current->next; ++i) {
            current = current->next;
        }

        if (current && current->next) {
            Node<T>* temp = current->next;
            current->next = current->next->next;
            delete temp;

            if (!current->next) {
                tail = current;
            }
        }
    }
}

template <typename T>
int LinkedList<T>::Search(T val) {
    int position = 0;
    Node<T>* current = head;

    while (current) {
        if (current->data == val) {
            return position;
        }
        current = current->next;
        ++position;
    }

    return -1;
}

template <typename T>
int LinkedList<T>::Replace(T oldVal, T newVal) {
    int count = 0;
    Node<T>* current = head;

    while (current) {
        if (current->data == oldVal) {
            current->data = newVal;
            ++count;
        }
        current = current->next;
    }

    if (count > 0) {
        return count;
    }
    else {
        return -1;
    }
}

template <typename T>
void LinkedList<T>::Reverse() {
    Node<T>* prev = nullptr;
    Node<T>* current = head;
    Node<T>* next = nullptr;

    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
}

template class LinkedList<int>;
