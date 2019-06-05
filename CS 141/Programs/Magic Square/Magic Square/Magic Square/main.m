

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* ------------------------------------------------
 * Program to Display Russian Magic Square
 *
 * Class: CS 141, Spring 2016.  Tuesday 10am lab.
 * System: Mac OS X, Xcode
 * Author: Srinivas Lingutla
 * TA's Name:Itika Gupta
 *
 * -------------------------------------------------
 */


int main()
{
    srand ( (int) time (0) ) ;
    int RandomNum, NumofItems;
    char RandomLetter = '\0', MagicLetter = '\0';
    printf("Program #1: Russian Magic Square\n");
    printf("Author: Srinivas Chowdhary Lingutla\n");
    printf("Lab: Tues 10am\n");
    printf("TA's Name: Itika Gupta\n");
    printf("Date: January 19, 2016\n");
    printf("System:  Xcode on MacOS X \n\n\n");
    
    
        //Using for loop to create numbers and letters in table.
        for(NumofItems = 99; NumofItems >= 0; NumofItems=NumofItems-1)
        {
            //RandomNum will get a random numbers 26 since there are 26 letters. THen depending on Even/ODD it will add ASCII values to make them small/Capital
            
            RandomNum = rand() % 26 + 1;
            
            //For all even random Numbers
            if(RandomNum % 2 == 0)
                RandomLetter = RandomNum + 64;
            
            //For all odd randomNumbers
            else if (RandomNum % 2 == 1)
                RandomLetter = RandomNum + 96;
            
            //Assigning the Random letter of 99 to the magic letter as it is divisible by 9
            if(NumofItems / 9 == 11)
                MagicLetter = RandomLetter;
        
            
            
            if(NumofItems < 10){
                printf(" ");
            }
            
            //Printing multiples of 9 with the magic letter
            if(NumofItems % 9 == 0){
                printf("%d:%c  ", NumofItems, MagicLetter);
            }
            
            //Printing all other values with a random letter
            else
                printf("%d:%c  ", NumofItems, RandomLetter);
            
            //Printing a new line after 10 digits
            if(NumofItems % 10 == 0){
                printf("\n");
            }
        }
        printf("\n\n\n1. Choose any two-digit number in the table above (e.g. 73).\n");
        printf("2. Subtract its two digits from itself (e.g. 73 - 7 - 3 = 63)\n");
        printf("3. Find this new number (e.g. 63) and remember the letter next to it.\n");
        printf("4. Now press enter and I'll read your mind... ");
       
   
   //Waits for the user to press enter.
    getchar();
    
        
    //The final Result
    printf("\n\nYou have selected the letter: %c\n\n\n", MagicLetter);
    return(0);
}
