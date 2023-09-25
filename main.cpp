/***********************************************************************
*** NAME : Kaylee Tringali                                           ***
*** CLASS : CSC300                                                   ***
*** ASSIGNMENT : 1                                                   ***
*** DUE DATE : 9/25/23                                               ***
*** INSTRUCTOR : GAMRADT                                             ***
************************************************************************
*** DESCRIPTION : This assignment involves creating a sorted linked  ***
*** list using C++. The program defines a 'List' class utilizing a   ***
*** linked list, implementing operations to add sorted elements and  ***
*** remove specified elements. The program displays the list content ***
*** and includes organized code across 'main.cpp', 'List.h', and     ***
*** 'List.cpp'. A provided 'Makefile' outputs successful addition/   ***
*** removal of elements.                                             ***
************************************************************************/

// File Descriptions:
// - main.cpp: Contains the main function to demonstrate the usage of the List class.
// - List.h: Header file for the List class, includes class and function declarations.
// - List.cpp: Implementation file for the List class, includes function definitions.

#include "List.h"
#include <iostream>

using namespace std;

int main() {
    // create a List instance
    List myList;

    // add elements to the list
    myList.add(10.0);
    myList.add(0.0);
    myList.add(-10.55);

    // display the contents of the list
    cout << "List contents:" << endl;
    myList.view();

    // remove an element from the list
    myList.remove(0.0);

    // display the updated contents of the list
    cout << "List contents after removal:" << endl;
    myList.view();

    return 0;
}
