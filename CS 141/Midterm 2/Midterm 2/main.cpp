// lab14.cpp
// Build in the function to do all sorts of linked list operations

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
        cout << pTemp->data << " ";  	// display the data at this node
        pTemp = pTemp->pNext;		// advance to next node
    }
    cout << "\n\n";
}

// Prepend to beginning of list
void prependToBeginningOfList( Node *&pHead, int number)
{
    Node *pTemp = new Node;			// allocate a new node
    pTemp->pNext = pHead;		// make it point to front of list
    pTemp->data = number;		// store the number
    pHead = pTemp;				// make this new node the new front of list
}//end prependToBeginningOfList(...)


// append a node onto the end of a list
void appendToEndOfList( Node *&pHead, Node *&pTail, int number)
{
    Node *pTemp = new Node;			// allocate a new node
    
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


//Task 1
// Modify the function insertNodeInOrder so that the function order numbers in an ascending order.
// The modified program would give the following output.
void insertNodeInOrder(  Node *&pHead,		// pointer to front of list
                       int number)		// number to be inserted
{
    Node *pNewNode;		// stores new node for malloc
    Node *pTemp = pHead;	// iterator to move down list
    
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
        while ( (pTemp->pNext != NULL) && (number >= pTemp->pNext->data) )  {
            pTemp = pTemp->pNext;		// advance to next node
        }
        
        // See if number goes at front of list
        if ( number <= pHead->data)  {
            // insert at front of list
            pNewNode->pNext = pHead;
            pHead = pNewNode;
        }
        else {
            // Node goes in the middle or at the end of list
            // Insert after node pointed to by pTemp
            pNewNode->pNext = pTemp->pNext;	// redundant assignment of NULL
            //    if appending to end of list
            pTemp->pNext = pNewNode;
        }
        
    } // end else
}//end insertNodeInOrder()


// build the list
void createAList( Node * &pHead)
{
    int number = 0; 	     // stores user input
    Node *pTemp = NULL;		 // used to allocate new nodes
    Node *pTail = NULL;
    
    // Prompt for numbers to be stored in linked list
    cout << "Linked list sample program, Inserting in order. \n";
    cout << "Enter as many integers > 0 as you would like, followed by -1:  ";
    
    // Read in values, creating nodes as we go and appending them to list
    while ( number != -1) {
        cin >> number;
        if (number != -1) {
            //appendToEndOfList( pHead, pTail, number);
            //prependToBeginningOfList( pHead, number);
            insertNodeInOrder( pHead, number);
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
        counter++;						// increment counter
        pCurrent = pCurrent->pNext; 	// advance node pointer to next node
    }
    
    return pCurrent;
}//end getNthNode(...)


// Search for and display the nth node
void promptForNthNodeToDisplay( Node *pCurrent)
{
    int nodeNumber;			// number of node to be found
    
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
    int nodeNumber;			// number of node to be found
    Node *pCurrent = NULL;	// pCurrent also points to head of list
    Node *pTemp;			// Will point to node to be deleted
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

// Task 2&3
// Implement a function called void reverseList( Node *&pHead) to reverse a list.
// Once the function is done, pHead should point to the node that used to be the last list Node in the linked list.

void reverseList( Node *&pHead)
{
    if(pHead == NULL) return;
    
    Node *prev = NULL, *ptemp = NULL, *next = NULL;
    ptemp = pHead;
    while(ptemp != NULL){
        next = ptemp->pNext;
        ptemp->pNext = prev;
        prev = ptemp;
        ptemp = next;
    }
    pHead = prev;
}


//-------------------------------------------------------------------------------------
int main()
{
    Node *pHead = NULL;	   // keeps track of head of list
    
    // Create two lists to append one to the other
    Node *pListA = NULL;
    createAList( pListA);
    Node *pListB = NULL;
    createAList( pListB);
    
    // Append list B onto end of List A
    append( pListA, pListB);
    // Display new complete list
    displayList( pListA);
    
    sort( pListA);
    displayList( pListA);
    
     //Uncomment the following lines to work on Task 2&3
     pHead = pListA;
     reverseList( pHead);
     displayList( pHead);
     printf("pHead's data has the value: %d\n",pHead->data);	
    
    cout << "Ending Linked List program.  Exiting ...";
}

