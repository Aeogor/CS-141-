//
//  Decipher.cpp
//  Decipher
//
//  Created by Srinivas Lingutla on 2/10/16.
//  Copyright © 2016 Srinivas Lingutla. All rights reserved.
//


/* ------------------------------------------------
 *
 *
 * Class: CS 141, Spring 2016.  Tuesday 10am lab.
 * System: Mac OS X, Xcode
 * Author: Srinivas Lingutla
 * TA's Name:Itika Gupta
 *
 * ToDo: Decipher code
 *
 *
 * -------------------------------------------------
 */

//Headers
#include <iostream>
#include <cstring>
#include <fstream>
#include <cassert>


using namespace std;

//size of the array
const  int Size = 81;



//A function to lookup the word and increament the parameters if word is found
void lookup_word(char wordToLookup[], int &currgreatestNumberOfEnglishWords, int &currTranposeNumber, int shift){
    
    //Max number of words
    int MaxNumberOfWords = 99000;
   
    //code to check if the parameters are passed correctly
   //printf("word: |%s|, ", wordToLookup);
    
   
    
    ifstream inStream;                          // declare an input stream for my use
    char theWords[ MaxNumberOfWords][ Size];    // Array to store words from input line
    int wordRow = 0;                            // Row for the current word
 //   char wordToLookup[ Size];                   // word to lookup
    bool wordWasFound = false;                  // flag to track whether or not word is found
  //  char c;
    int i;
    
    // stores return character after input
    
    inStream.open( "dictionaryMax6.txt");
    assert( ! inStream.fail() );  // make sure file open was OK
    
    // Keep repeating while input from the file yields a word
    while ( wordRow < MaxNumberOfWords && inStream >> theWords[wordRow] )
    {
        
        wordRow++;
        
        if(wordRow>MaxNumberOfWords)
        {
            cout<<"END"<<endl;
            break;
        }
    }
    
    // Prompt for and get the word to be looked up
    //cout << "Enter the word to lookup: ";
    //cin >> wordToLookup;
    //cin.get( c);      // clear the "enter" character from the input buffer.
    
    // See if the word is found
    // Note that if we didn't know exactly the number of words in the array,
    // (which could be less than the total number that *could* be stored)
    // then we would need to initialize each array element to NULL so that
    // string compare wouldn't choke.
    for (i=0; i<wordRow; i++)  {
        // See if this word matches
        if ( strcmp( wordToLookup, theWords[i]) == 0 ){
            wordWasFound = true;
            
            //If code is found, increment the number of english words found.
            currgreatestNumberOfEnglishWords++;
            currTranposeNumber = shift;
            break;      // quit looking
        }
    }
    
    //code to check if the word was correctly found or not
    if ( wordWasFound ){
     //   cout << wordToLookup << " was found at position " << i << endl;
    }
    else {
    //    cout << wordToLookup << " was not found in the array." << endl;
    }
 
    
    
}





//A function that reverses the string input
char reverse_string(char str[])
{
    char temp;
    size_t len = strlen(str) - 1;
    size_t i;
    size_t k = len;
    
    for(i = 0; i < len; i++)
    {
        temp = str[k];
        str[k] = str[i];
        str[i] = temp;
        k--;
        
        /* As 2 characters are changing place for each cycle of the loop
         only traverse half the array of characters */
        if(k == (len / 2))
        {
            break;
        }
    }
    return 0;
}






//A function to encrypt and decrypt the code accordingly
void text_encrypt()
{
    //Variables
    int shift;
    char cipher[81];
    char origcipher[81];
    int reverse;
    int ccipher;
    
    //Get users input
    printf("\nEnter the text to be encoded: ");
    cin.get(cipher, 81);
    
    //copy the cipher to original code
    strcpy(origcipher, cipher);
    
    //Get the direction of the code
    printf("\nEnter direction (1 Forwards or 2 Reverse): ");
    cin >> reverse;
    
    //If user wants reverse, then reverse the string input
    if (reverse == 2) {
        reverse_string(cipher);
        //printf("Reversed Text: %s\n", cipher);
    }
    
    //Get the shift value
    printf("\nEnter transposition value: ");
    cin >> shift;
    
    //length of the array
    size_t num = strlen(cipher);
        
    //for loope to move each character by the shift value and wrap around accordingly
    for (int i=0; i < num; i++)
    {
        //get the integer value of the cipher
        ccipher = (int)cipher[i];
        if ((ccipher + shift) >= 32 && (ccipher + shift)<= 126)
        
            cipher[i] = (char)(ccipher + shift);
        
        else if ((ccipher + shift)> 126)
        {
            cipher[i] = (char)(((ccipher + shift - 32 + 94) % 94) + 31);
        }
        else if ((ccipher + shift)< 32)
        {
            cipher[i] = (char)(((ccipher + shift - 32 + 94) % 94) + 31);
        }
    }
    
    //print the orginal and final statements
    printf("Original and changed text are: \n%s \n%s\n",origcipher, cipher);

    
}



//A function to encrypt and decrypt the code accordingly
void text_decrypt()
{
    //Variables
    int shift;
    char cipher[81];
    char origcipher[81];
    int ccipher;
    
    //Get users input
    printf("\nEnter the text to be decoded: ");
    cin.get(cipher, 81);
    
    //copy the cipher to original code
    strcpy(origcipher, cipher);
    
    //Get the shift value
    printf("\nEnter transposition value: ");
    cin >> shift;
    
    //length of the array
    size_t num = strlen(cipher);
    
    //for loope to move each character by the shift value and wrap around accordingly
    for (int i=0; i < num; i++)
    {
        //get the integer value of the cipher
        ccipher = (int)cipher[i];
        if ((ccipher + shift) >= 32 && (ccipher + shift)<= 126)
            
            cipher[i] = (char)(ccipher + shift);
        
        else if ((ccipher + shift)> 126)
        {
            cipher[i] = (char)(((ccipher + shift - 32 + 94) % 94) + 31);
        }
        else if ((ccipher + shift)< 32)
        {
            cipher[i] = (char)(((ccipher + shift - 32 + 94) % 94) + 31);
        }
    }
    
    //print the orginal and final statements
    printf("\nOriginal and changed text are: \n%s \n%s   <--- Forward\n",origcipher, cipher);
    
    reverse_string(cipher);
    printf("%s   <--- Reverse \n", cipher);
    
    
}





//A function to decode the text
void decodeString(char *cipher, int shift){
    
    
    int ccipher;
    size_t num = strlen(cipher);
    
    
    
        //for loope to move each character by the shift value and wrap around accordingly
        for (int i=0; i < num; i++)
        {
            //get the integer value of the cipher
            ccipher = (int)cipher[i];
            if ((ccipher + shift) >= 32 && (ccipher + shift)<= 126)
                
                cipher[i] = (char)(ccipher + shift);
            
            else if ((ccipher + shift)> 126)
            {
                cipher[i] = (char)(((ccipher + shift - 32 + 94) % 94) + 31);
            }
            else if ((ccipher + shift)< 32)
            {
                cipher[i] = (char)(((ccipher + shift - 32 + 94) % 94) + 31);
            }
        }
    
    
    
}





//A function to search the word the and lookup in the dictionary
void searchword(){
    
    

    //the array for the user input
    char cipher[81];
    //variables to store the number of words and the shift
    int greatestNumberOfEnglishWords = 0;
    int greatestTranposeNumber = 0;
    int currgreatestNumberOfEnglishWords = 0;
    int currTranposeNumber = 0;
    
    //get the user input
    printf("\nEnter the text to be encoded: ");
    cin.get(cipher, 81);
    
    //vopy over the original string
    char cipherorig[81];
    strcpy(cipherorig, cipher);
    
    
    


    int transpositionNumber;
    
    //for loop to loop through all the transposition numbers
    for ( transpositionNumber = 94; transpositionNumber >=0; transpositionNumber--)
    {
        //
        // this function will get every transposed string -- basically steps 1 - 3
        // put into a function (you don't have to necessarily put it into a function,
        // it's just a suggestion)
        //
        
        decodeString(cipher, transpositionNumber);
        
        //Set total found words to 0
        currgreatestNumberOfEnglishWords = 0;
        
        //
        // now that you the transposed string, print it out so you can determine if
        // your code works
        //
        //cout << "Transpose number: " << transpositionNumber << ": " << cipher << endl;
    
    
        //
        // get the number of characters in the string
        //
        size_t numCharsInString = strlen(cipher);
        
        //
        // you are going to need a variable to put the word
        //
        char word[6];  // words aren't longer than 6 characters
        
        //
        // you are going to need an index variable for the spaces in the word variable
        //
        int j = 0;
        
        //
        // now loop through the transposed string, and examine each character in the string
        // if the character is a space, then you know you've reached the end of a word
        //
       
        
    
        
        
      //for loop for normal statment -- normal
        for (int i = 0; i < numCharsInString; i++)
        {
            
            
            
            //
            // if (the character is NOT a space, put the character into the word variable)
            //
            if (cipher[i]!=' ')
            {
                if(j<6){
                word[j] = cipher[i]; // put the character into the word variable)
                j++;  // need to increment the word index
                }
            }
            //
            // else, the character IS a space, in which case we've come to the end of the
            // word.  This means that we can check if it's in the dictionary
            //
            else if (cipher[i]==' ')
            {
                //printf("%s\n", word);
                //search the word in the dictionary
                lookup_word(word, currgreatestNumberOfEnglishWords, currTranposeNumber, transpositionNumber); // this is the entire point of the exercise
                j = 0;  // you need to start j over
                memset(&word[0], 0, strlen(word));  // so you can reuse the "word" variable
                
                
            }
            if (i==(strlen(cipher)-1)) {
                lookup_word(word, currgreatestNumberOfEnglishWords, currTranposeNumber, transpositionNumber); // this is the entire point of the exercise
                j = 0;  // you need to start j over
                memset(&word[0], 0, strlen(word));  // so you can reuse the "word" variable
                
            }
            
            
            
            
        }
        
       //set the word string to NULL
         memset(&word[0], 0, strlen(word));
        
        //if the string found more words, assign them
        if (currgreatestNumberOfEnglishWords > greatestNumberOfEnglishWords)
        {
            greatestNumberOfEnglishWords = currgreatestNumberOfEnglishWords;
            greatestTranposeNumber = transpositionNumber;
        }
        
        //Set total found words to 0
        currgreatestNumberOfEnglishWords = 0;
        
        
        
        //for loop for reverse statement  - reverse
        
        reverse_string(cipher);
        //strcat(cipher, " ");
        for (int i = 0; i < numCharsInString; i++)
        {
            
            
            
            //
            // if (the character is NOT a space, put the character into the word variable)
            //
            if (cipher[i]!=' ')
            {
                if(j<6){
                    word[j] = cipher[i]; // put the character into the word variable)
                    j++;  // need to increment the word index
                }
            }
            //
            // else, the character IS a space, in which case we've come to the end of the
            // word.  This means that we can check if it's in the dictionary
            //
            else if (cipher[i]==' ')
            {
                //printf("%s\n", word);
                lookup_word(word, currgreatestNumberOfEnglishWords, currTranposeNumber, transpositionNumber); // this is the entire point of the exercise
                j = 0;  // you need to start j over
                memset(&word[0], 0, strlen(word));  // so you can reuse the "word" variable
                
                
            }
            if (i==(strlen(cipher)-1)) {
                lookup_word(word, currgreatestNumberOfEnglishWords, currTranposeNumber, transpositionNumber); // this is the entire point of the exercise
                j = 0;  // you need to start j over
                memset(&word[0], 0, strlen(word));  // so you can reuse the "word" variable
                
            }
            
        }
               //set the word string to NULL
        memset(&word[0], 0, strlen(word));
        
        if (currgreatestNumberOfEnglishWords > greatestNumberOfEnglishWords)
        {
            greatestNumberOfEnglishWords = currgreatestNumberOfEnglishWords;
            greatestTranposeNumber = transpositionNumber;
        }
        
        
        currgreatestNumberOfEnglishWords = 0;
        
        
        
    
    
    strcpy(cipher, cipherorig);
        
    
    }
    
    //printf the normal statement
    decodeString(cipherorig, greatestTranposeNumber);
    printf("\nNormal Statement --->    '%s'  \nTransposition    --->     %d\n\n", cipherorig, greatestTranposeNumber);
    
    //print the reverse statement
    reverse_string(cipherorig);
    
    printf("\nReverse Statement --->   '%s'  \nTransposition    --->     %d\n", cipherorig, greatestTranposeNumber);

    
}



//main function
int main () {

    char choice;
    

    //displaying the personal info
    printf("Program #3: Decipher\n");
    printf("Author: Srinivas Chowdhary Lingutla\n");
    printf("Lab: Tues 10am\n");
    printf("TA's Name: Itika Gupta\n");
    printf("Date: Febuary 22, 2016\n");
    printf("System:  Xcode on MacOS X \n\n\n");
    
    
    
    
    //giving options for the use
    printf("Choose the following options\n");
    printf("    1. Encode some text\n");
    printf("    2. Decode using user-entered values\n");
    printf("    3. Decode automatically\n");
    printf("    4. Exit program\n");
    
    //getting the user's choise
    printf("Your Choice: ");
    cin.get(choice);
    
    cin.ignore();
    
    
    
    printf("%c\n",choice);
    
    
    
    switch (choice) {
        case '1':
        {
            
                text_encrypt();
               break;
        }
         
            
        case '2':
        {
                text_decrypt();
        break;
        }
         
            
        case '3':
        {
           
           searchword();
            break;
        }
            case '4':
        {
            exit(0);
        }
        default:
        {
            printf("No such choice! Run the program again to try again! Good Luck!");
            break;
    
        }
    }
  
    
    

    
  
}


