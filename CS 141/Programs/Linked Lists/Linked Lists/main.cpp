//
//  main.cpp
//  Linked Lists
//
//  Created by Srinivas Lingutla on 4/25/16.
//  Copyright © 2016 Srinivas Lingutla. All rights reserved.
//

// LinkedListEverything.cpp
//    Build in the function to do all sorts of linked list operations

#include <iostream>
#include <cstdlib>      // for the sizeof() function
using namespace std;

// Struct for linked list nodes
struct Node {
    int data;
    Node *pNext;   // pointer to next Node.  In C this would be: struct Node *pNext
};


//-------------------------------------------------------------------------------------
void displayList( Node *pHead)
{
    Node *pTemp = pHead;  // Used to traverse list.  What would happen if we used pHead instead?
    cout << "\nList contains: ";
    while( pTemp != NULL) {
        cout << pTemp->data << " ";    // display the data at this node
        pTemp = pTemp->pNext;      // advance to next node
    }
    cout << "\n\n";
}





// Prepend to beginning of list
void prependToBeginningOfList( Node *&pHead, int number)
{
    Node *pTemp = new Node;         // allocate a new node
    pTemp->pNext = pHead;        // make it point to front of list
    pTemp->data = number;        // store the number
    pHead = pTemp;              // make this new node the new front of list
}//end prependToBeginningOfList(...)







// append a node onto the end of a list
void appendToEndOfList( Node *&pHead, Node *&pTail, int number)
{
    Node *pTemp = new Node;         // allocate a new node
    
    // handle case when it is first node
    if( pHead == NULL) {
        // Insert as new head of list
        pTemp->data = number;
        pTemp->pNext = pHead;
        pHead = pTemp;
        pTail = pTemp;
    }
    else {
        // there is already at least one node, and pTail points to it
        // Insert at the end of list
        pTemp->data = number;
        pTemp->pNext = NULL;
        pTail->pNext = pTemp;    // connect it into the list
        pTail = pTemp;           // advance tail pointer
    }
}//end appendToEndOfList(...)







//-----------------------------------------------------------------
void insertNodeInOrder(  Node *&pHead,      // pointer to front of list
                       int number)        // number to be inserted
{
    Node *pNewNode;     // stores new node for malloc
    Node *pTemp = pHead;    // iterator to move down list
    
    // get new node
    pNewNode = (Node *) malloc ( sizeof( struct Node));
    // Initialize values
    pNewNode->data = number;
    pNewNode->pNext = NULL;
    
    // Check to see if list is empty
    if (pHead == NULL)  {
        // list is empty, so make this the first node
        pHead = pNewNode;
    }
    else  {
        // list is not empty
        pTemp = pHead;
        
        // Iterate through list to find insertion location
        while ( (pTemp->pNext != NULL) && (number > pTemp->pNext->data) )  {
            pTemp = pTemp->pNext;        // advance to next node
        }
        
        // See if number goes at front of list
        if ( number < pHead->data)  {
            // insert at front of list
            pNewNode->pNext = pHead;
            pHead = pNewNode;
        }
        else {
            // Node goes in the middle or at the end of list
            // Insert after node pointed to by pTemp
            pNewNode->pNext = pTemp->pNext;   // redundant assignment of NULL
            //    if appending to end of list
            pTemp->pNext = pNewNode;
        }
        
    } // end else
}//end insertNodeInOrder()








// build the list
void createAList( Node * &pHead)
{
    int number = 0;          // stores user input
    Node *pTemp = NULL;      // used to allocate new nodes
    Node *pTail = NULL;
    
    // Prompt for numbers to be stored in linked list
    cout << "Linked list sample program, Inserting in order. \n";
    cout << "Enter as many integers > 0 as you would like, followed by -1:  ";
    
    // Read in values, creating nodes as we go and appending them to list
    while ( number != -1) {
        cin >> number;
        if (number != -1) {
            appendToEndOfList( pHead, pTail, number);
//            //prependToBeginningOfList( pHead, number);
//            insertNodeInOrder( pHead, number);
        }//if( number...
    }//while( number...
    
}//end buildTheList(...)









// Get and return the list length
int getListLength( Node *pHead)
{
    int counter = 0;
    while( pHead != NULL) {
        counter++;
        pHead = pHead->pNext;
    }
    return counter;
}//end getListLength(...)







// Return the nth node
// If list is empty, pCurrent should be NULL
Node *getNthNode( Node *pCurrent, int n)
{
    int counter = 1;   // Node numbers start at 1
    
    // While there are still nodes on the list, and we haven't reached
    // the nth node yet, advance to the next node
    while( pCurrent != NULL && counter < n) {
        counter++;                      // increment counter
        pCurrent = pCurrent->pNext;  // advance node pointer to next node
    }
    
    return pCurrent;
}//end getNthNode(...)









// Search for and display the nth node
void promptForNthNodeToDisplay( Node *pCurrent)
{
    int nodeNumber;         // number of node to be found
    
    // Prompt for and get user input
    cout << "Enter the node number you want to display: ";
    cin >> nodeNumber;
    
    // Make pCurrent point to the desired node.
    pCurrent = getNthNode( pCurrent, nodeNumber);
    
    // we found it, so print it out
    if( pCurrent != NULL) {
        cout << "At node " << nodeNumber << ", value is: " << pCurrent->data << endl;
    }
    else {
        cout << "That node number is not on the list.\n";
    }
}//end promptForNthNodeToDisplay( ...)









// Delete the nth node
void deleteNodeN( Node *&pHead, int listLength, int n)
{
    Node *pCurrent = pHead;
    Node *pTemp = NULL;
    
    // There is only one node, or the first one is the one to delete
    if( listLength==1 || n==1) {
        pTemp = pHead;
        pHead = pHead->pNext;
        delete pTemp;
        return;
    }
    else {
        // Make pCurrent point to the desired node *before* the one you want to delete,
        // and use it to delete the next node
        pCurrent = getNthNode( pHead, n-1);
    }
    
    // pCurrent should now be the Node before the one to be deleted
    if( pCurrent != NULL) {
        // Delete the node after pCurrent
        pTemp = pCurrent->pNext;
        pCurrent->pNext = pTemp->pNext;
        delete pTemp;
    }
    else {
        // Sanity check, should not get here
        cout << "There is nothing at that spot on the list.\n";
    }
}//end deleteNodeN(...)









// Prompt for node to be deleted, and then delete it
void promptForNodeToDelete( Node *&pHead)
{
    int nodeNumber;         // number of node to be found
    Node *pCurrent = NULL;  // pCurrent also points to head of list
    Node *pTemp;            // Will point to node to be deleted
    int listLength = getListLength( pHead);
    
    // Prompt for and get user input
    cout << "Enter the node number you want to delete: ";
    cin >> nodeNumber;
    
    // Handle attempts to delete from an empty list
    if( listLength==0) {
        cout << "Sorry, you can't delete from an empty list. " << endl;
        return;
    }
    // Handle attempts to delete a node out of bounds
    if( nodeNumber > listLength || nodeNumber <= 0) {
        cout << "That node number is out of bounds for this list." << endl;
    }
    
    // Delete node
    deleteNodeN( pHead, listLength, nodeNumber);
    
}//end deleteNthNode( ...)








void deleteList( Node *&pHead)
{
    int listLength = getListLength( pHead);
    
    // loop through list, deleting the 1st node each time
    for( int i=0; i<listLength; i++) {
        deleteNodeN( pHead, listLength-i, 1);
    }
}








// Append List B onto the end of List A
void append( Node *&pListA, Node *pListB)
{
    // Handle the case where List A is NULL
    if( pListA == NULL) {
        pListA = pListB;
    }
    else {
        // Find the length of list A
        int listLength = getListLength( pListA);
        // Get the last node from list A using the list length
        Node *pTail = getNthNode( pListA, listLength);
        
        // Use that tail pointer to now point to head of list B
        pTail->pNext = pListB;
    }
}//end append(...)








void sort( Node *&pList)
{
    // Make a new list
    Node *pNewList = NULL;
    
    // Step through the nodes from the existing list one at a time and
    // insert them in order into the new list
    for( Node *pCurrent = pList; pCurrent != NULL; pCurrent=pCurrent->pNext) {
        // add the current node in order to the new list
        insertNodeInOrder( pNewList, pCurrent->data);
    }
    
    // Delete the original list
    deleteList( pList);
    
    // Make the pointer from the original list point to the new list
    pList = pNewList;
}








// We already wrote this, but are just making a synonym here to use stack terminology
void push( Node *&pHead, int value)
{
    prependToBeginningOfList( pHead, value);
}








// This returns the value stored on the topmost stack node, and removes that node from the list.
// We could use deleteNodeN() to do this, but it has more complexity than we need.
int pop( Node*&pHead)
{
    int returnValue = -1;
    
    // Ensure list has at least one node
    if( pHead == NULL) {
        cout << "List is empty, so we cannot pop from it.\n";
    }
    else {
        Node *pTemp = pHead;
        returnValue = pTemp->data;
        pHead = pHead->pNext;
        delete pTemp;   // free up memory of the node being deleted
    }
    return returnValue;
}//end pop()





void removeduplicates(Node *&pHead){
    Node *pTemp = pHead;
    
    if(pTemp == NULL) return;
    
    while (pTemp->pNext != NULL) {
        if(pTemp->pNext->data == pTemp->data){
            Node *next = pTemp->pNext->pNext;
            free(pTemp->pNext);
            pTemp->pNext = next;
            
        }
        else
            pTemp = pTemp->pNext;
    }
}




void alternativesplit(Node *&pHead){
    Node *pTemp = pHead;
    
    Node *List1 = NULL;
    Node *List2 = NULL;
    Node *pTail = NULL;
    
    int counter = 0;
    
    if(pTemp == NULL) return;
    while(pTemp!=NULL){
        
        if(counter % 2 == 0){
            appendToEndOfList(List1, pTail, pTemp->data);
        }
        else
            appendToEndOfList(List2, pTail, pTemp->data);
        
        counter++;
        pTemp = pTemp->pNext;
    }
    cout << "List A";
    displayList(List1);
    cout << "List B";
    displayList(List2);
}



//-------------------------------------------------------------------------------------
int main()
{
    Node *pHead = NULL;    // keeps track of head of list
    
    //createAList( pHead);
    //displayList( pHead);
    //cout << "Length of list is: " << getListLength( pHead) << endl;
    
    // Create two lists to append one to the other
    Node *pListA = NULL;
    createAList( pListA);
   
    //Node *pListB = NULL;
    //createAList( pListB);
    
    // Append list B onto end of List A
    //append( pListA, pListB);
    // Display new complete list
    displayList( pListA);
    
    cout << "Sorting the list" << endl;
    sort( pListA);
    displayList( pListA);
    
    cout << "Removing Duplicates" << endl;
    removeduplicates(pListA);
    displayList(pListA);
    
    cout << "Alternating spliting" << endl;
    alternativesplit(pListA);
    displayList( pListA);

    
    deleteList( pListA);
    
    // Search for and display the nth node
    //promptForNthNodeToDisplay( pHead);
    
    // Delete the nth node
    //promptForNodeToDelete( pHead);
    //displayList( pHead);
    
    
    cout << "Ending Linked List program.  Exiting ...";
}



//stack



//-------------------------------------------------------------------------------------
int main()
{
    Node *pHead = NULL;    // keeps track of head of list
    char c = ' ';          // for user input one character at a time
    
    Node *pStack = NULL;
    
    // Read input line one character at a time
    cout << "Enter parenthesis then ^D (Mac) or ^Z (Windows): \n";
    while( (c=getchar()) != EOF) {
        if( c=='(') {
            push(pHead, c);
        }
        if( c==')') {
            if( pHead == NULL) {
                cout << "Missing '('" << endl;
                break;   // exit enclosing loop
            }
            else {
                pop(pHead);
            }
        }
    }
    // If list still has nodes, there were too many '('
    if( pHead != NULL) {
        cout << "Missing ')'" << endl;
    }
    
    
    while( pStack != NULL) {
        cout << (char)pop( pStack);
    }
    cout << "Ending Stack program.  Exiting ...";
}//end main()

//--------


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//----------------------------------------------------------------------------
//  Function prototypes
//
void    display_usage();
void    get_arguments( int, char**, float*, int*, char*, char**);
void    display_arguments( float, int, char, char *);
void    error(  char*, char*, int);


//----------------------------------------------------------------------------
//  main - Main Function, receives arguments and displays them.
//
int main( int argc,       // count of how many arguments, including program name
         char *argv[])   // array of char*, where each points to a C-string
{
    float floatValue = 0.0;       // floating point value command line parameter
    int   intValue = 0;           // integer value command line parameter
    char  charValue = 'A';        // character value command line parameter
    char  *stringValue = NULL;    // string value command line parameter
    
    get_arguments(  argc, argv, &floatValue, &intValue, &charValue, &stringValue);
    
    display_arguments( floatValue, intValue, charValue, stringValue);
    
    system("pause");  // for DevC++, to pause the output
}//end main()


//----------------------------------------------------------------------------
//  display_usage() - Display program usage message
//
void display_usage()
{
    printf("  USAGE:                                        \n");
    printf("    test [-f Fv] [-i Iv] [-c Cv] [-s Sv]        \n");
    printf("                                                \n");
    printf("    where the parameters are:                   \n");
    printf("            [-f Fv] = A floating point number   \n");
    printf("            [-i Iv] = An integer value          \n");
    printf("            [-c Cv] = A single character        \n");
    printf("            [-s Sv] = A string                  \n");
    
    exit( 0);
}//end display_usage()


//----------------------------------------------------------------------------
//  get_arguments - Retrieve & store command line arguments
//
void get_arguments(
                   int   argc,         // number of args, including prog. name
                   char  *argv[],      // array of strings
                   float *floatValue,  // floating point value command line parameter
                   int   *intValue,    // integer value command line parameter
                   char  *charValue,   // character value command line parameter
                   char  **stringValue)// string value command line parameter
{
    if (argc == 1)                      // No arguments at all
        display_usage();
    else {
        while ( (argc -= 2) > 0)  {      // while there is another pair of strings
            if (argv[ 1][ 0] != '-')    // Invalid syntax, no "-" before option
                display_usage();
            switch (argv[ 1][ 1]) {     // handle options
                case 'f':
                    *floatValue = atof( argv[ 2]);
                    break;
                case 'i':
                    *intValue = atoi( argv[ 2]);
                    break;
                case 'c':
                    *charValue = argv[ 2][ 0];
                    break;
                case 's':
                    *stringValue = argv[ 2];
                    break;
                default:
                    error("Incorrect parameter", &argv[ 1][ 1], 0);
            } // end switch
            
            argv += 2;          // advance to next pair of command line options
        } //end while()
        
    } //end else
}//end get_arguments()


//----------------------------------------------------------------------------
//  display_arguments - Display command line arguments
//
void display_arguments(
                       float floatValue,   // floating point value command line parameter
                       int   intValue,     // integer value command line parameter
                       char  charValue,    // character value command line parameter
                       char  *stringValue) // string value command line parameter
{
    printf( "The options to be used in running this program are: \n");
    printf( "\t A floating point number: %f\n", floatValue);
    printf( "\t An integer value: %d\n", intValue);
    printf( "\t A single character: %c\n", charValue);
    printf( "\t The string: ");
    if ( stringValue != NULL)  {
        printf( " %s\n", stringValue);
    }
    else {
        printf("\n ");
    }
}//end display_arguments()


//----------------------------------------------------------------------------
//  error() - Display program error message and exit program
//
void error(
           char *error_name,       // String describing type of error
           char *error_operand,    // String describing specific data structure used
           int  error_number)      // Error number, also used to display subscripts
{
    printf( "argcArgv program error: \n");
    printf( "*** %s WHEN OPERATING ON: %s ", error_name, error_operand);
    if (error_number != 0)
        printf( "at %d\n", error_number);
    else
        printf( "\n");
    exit(-1);
}//end error()
