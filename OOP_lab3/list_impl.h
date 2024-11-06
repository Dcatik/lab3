#pragma once
#include "list.h"
#include <iostream>

template <typename T>
List<T>::List() : head(nullptr), size(0) {          // Constructor initializes head to nullptr and size to 0
}

template <typename T>
List<T>::List(const List<T>& other) : head(nullptr), size(0) {
    Node* current = other.head;
    while (current) {
        Add(size, current->data); 
        current = current->next;
    }
}

template <typename T>
List<T>::~List() {
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;             // Save next node
        delete current;                             // Delete current node
        current = nextNode;                         // Move to next node
    }
}

template <typename T>
List<T>::List(std::vector<T> other) : head(nullptr), size(0) {
    if (other.empty()) {
        return;
    }

    for (const T& item : other) {
        this->Add(size, item);
    }
}

template <typename T>
void List<T>::Add(int index, const T& data) {
    if (index < 0 || index > size) {                // Check if index is within bounds
        throw std::out_of_range("Index out of bounds");
    }
    Node* newNode = new Node{ data, nullptr };      // Create new node with given data

    if (index == 0) {                               // Insert at head
        newNode->next = head;
        head = newNode;
    }
    else {
        Node* current = head;
        for (int i = 0; i < index - 1; ++i) {       // Traverse to the node before index
            current = current->next;
        }
        newNode->next = current->next;              // Link new node to the next node
        current->next = newNode;                    // Link previous node to new node
    }
    ++size;                                         // Increment size of the list
}

template <typename T>
void List<T>::Remove(int index) {
    if (index < 0 || index >= size) {               // Check if index is within bounds
        throw std::out_of_range("Index out of bounds");
    }
    Node* toDelete;
    if (index == 0) {                               // Remove head node
        toDelete = head;
        head = head->next;
    }
    else {
        Node* current = head;
        for (int i = 0; i < index - 1; ++i) {       // Traverse to the node before index
            current = current->next;
        }
        toDelete = current->next;                   // Node to delete
        current->next = toDelete->next;             // Bypass the node to delete
    }
    delete toDelete;                                // Delete node
    --size;                                         // Decrement size of the list
}

template <typename T>
T List<T>::GetAt(int index) {
    if (index < 0 || index >= size) {               // Check if index is within bounds
        throw std::out_of_range("Index out of bounds");
    }
    Node* current = head;
    for (int i = 0; i < index; ++i) {               // Traverse to the desired index
        current = current->next;
    }
    return current->data;                           // Return data at index
}

template <typename T>
T List<T>::GetData() {
    if (head == nullptr) {                          // Check if list is empty
        throw std::runtime_error("List is empty");
    }
    return head->data;                              // Return data at head
}

template <typename T>
int List<T>::Size() {
    return size;                                    // Return size of the list
}

template <typename T>
T List<T>::operator[](int index) {
    return this->GetAt(index);
}