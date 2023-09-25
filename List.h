/***********************************************************************
*** NAME : Kaylee Tringali                                           ***
*** CLASS : CSC300                                                   ***
*** ASSIGNMENT : 1                                                   ***
*** DUE DATE : 9/25/23                                               ***
*** INSTRUCTOR : GAMRADT                                             ***
************************************************************************
*** DESCRIPTION : This ADT represents a sorted linked list where     ***
*** elements are stored in ascending order. Supporting operations    ***
*** include adding elements while maintaining the sorted order,      ***
*** removing specified elements, and viewing contents of the list.   ***
************************************************************************/

#ifndef _LIST_H
#define _LIST_H

using Element = float;

class List {
public:

/********************************************************************
*** FUNCTION List()                                               ***
*********************************************************************
*** DESCRIPTION :  Constructor for List class. Initializes front  ***
**  pointer to nullptr.                                           ***
*** INPUT ARGS : None                                             ***
*** OUTPUT ARGS : None                                            ***
*** IN/OUT ARGS : None                                            ***
*** RETURN : None                                                 ***
********************************************************************/
    
    List();

/********************************************************************
*** FUNCTION List(const List &)                                   ***
*********************************************************************
*** DESCRIPTION : Copy constructor for List class. Creates a new  ***
**  list w/ elements copied from input list.                      ***
*** INPUT ARGS : other - List to copy elements from               ***
*** OUTPUT ARGS : None                                            ***
*** IN/OUT ARGS : None                                            ***
*** RETURN : None                                                 ***
********************************************************************/

    List(const List &);

/********************************************************************
*** FUNCTION ~List()                                              ***
*********************************************************************
*** DESCRIPTION : Destructor for List class. Deletes all of the   ***
**  dynamically allocated nodes in list.                          ***
*** INPUT ARGS : None                                             ***
*** OUTPUT ARGS : None                                            ***
*** IN/OUT ARGS : None                                            ***
*** RETURN : None                                                 ***
********************************************************************/

    ~List();

/**********************************************************************
*** FUNCTION void add()                                             ***
***********************************************************************
*** DESCRIPTION : Adds a new element to the list in a sorted order. ***
*** INPUT ARGS : Element                                            ***
*** OUTPUT ARGS : None                                              ***
*** IN/OUT ARGS : None                                              ***
*** RETURN : void                                                   ***
***********************************************************************/
    
    void add(const Element);

/**********************************************************************
*** FUNCTION void remove()                                          ***
***********************************************************************
*** DESCRIPTION : Removes a specified element from the list.        ***
*** INPUT ARGS : Element                                            ***
*** OUTPUT ARGS : None                                              ***
*** IN/OUT ARGS : None                                              ***
*** RETURN : void                                                   ***
***********************************************************************/

    void remove(const Element);

/**********************************************************************
*** FUNCTION void view()                                            ***
***********************************************************************
*** DESCRIPTION : Displays contents of the list.                    ***
*** INPUT ARGS : None                                               ***
*** OUTPUT ARGS : None                                              ***
*** IN/OUT ARGS : None                                              ***
*** RETURN : void                                                   ***
***********************************************************************/
    
    void view() const;

private: // non-exportable so no documentation needed past here
    struct Node;
    using NodePtr = Node *;

    struct Node {
        Element element;
        NodePtr next;
    };

    NodePtr front;
};

#endif
