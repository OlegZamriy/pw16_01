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

template class LinkedList<int>;
