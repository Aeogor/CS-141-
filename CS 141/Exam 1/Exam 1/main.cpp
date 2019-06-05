
#include <iostream>

#include <cstring>

#include <string.h>

#include <string>

using namespace std;


/* ------------------------------------------------
 *        --------EXAM 1------------
 *
 * Class: CS 141, Spring 2016.  Tuesday 10am lab.
 * System: Mac OS X, Xcode
 * Author: Srinivas Lingutla
 * TA's Name:Itika Gupta
 *
 * ToDo: Search and replace a word in a user-inputted string
 *
 *
 * -------------------------------------------------
 */



//----------------------------------------------------------

// Only change the code inside this function.

//    Start with inserting the declarations for the parameters.

//

// This function should change the original array by

// removing the wordToRemove and adding the wordToInsert.

//

void change( char text[81], char word[81], char replace[81])
{
    //initialising variables
    char str[10][10];
    int i=0,j=0,k=0,w;
    char final[81] = "";
    
    //unsigned long for the length of string
    size_t p=strlen(text);
    
    for (k=0; k<p; k++)
    {
        
        if (text[k]!=' ')
        {
            str[i][j] = text[k];
            j++;
        }
        else
        {
            str[i][j]='\0';
            j=0; i++;
        }
    }
    str[i][j]='\0';
    w=i;
   
    for (i=0; i<=w; i++)
    {
        if(strcmp(str[i],word)==0){
            strcpy(str[i],replace);}
        
        strcat(str[i], " ");
        strcat(final, str[i]);
        strcpy(text, final);
      
       //copying over the sentence into text
    }
    

    
}//end change


//----------------------------------------------------------

// DO NOTE CHANGE CODE INSIDE main().

//     Only change code in function change(...) above.

//

int main()
{
    char original[ 81];      // to store a user input line
    
    char wordToRemove[ 81];  // word to be removed
    
    char wordToInsert[ 81];  // new word to be inserted
    
    
    
    
    
    printf("Enter the original text: ");
    
    cin.getline( original, 80);            // read the whole line into an array
    
    
    printf("Enter word to remove: ");
    
    cin.getline( wordToRemove, 80);            // read the whole line into an array
    
    
    
    printf("Enter new word to insert: ");
    
    cin.getline( wordToInsert, 80);            // read the whole line into an array
    
    
    printf("Old string is: %s\n", original);  //printing out the original text
    // Do the substitution
    
    change( original, wordToRemove, wordToInsert);
    
    
    
    // Display the new string
    
    printf("New string is: %s\n", original); //printing out final text
    
    
    
    return 0;
}