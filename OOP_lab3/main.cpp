#include <iostream>
#include "list.h"
#include "linkedlist.h"

int main() {
    List<int> list;

    list.Add(0, 10);
    list.Add(1, 20);
    list.Add(list.Size()-1, 30);
    list.Add(1, 15);

    std::cout << "List contents after adding elements:" << std::endl;
    for (int i = 0; i < list.Size(); ++i) {
        std::cout << "Element at index " << i << ": " << list.GetAt(i) << std::endl;
    }

    list.Remove(1);
    std::cout << "\nList contents after removing element at index 1:" << std::endl;
    for (int i = 0; i < list.Size(); ++i) {
        std::cout << "Element at index " << i << ": " << list[i] << std::endl;
    }

    std::cout << "\nData at the head of the list: " << list.GetData() << std::endl;

    std::cout << "Size of the list: " << list.Size() << std::endl;


    LinkedList<int> list1;
                                                     
    list1.Add(0, 10);                                                                  
    list1.Add(1, 20);                                                                   
    list1.Add(1, 15);                                                                  
                                                                           
    for (int i = 0; i < list1.Size(); ++i) {
        std::cout << "Element at index " << i << ": " << list1.GetAt(i) << std::endl;
    }
                                                                                   
    list1.Remove(1);                                                                    
    std::cout << "After removing index 1:" << std::endl;
    for (int i = 0; i < list1.Size(); ++i) {
        std::cout << "Element at index " << i << ": " << list1[i] << std::endl;
    }

    list1.Add(1, 123);

    std::cout<< "List at index 1 after adding a number: " << list1[1] << std::endl;

    List<int> copied_l(list);
    List<int> assign_l = list;
    std::cout << "List at index 1 of copied_l: " << copied_l[1] << std::endl;
    std::cout << "List at index 1 of _l: " << copied_l[1] << std::endl;
    std::cout << "List at index 1 of copied_l: " << copied_l[1] << std::endl;


    //------------------------------------------------------------------------------------
    std::vector<int> vect;
    for (int i = 0; i < 6; i++) {
        vect.push_back(i);
    }

    List<int> listV(vect);
    List<int> linkedlistV(vect);

    for (int i = 0; i < listV.Size(); ++i) {
        std::cout << "Element at index " << i << ": " << " of copied from vect listV = " << listV[i] << std::endl;
    }
    for (int i = 0; i < linkedlistV.Size(); ++i) {
        std::cout << "Element at index " << i << ": " << " of copied from vect linkedlistV = " << linkedlistV[i] << std::endl;
    }


    return 0;
}