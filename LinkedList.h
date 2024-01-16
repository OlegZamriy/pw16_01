#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T val) : data(val), next(nullptr) {}
};

template <typename T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    LinkedList();
    ~LinkedList();

    void AddToHead(T val);
    void AddToTail(T val);
    void DeleteFromHead();
    void DeleteFromTail();
    void DeleteAll();
    void Show();

    void InsertAtPosition(T val, int position);
    void DeleteAtPosition(int position);
    int Search(T val);
    int Replace(T oldVal, T newVal);
    void Reverse();
};

#endif  // LINKEDLIST_H
