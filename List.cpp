/**********************************************************************
*** NAME : Kaylee Tringali                                          ***
*** CLASS : CSC300                                                  ***
*** ASSIGNMENT : 1                                                  ***
*** DUE DATE : 9/25/23                                              ***
*** INSTRUCTOR : GAMRADT                                            ***
***********************************************************************
*** DESCRIPTION : This file contains the implementation of the List ***
*** ADT. The List ADT is a sorted linked list where elements are    ***
*** stored in ascending order. The supported operations include     ***
*** adding elements while maintaining the sorted order, removing    ***
specified elements, and viewing the contents of the list.           ***
***********************************************************************/

#include "List.h"
#include <iostream>

using namespace std;

/********************************************************************
*** FUNCTION List::List()                                         ***
*********************************************************************
*** DESCRIPTION : Constructor for List class. Initializes front   ***
*** pointer to nullptr.                                           ***
*** INPUT ARGS : None                                             ***
*** OUTPUT ARGS : None                                            ***
*** IN/OUT ARGS : None                                            ***
*** RETURN : None                                                 ***
********************************************************************/

List::List() : front(nullptr) {}

/********************************************************************
*** FUNCTION List::List(const List &)                             ***
*********************************************************************
*** DESCRIPTION : Copy constructor for List class. Creates a new  ***
*** list with elements copied from the input list.                ***
*** INPUT ARGS : List to copy elements from                       ***
*** OUTPUT ARGS : None                                            ***
*** IN/OUT ARGS : None                                            ***
*** RETURN : None                                                 ***
********************************************************************/

List::List(const List &other) : front(nullptr) {
    NodePtr temp = other.front;
    while (temp != nullptr) {
        add(temp->element);
        temp = temp->next;
    }
}

/********************************************************************
*** FUNCTION List::~List()                                        ***
*********************************************************************
*** DESCRIPTION : Destructor for List class. Deletes all of the   ***
*** dynamically allocated nodes in the list.                      ***
*** INPUT ARGS : None                                             ***
*** OUTPUT ARGS : None                                            ***
*** IN/OUT ARGS : None                                            ***
*** RETURN : None                                                 ***
********************************************************************/

List::~List() {
    while (front != nullptr) {
        NodePtr temp = front;
        front = front->next;
        delete temp; // deallocate memory for current node 
    }
}

/********************************************************************
*** FUNCTION void List::add(const Element value)                  ***
*********************************************************************
*** DESCRIPTION : Adds new element to the list in a sorted order. ***
*** INPUT ARGS : Element (value) to be added to the list          ***
*** OUTPUT ARGS : None                                            ***
*** IN/OUT ARGS : None                                            ***
*** RETURN : void                                                 ***
********************************************************************/

void List::add(const Element value) {
    NodePtr newNode = new Node;
    newNode->element = value;
    newNode->next = nullptr;

    if (front == nullptr || value >= front->element) {
        // adding at front or when list is empty
        newNode->next = front;
        front = newNode;
    } else {
        NodePtr current = front;
        while (current->next != nullptr && current->next->element > value) {
            // traverse the list to find the correct position to add node
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

/********************************************************************
*** FUNCTION void List::remove(const Element value)               ***
*********************************************************************
*** DESCRIPTION : Removes a specified element from the list.      ***
*** INPUT ARGS : value - Element to be removed from the list      ***
*** OUTPUT ARGS : None                                            ***
*** IN/OUT ARGS : None                                            ***
*** RETURN : void                                                 ***
********************************************************************/

void List::remove(const Element value) {
    if (front == nullptr)
        return; // nothing to remove if list is empty

    NodePtr temp = front;

    // if value is at the front, remove 
    if (front->element == value) {
        front = front->next;
        delete temp; // deallocate memory for removed node 
        return;
    }

    NodePtr prev = nullptr;
    while (temp != nullptr && temp->element != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr)
        return; // value not found in list

    // value found, adjust links and deallocate memory
    prev->next = temp->next;
    delete temp; // deallocate memory for removed node
}

/********************************************************************
*** FUNCTION void List::view() const                              ***
*********************************************************************
*** DESCRIPTION : Displays the contents of the list.              ***
*** INPUT ARGS : None                                             ***
*** OUTPUT ARGS : None                                            ***
*** IN/OUT ARGS : None                                            ***
*** RETURN : void                                                 ***
********************************************************************/

void List::view() const {
    NodePtr current = front;
    cout << "FRONT -> ";

    while (current != nullptr) {
        cout << current->element << " -> ";
        current = current->next;
    }

    cout << "END" << endl;
}
