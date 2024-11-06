#pragma once
#include "linkedlist.h"

template <typename T>
LinkedList<T>::LinkedList() : head(nullptr), tail(nullptr), size(0) {   // Constructor initializes head, tail, and size
}

template <typename T>
LinkedList<T>::~LinkedList(){
    Node* current = head;
    while (current != nullptr) {
        Node* nextNode = current->next;                                 // Save next node
        delete current;                                                 // Delete current node
        current = nextNode;                                             // Move to the next node
    }
}

                                                                        // Copy constructor
template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& other) : head(nullptr), tail(nullptr), size(0) {
    Node* current = other.head;
    while (current) {
        Add(size, current->data); 
        current = current->next;
    }
}

template <typename T>
LinkedList<T>::LinkedList(std::vector<T> other) : head(nullptr), tail(nullptr), size(0) {
    if (other.empty()) {
        return;
    }

    for (const T& item : other) {
        this->Add(size, item);
    }
}
                                                                        // Assignment operator
template <typename T>
LinkedList<T> LinkedList<T>::operator=(const LinkedList<T>& other) {
    if (this == &other) {
        return *this; 
    }

    while (head) {
        Remove(0);
    }

    Node* current = other.head;
    while (current) {
        Add(size, current->data);
        current = current->next;
    }

    return *this;
}


template <typename T>
void LinkedList<T>::Add(int index, const T& data) {
    if (index < 0 || index > size) {                                    // Check index bounds
        throw std::out_of_range("Index out of bounds");
    }
    Node* newNode = new Node{ data, nullptr, nullptr };                 // Create new node

    if (index == 0) {                                                   // Insert at head
        newNode->next = head;
        if (head) head->prev = newNode;
        head = newNode;
        if (size == 0) tail = head;                                     // Update tail if list was empty
    }
    else if (index == size) {                                           // Insert at tail
        if (tail) {
            newNode->prev = tail;
            tail->next = newNode;
        }
        else {
            head = newNode;
        }
        tail = newNode;
    }
    else {                                                              // Insert at middle
        Node* current = head;
        for (int i = 0; i < index - 1; i++) {                           // Traverse to node before index
            current = current->next;
        }
        newNode->next = current->next;
        newNode->prev = current;
        current->next->prev = newNode;
        current->next = newNode;
    }
    ++size;                                                             // Increment size
}

template <typename T>
void LinkedList<T>::Remove(int index) {
    if (index < 0 || index >= size) {                                   // Check index bounds
        throw std::out_of_range("Index out of bounds");
    }
    Node* toDelete;
    if (index == 0) {                                                   // Remove head
        toDelete = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;                                            // List becomes empty
    }
    else if (index == size - 1) {                                       // Remove tail
        toDelete = tail;
        tail = tail->prev;
        if (tail) {
            tail->next = nullptr;
        }
        else {
            head = nullptr;
        }
    }
    else {                                                              // Remove from middle
        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        toDelete = current;
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }
    delete toDelete;                                 
    size = size - 1;                                             
}

template <typename T>
T LinkedList<T>::GetAt(int index) {
    if (index < 0 || index >= size) {                                   // Check index bounds
        throw std::out_of_range("Index out of bounds");
    }
    Node* current = head;
    for (int i = 0; i < index; ++i) {                                   // Traverse to the specified index
        current = current->next;
    }
    return current->data;                                               // Return data at index
}

template <typename T>
T LinkedList<T>::GetData() {
    if (head == nullptr) {                                              // Check if list is empty
        throw std::runtime_error("List is empty");
    }
    return head->data;                                                  // Return data at head
}

template <typename T>
int LinkedList<T>::Size() {
    return size;                                                        // Return list size
}

template <typename T>
T LinkedList<T>::operator[](int index) {
    return this->GetAt(index);
}
