#pragma once
#include "container.h"
#include <exception>

/**
 * @brief Doubly linked list class
 * @tparam T Datatype of stored data
*/
template <typename T>
class LinkedList : public Container<T> {                // Doubly linked list class
public:
    /**
    * \brief Default constructor for the LinkedList class.
    * Initializes an empty list with head pointing to nullptr and size set to 0.
    */
    LinkedList();                                       // Defines default constructor

    /**
     * @brief Constructor of copying other object
     * @param other other object of class LinkedList
    */
    LinkedList(const LinkedList<T>& other);             // Defines copy constuctor

    /**
     * @brief Copy constructor. Copying data from vector typed data.
     * @param other Vector with the same typed T.
    */
    LinkedList(std::vector<T> other);            // Defines copy constuctor from vector typed data

    /**
     * @brief Assignment operator for the LinkedList class.
     * @tparam T Data type stored in the LinkedList.
     * @return Reference to the current object (*this) after assignment.
    */
    LinkedList operator=(const LinkedList<T>& other);   // Defines copy operator

    /**
    * \brief Destructor for the List class.
    * Cleans up all nodes in the list to free memory.
    */
    ~LinkedList();                                      // Defines destructor

    /**
    * \brief Retrieves data from the head node.
    * \return Data of type T stored in the head node.
    */
    T GetData();                                        // Implements getting data

    /**
    * \brief Adds a new node with specified data at a given index.
    * \param index Position at which the new node is to be inserted.
    * \param data The data of type T to be stored in the new node.
    */
    void Add(int index, const T& data) override;        // Implements adding at index

    /**
    * \brief Removes a node at the specified index from the list.
    * \param index Index of the element to be removed.
    */
    void Remove(int index) override;                    // Implements removing at index

    /**
    * \brief Returns the number of nodes currently in the list.
    * \return Integer representing the number of nodes in the list.
    */
    int Size() override;                                // Implements getting list size

    /**
    * \brief Retrieves data from the node at a specified index.
    * \param index Position of the node to retrieve data from.
    * \return Data of type T stored in the node at the specified index.
    */
    T GetAt(int index) override;                        // Implements getting data at index

    /**
    * \brief Returns the number of nodes currently in the list.
    * \param index Position of the node to retrieve data from.
    * \return Data of type T stored in the node at the specified index.
    */
    T operator[](int index);                            // Implements operator getting data at index

private:

    struct Node {                                       // Defines node structure
        T data;                                         // Stores node data
        Node* next;                                     // Points to the next node
        Node* prev;                                     // Points to the previous node
    };

    Node* head;                                         // Points to the first node
    Node* tail;                                         // Points to the last node
    int size;                                           // Tracks number of nodes in the list
};

#include "linkedlist_impl.h"
