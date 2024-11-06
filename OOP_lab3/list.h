#pragma once
#include <vector>
#include "container.h"

/**
 * @brief Singly linked list class
 * @tparam T Datatype of stored data
*/
template <typename T>
class List : public Container<T> {                  // Singly linked list class
public:
    /**
    * \brief Default constructor for the List class.
    * Initializes an empty list with head pointing to nullptr and size set to 0.
    */
    List();                                         // Defines default constructor

    /**
    * \brief Destructor for the List class.
    * Cleans up all nodes in the list.
    */
    ~List();                                        // Defines destructor

    /**
    * @brief Copy constructor for the List class.
    *
    * @tparam T Data type stored in the list.
    * @param other Constant reference to the source list to copy.
    */
    List(const List<T>& other);                     // Defines copy constructor

    /**
     * @brief Copy constructor. Copying data from vector typed data.
     * @param other Vector with the same typed T.
    */
    List(std::vector<T> other);                     // Defines copy constuctor from the vector type

    /**
    * @brief Assignment operator for the List class.
    * 
    * @tparam T Data type stored in the list.
    * @param other Constant reference to the list whose elements are to be copied.
    * @return Reference to the current object (*this) after assignment.
    */
    List operator=(const List<T>& other);           // Defines copy operator

    /**
    * \brief Adds a new node with specified data at a given index.
    * \param index Position at which the new node is to be inserted.
    * \param data The data of type T to be stored in the new node.
    */
    void Add(int index, const T& data);             // Implements adding

    /**
    * \brief Removes a node at the specified index from the list.
    * \param index Index of the element to be removed.
    */
    void Remove(int index);                         // Implements removing

    /**
    * \brief Returns the number of nodes currently in the list.
    * \return Integer representing the number of nodes in the list.
    */
    int Size();                                     // Implements getting size

    /**
    * \brief Retrieves data from the node at a specified index.
    * \param index Position of the node to retrieve data from.
    * \return Data of type T stored in the node at the specified index.
    */
    T GetAt(int index);                             // Implements getting data at index
    
    /**
    * \brief Returns the number of nodes currently in the list.
    * \param index Position of the node to retrieve data from.
    * \return Data of type T stored in the node at the specified index.
    */
    T operator[](int index);                        // Implements operator getting data at index

    /**
    * \brief Retrieves data from the head node.
    * \return Data of type T stored in the head node.
    */
    T GetData();                                    // Implements getting data

private:
    struct Node {                                   // Defines node structure
        T data;                                     // Stores data in the node
        Node* next;                                 // Points to the next node
    };

    Node* head;                                     // Points to the head node of the list
    int size;                                       // Tracks the number of nodes in the list
};

#include "list_impl.h"