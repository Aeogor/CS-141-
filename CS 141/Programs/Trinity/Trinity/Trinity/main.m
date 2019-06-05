/* ------------------------------------------------
 *
 *
 * Class: CS 141, Spring 2016.  Tuesday 10am lab.
 * System: Mac OS X, Xcode
 * Author: Srinivas Lingutla
 * TA's Name:Itika Gupta
 *
 * ToDo: Play the Trinity Game!
 *
 *
 * -------------------------------------------------
 */

//Headers
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>



//A function to sort the order of the parameters that were passed in assending order. Here parameters were passed through pointers by reference.

void order (int *a, int *b)
{
    int inter;
    if(*a > *b)
    {
        inter = *a;
        *a = *b;
        *b = inter;
    }
    
} //End of the function order

/* ---------------------------------------------------------------------------------------------------*/


//A function that displays the table with the remaining pieces that were unused.
void displayPieces(
                   char b1,char b2,char b3,char b4,char b5,char b6,char b7, char b8,char b9, char pieceToPlay)

{
    
    printf("\n-------------------------------------------\n\n");
    printf("Pieces Available to play:\n");
    printf("\n");
    printf ("     %c   %c   %c \n", b1, b2, b3);
    printf ("     %c   %c   %c \n", b4, b5, b6);
    printf ("     %c   %c   %c \n", b7, b8, b9);
    printf ("\n\n");
    
}//End of the function displayPieces


/* ---------------------------------------------------------------------------------------------------*/


//A function named displayTable that displays the table after the user has inputed a character and position.
void displayTable (char p1,char p2,char p3,char p4,char p5,char p6,char p7, char p8,char p9, int x, char y)
{
    
    //If condition to check whether the posotion (x) is within the following limits [1,9]. If true the table is printed with only the characters already used.
    if (x==1 || x==2 || x==3 || x==4 || x==5 || x==6 || x==7 || x==8 || x==9) {
        
        
        
        printf("-------------             Positions\n");
        printf("| %c | %c | %c |            1   2   3\n", p1, p2, p3);
        printf("-------------\n");
        printf("| %c | %c | %c |            4   5   6\n", p4, p5, p6);
        printf("-------------\n");
        printf("| %c | %c | %c |            7   8   9\n", p7,p8, p9);
        printf("-------------\n");
        printf ("\n\n");
    }
    
}

/* ---------------------------------------------------------------------------------------------------*/



//A function to check whether any row/column/diagonal in the table has the winning conditions.
void winningCondition (char p1,char p2,char p3, bool *condition) {
    
    //Declaring and initialising variables to that of the characters user entered
    int a =p1;
    int b=p2;
    int c=p3;
    
    
    //Calling the function order to sort the following code in ascending order, so that comparing the variables will be efficient.
    order(&a, &b);
    order(&a, &c);
    order(&b, &c);
    
    //Code to check whether ascii values of the inputed characters match with that of the winning conditions. This code checks the first row of the table.
    if(a==65&&b==66&&c==67)
    {
        printf("We have a winner with %c %c %c!\n", a,b,c);
        *condition = 0;
    }
    else if (a==49&&b==50&&c==51)
    {
        printf("We have a winner with %c %c %c!\n", a,b,c);
        *condition = 0;
    }
    else if (a==97&&b==98&&c==99)
    {
        printf("We have a winner with %c %c %c!\n", a,b,c);
        *condition = 0;
    }
    else if (a==49&&b==65&&c==97)
    {
        printf("We have a winner with %c %c %c!\n", a,b,c);
        *condition = 0;
    }
    else if (a==50&&b==66&&c==98)
    {
        printf("We have a winner with %c %c %c!\n", a,b,c);
        *condition = 0;
    }
    else if (a==51&&b==67&&c==99)
    {
        printf("We have a winner with %c %c %c!\n", a,b,c);
        *condition = 0;
    }
    else if (a==49&&b==66&&c==99)
    {
        printf("We have a winner with %c %c %c!\n", a,b,c);
        *condition = 0;
    }
    else if (a==49&&b==67&&c==98)
    {
        printf("We have a winner with %c %c %c!\n", a,b,c);
        *condition = 0;
    }
    else if (a==50&&b==65&&c==99)
    {
        printf("We have a winner with %c %c %c!\n", a,b,c);
        *condition = 0;
    }
    else if (a==50&&b==67&&c==97)
    {
        printf("We have a winner with %c %c %c!\n", a,b,c);
        *condition = 0;
    }
    else if (a==51&&b==65&&c==98)
    {
        printf("We have a winner with %c %c %c!\n", a,b,c);
        *condition = 0;
    }
    else if (a==51&&b==66&&c==97)
    {
        printf("We have a winner with %c %c %c!\n", a,b,c);
        *condition = 0;
    }
    

}








//Main function
int main(void)

{
    
    //Print out Information
    printf("Program #2: Trinity\n");
    printf("Author: Srinivas Chowdhary Lingutla\n");
    printf("Lab: Tues 10am\n");
    printf("TA's Name: Itika Gupta\n");
    printf("Date: Febuary 2, 2016\n");
    printf("System:  Xcode on MacOS X \n\n\n");
    
    //Print out description of the game, Trinity
    printf(" \n\n\nWelcome to Trinity, the game where there's three ways to get three in a row, in one of three rows or columns, or diagonals.  Play alternates between the two players. On each move select any available piece and an open board destination location.  A winning configuration is three of the same set in a row (e.g. b a c, A B C or 3 2 1),  all 3 from the same set position (e.g. A 1 a, B 2 b or c 3 C), or three in a row where each is different set member (1st, 2nd, 3rd) such as 2 A c, a B 3 or C 1 b.  \n\n ");
    
    
    //A Char variable that stores the position that was inputted by the user.
    char position;
    char pos;
    //A char variable that stores the character the was inputted by the user. It is initially initialised at space.
    char pieceToPlay = ' ';
    char piecetoplay = ' ';
    //A third variable that the stores the return character to maintain the fluency in the code.
    char returnChar;
    
    // A variable for the loop counter
    int i = 0;
    
    //A variable to store whether the player is 1 or 2
    int player = 0;
    
    
    //A Set of char variables that store all the possibilities of the characters
    char b1 = 'A';
    char b2 = 'B';
    char b3 = 'C';
    char b4 = 'a';
    char b5 = 'b';
    char b6 = 'c';
    char b7 = '1';
    char b8 = '2';
    char b9 = '3';
    
    //A set of char variables that were initialised as space and converted to inputted character accordingly.
    char p1 = ' ';
    char p2 = ' ';
    char p3 = ' ';
    char p4 = ' ';
    char p5 = ' ';
    char p6 = ' ';
    char p7 = ' ';
    char p8 = ' ';
    char p9 = ' ';
    
    //int variable to check the position in the function displayTable
    int x = 1;
    
    //A boolean condition to check whether the player won. If there is a matching condition, then condition will be set to 0 and the for loop will end.
    bool condition = 1;
    
    //for loop to loop through 9 times since there are 9 items on the board.
    for( i = 0; i<9 &&condition==1; i++)
        
    {
        //A boolean character to check
        bool repeat;
        printf("\n\n");
        
        //Calling a function to display the characters that were unused.
        displayPieces(b1, b2, b3, b4, b5, b6, b7 ,b8, b9,pieceToPlay);
        
        //A function that displays the table with the characted that were inputted by the user.
        displayTable (p1,p2,p3,p4,p5,p6,p7,p8,p9,x,pieceToPlay);
        
        //An equation that altenates between 1 and 2 to display the player number
        player = i%2 + 1;
        
        //A do while loop to check all the pieces that were entered were valid and allowed
        do
        {
            
            //A do while loop that repeats when incorrect information is entered
            do
            {
                
                
                printf("\nPlayer %d, please enter the piece to place and its position: ", player);
                
                //Gets the input from the user of the information of the piece and the position
                scanf("%c%c%c", &piecetoplay, &pos, &returnChar);     // reads user input
                
                pieceToPlay = piecetoplay;
                position = pos;
                
                
                //initialising the variable repeat to 1
                repeat = 1;
                
                //A switch case to check the input of the piece and change the b1 to space. If the position is already taken, it changes the repeat to 0 and outputs an error.
                switch(pieceToPlay)
                {
                    case 'A' :
                        if ( pieceToPlay == b1)
                        {
                            b1 = ' ';
                        }
                        else{
                            printf("Invalid piece. Enter Again");
                            repeat = 0;
                        }
                        break;
                    case 'B' :
                        if ( pieceToPlay == b2)
                        {
                            b2 = ' ';
                            
                        }
                        else{
                            printf("Invalid piece. Enter Again");
                            repeat = 0;
                        }
                        break;
                    case 'C' :
                        if ( pieceToPlay == b3)
                        {
                            b3 = ' ';
                            
                        }
                        else{
                            printf("Invalid piece. Enter Again");
                            repeat = 0;
                        }
                        break;
                    case 'a' :
                        if ( pieceToPlay == b4)
                        {
                            b4 = ' ';
                            
                        }
                        else{
                            printf("Invalid piece. Enter Again");
                            repeat = 0;
                        }
                        break;
                    case 'b' :
                        if ( pieceToPlay == b5)
                        {
                            b5 = ' ';
                            
                        }
                        else{
                            printf("Invalid piece. Enter Again");
                            repeat = 0;
                        }
                        break;
                    case 'c' :
                        if ( pieceToPlay == b6)
                        {
                            b6 = ' ';
                            
                        }
                        else{
                            printf("Invalid piece. Enter Again");
                            repeat = 0;
                        }
                        break;
                    case '1' :
                        if ( pieceToPlay == b7)
                        {
                            b7 = ' ';
                            
                        }
                        else{
                            printf("Invalid piece. Enter Again");
                            repeat = 0;
                        }
                        break;
                    case '2' :
                        if ( pieceToPlay == b8)
                        {
                            b8 = ' ';
                            
                        }
                        else{
                            printf("Invalid piece. Enter Again");
                            repeat = 0;
                        }
                        break;
                    case '3' :
                        if ( pieceToPlay == b9)
                        {
                            b9 = ' ';
                            
                        }
                        else{
                            printf("Invalid piece. Enter Again");
                            repeat = 0;
                        }
                        break;
                        
                    default:
                        
                        printf("\nInvalid input: Enter again\n");
                        repeat = 0;
                        
                        break;
                        
                }
                
                
                //A code to make the following switch statement run only when the character entered is valid.
                if (repeat!=0) {
                    
                    
                    //A code to check the proper position of the entered value and make sure it is valid. If position is already taken, then it triggers the repeat to 0 and ouputs an error messgae.
                    switch(position)
                    {
                        case '1' :
                            if (p1 == ' ') {
                                
                                
                                if ( position == '1')
                                {
                                    
                                    p1=pieceToPlay;
                                }
                                
                                else{
                                    printf("Invalid position. Enter Again");
                                    repeat = 0;
                                }
                            }
                            else
                            {
                                printf("Invalid position. Enter Again");
                                repeat = 0;
                            }
                            break;
                        case '2' :
                            if (p2 == ' ') {
                                
                                
                                if ( position == '2')
                                {
                                    
                                    p2=pieceToPlay;
                                }
                                
                                else{
                                    printf("Invalid position. Enter Again");
                                    repeat = 0;
                                }
                            }
                            else
                            {
                                printf("Invalid position. Enter Again");
                                repeat = 0;
                            }
                            break;
                        case '3' :
                            if (p3 == ' ') {
                                
                                
                                if ( position == '3')
                                {
                                    
                                    p3=pieceToPlay;
                                }
                                
                                else{
                                    printf("Invalid position. Enter Again");
                                    repeat = 0;
                                }
                            }
                            else
                            {
                                printf("Invalid position. Enter Again");
                                repeat = 0;
                            }                    break;
                        case '4' :
                            if (p4 == ' ') {
                                
                                
                                if ( position == '4')
                                {
                                    
                                    p4=pieceToPlay;
                                }
                                
                                else{
                                    printf("Invalid position. Enter Again");
                                    repeat = 0;
                                }
                            }
                            else
                            {
                                printf("Invalid position. Enter Again");
                                repeat = 0;
                            }                    break;
                        case '5' :
                            if (p5 == ' ') {
                                
                                
                                if ( position == '5')
                                {
                                    
                                    p5=pieceToPlay;
                                }
                                
                                else{
                                    printf("Invalid position. Enter Again");
                                    repeat = 0;
                                }
                            }
                            else
                            {
                                printf("Invalid position. Enter Again");
                                repeat = 0;
                            }                    break;
                        case '6' :
                            if (p6 == ' ') {
                                
                                
                                if ( position == '6')
                                {
                                    
                                    p6=pieceToPlay;
                                }
                                
                                else{
                                    printf("Invalid position. Enter Again");
                                    repeat = 0;
                                }
                            }
                            else
                            {
                                printf("Invalid position. Enter Again");
                                repeat = 0;
                            }                    break;
                        case '7' :
                            if (p7 == ' ') {
                                
                                
                                if ( position == '7')
                                {
                                    
                                    p7=pieceToPlay;
                                }
                                
                                else{
                                    printf("Invalid position. Enter Again");
                                    repeat = 0;
                                }
                            }
                            else
                            {
                                printf("Invalid position. Enter Again");
                                repeat = 0;
                            }                    break;
                        case '8' :
                            if (p8 == ' ') {
                                
                                
                                if ( position == '8')
                                {
                                    
                                    p8=pieceToPlay;
                                }
                                
                                else{
                                    printf("Invalid position. Enter Again");
                                    repeat = 0;
                                }
                            }
                            else
                            {
                                printf("Invalid position. Enter Again");
                                repeat = 0;
                            }                    break;
                        case '9' :
                            if (p9 == ' ') {
                                
                                
                                if ( position == '9')
                                {
                                    
                                    p9=pieceToPlay;
                                }
                                
                                else{
                                    printf("Invalid position. Enter Again");
                                    repeat = 0;
                                }
                            }
                            else
                            {
                                printf("Invalid position. Enter Again");
                                repeat = 0;
                            }
                            break;
                            
                        default:
                            
                            printf("\nInvalid position: Enter again\n");
                            repeat = 0;
                            break;
                            
                            
                    }
                }
            }
            //A condition to repeat the process if the either the position or the piece were invalid
            while ( repeat==0);
            
            
            
            // A condition to check all the entered values were within the set parameters and limits.
        }
        while((position<0||position>9) &&((pieceToPlay!='A')&&(pieceToPlay!='B')&&(pieceToPlay!='C')&&(pieceToPlay!='a')&&(pieceToPlay!='b')&&(pieceToPlay!='c')&&(pieceToPlay!='1')&&(pieceToPlay!='2')&&(pieceToPlay!='3')));
        
        
        //A call to the function to check whether the entered value is a winning condition.
        
         //Checking the first row
         winningCondition(p1,p2,p3, &condition);
         //Checking the second row
         winningCondition(p4,p5,p6, &condition);
         //Checking the third row
         winningCondition(p7,p8,p9, &condition);
         //Checking the first column
         winningCondition(p1,p4,p7, &condition);
         //Checking the second column
         winningCondition(p2,p5,p8, &condition);
         //Checking the third column
         winningCondition(p3,p6,p9, &condition);
         //Checking the first diagonal
         winningCondition(p1,p5,p9, &condition);
         //Checking the second diagonal
         winningCondition(p3,p5,p7, &condition);
        
        
        
        
        
    }
    
    //Printing the final table with the desired result.
    printf("\n\n");
    printf("-------------             Positions\n");
    printf("| %c | %c | %c |            1   2   3\n", p1, p2, p3);
    printf("-------------\n");
    printf("| %c | %c | %c |            4   5   6\n", p4, p5, p6);
    printf("-------------\n");
    printf("| %c | %c | %c |            7   8   9\n", p7,p8, p9);
    printf("-------------\n");
    printf ("\n\n");
    
    //Checking the program whether it is a draw or not. 
    if(condition == 0)
        printf("\nplayer %d, YOU WON!\n", player);
    else
        printf("DRAW");
}

//THE END :)









