/* trinity.cpp
 
 Description: Play a tic-tac-toe-like game where there are
 various ways to get 3 in a row.
 Author: Dale Reed
 Date: 1/29/2016
 Class: CS 141, UIC
 
 Because we have not yet fully studied arrays, the implementation
 below uses individual variables.  One key idea is to write functions to
 get and set these individual variables.  A second key idea came
 from a student, and that is to use the ASCII sum of pieces to
 help check for a winning combination when looking for the combination
 with the 1st in one set, 2nd in the other, and 3rd in the other.
 
 The problem is broken down using functions, to avoid to a great extent
 the need to enumerate all winning combinations.
 
 Running the program looks like:
 
 Program #2: Trinity
 Author: Dale Reed
 Lab: Tues 5am
 Date: January 22, 2016
 System:  DevC++ on Windows 10
 
 Welcome to Trinity, the game where there's three ways
 to get three in a row, in one of three rows or columns,
 or diagonals.  Play alternates between the two players.
 On each move select any available piece and an open
 board destination location.  A winning configuration
 is three of the same set in a row (e.g. b a c, A B C
 or 3 2 1),  all 3 from the same set position (e.g. A 1 a,
 B 2 b or c 3 C), or three in a row where each is a
 different set member (1st, 2nd, 3rd) such as 2 A c,
 a B 3 or C 1 b.
 
 
 ------------------------------------
 Pieces available to play:
 A B C
 1 2 3
 a b c
 
 -----------   Positions:
 |   |   |   |    1  2  3
 |-----------|
 |   |   |   |    4  5  6
 |-----------|
 |   |   |   |    7  8  9
 -----------
 1. Player 1 enter piece and position: A1
 
 ------------------------------------
 Pieces available to play:
 B C
 1 2 3
 a b c
 
 -----------   Positions:
 | A |   |   |    1  2  3
 |-----------|
 |   |   |   |    4  5  6
 |-----------|
 |   |   |   |    7  8  9
 -----------
 2. Player 2 enter piece and position: 16
 
 ------------------------------------
 Pieces available to play:
 B C
 2 3
 a b c
 
 -----------   Positions:
 | A |   |   |    1  2  3
 |-----------|
 |   |   | 1 |    4  5  6
 |-----------|
 |   |   |   |    7  8  9
 -----------
 3. Player 1 enter piece and position: C8
 
 ------------------------------------
 Pieces available to play:
 B
 2 3
 a b c
 
 -----------   Positions:
 | A |   |   |    1  2  3
 |-----------|
 |   |   | 1 |    4  5  6
 |-----------|
 |   | C |   |    7  8  9
 -----------
 4. Player 2 enter piece and position: a5
 
 ------------------------------------
 Pieces available to play:
 B
 2 3
 b c
 
 -----------   Positions:
 | A |   |   |    1  2  3
 |-----------|
 |   | a | 1 |    4  5  6
 |-----------|
 |   | C |   |    7  8  9
 -----------
 5. Player 1 enter piece and position: A1
 *** Piece A is not available. Please retry: b5
 *** Location 5 is already taken. Please retry: 22
 
 ------------------------------------
 Pieces available to play:
 B
 3
 b c
 
 -----------   Positions:
 | A | 2 |   |    1  2  3
 |-----------|
 |   | a | 1 |    4  5  6
 |-----------|
 |   | C |   |    7  8  9
 -----------
 
 Congratulations player 1 on winning the game!
 
 Done.
 
 --------------------------------
 Process exited after 102 seconds with return value 0
 Press any key to continue . . .
 */

#include <iostream>
using namespace std;


//--------------------------------------------------------------------------------
void displayIdentifyingInformationAndInstructions()
{
    cout << "Program #2: Trinity \n"
 		 << "Author: Dale Reed \n"
 		 << "Lab: Tues 5am \n"
 		 << "Date: January 22, 2016 \n"
 		 << "System:  DevC++ on Windows 10 \n"
 		 << " \n"
 		 << "Welcome to Trinity, the game where there's three ways \n"
 		 << "to get three in a row, in one of three rows or columns, \n"
 		 << "or diagonals.  Play alternates between the two players. \n"
 		 << "On each move select any available piece and an open \n"
 		 << "board destination location.  A winning configuration \n"
 		 << "is three of the same set in a row (e.g. b a c, A B C  \n"
 		 << "or 3 2 1),  all 3 from the same set position (e.g. A 1 a,  \n"
 		 << "B 2 b or c 3 C), or three in a row where each is a  \n"
 		 << "different set member (1st, 2nd, 3rd) such as 2 A c, \n"
 		 << "a B 3 or C 1 b.    \n"
 		 << " \n";
}


//--------------------------------------------------------------------------------
// Display the playing pieces and the board
/* This will look something like:
	------------------------------------
	Pieces available to play:
 A B C
 1 2 3
 a b c
 
 -----------   Positions:
	|   |   |   |    1  2  3
	|-----------|
	|   |   |   |    4  5  6
	|-----------|
	|   |   |   |    7  8  9
 -----------
 */
void displayBoard( char p1, char p2, char p3,
                  char p4, char p5, char p6,
                  char p7, char p8, char p9,
                  char b1, char b2, char b3,
                  char b4, char b5, char b6,
                  char b7, char b8, char b9 )
{
    printf(" \n");
    printf(" ------------------------------------\n");
    printf(" Pieces available to play:           \n");
    printf("    %c %c %c \n", p1,p2,p3);
    printf("    %c %c %c \n", p4,p5,p6);
    printf("    %c %c %c \n", p7,p8,p9);
    printf("                            \n");
    printf("  -----------   Positions:  \n");
    printf(" | %c | %c | %c |    1  2  3\n", b1,b2,b3);
    printf(" |-----------|              \n");
    printf(" | %c | %c | %c |    4  5  6\n", b4,b5,b6);
    printf(" |-----------|              \n");
    printf(" | %c | %c | %c |    7  8  9\n", b7,b8,b9);
    printf("  -----------               \n");
}// end displayIdentifyingInformationAndInstructions()


//--------------------------------------------------------------------------------
// Given a piece to be played, return the character stored
// in the corresponding piece variable, or an error message and
// the space character if that piece is not available
char getPiece(
              char thePiece,				// Piece 'A','B','C','1','2','3','a','b','c'
              char p1, char p2, char p3,
              char p4, char p5, char p6,
              char p7, char p8, char p9)
{
    // Find matching piece and return it
    switch( thePiece) {
        case 'A': return p1; break;
        case 'B': return p2; break;
        case 'C': return p3; break;
        case '1': return p4; break;
        case '2': return p5; break;
        case '3': return p6; break;
        case 'a': return p7; break;
        case 'b': return p8; break;
        case 'c': return p9; break;
        default:
            printf("*** Invalid piece index of %d was sent in fcn getPiece(). \n");
            break;
    }
    return '*';   // default, which should only happen if invalid piece was selected
}// end getPiece()


//--------------------------------------------------------------------------------
// Clear the selected piece
void clearPiece(
                char thePiece, 					// Piece 'A','B','C','1','2','3','a','b','c'
                char &p1, char &p2, char &p3,
                char &p4, char &p5, char &p6,
                char &p7, char &p8, char &p9)
{
    switch( thePiece) {
        case 'A': p1 = ' '; break;
        case 'B': p2 = ' '; break;
        case 'C': p3 = ' '; break;
        case '1': p4 = ' '; break;
        case '2': p5 = ' '; break;
        case '3': p6 = ' '; break;
        case 'a': p7 = ' '; break;
        case 'b': p8 = ' '; break;
        case 'c': p9 = ' '; break;
        default:
            // Give an error message if the pieceNumber is invalid
            printf("*** Invalid piece index of %d was sent in fcn clearPiece(). \n");
            break;
    }
}// end clearPiece()


//--------------------------------------------------------------------------------
// Return the piece stored at a particular board position,
char getBoardPiece(
                   char position, 			// Board position '1'..'9'
                   char b1, char b2, char b3,
                   char b4, char b5, char b6,
                   char b7, char b8, char b9)
{
    // Find the matching position, and return the piece at that position
    switch( position) {
        case '1': return b1; break;
        case '2': return b2; break;
        case '3': return b3; break;
        case '4': return b4; break;
        case '5': return b5; break;
        case '6': return b6; break;
        case '7': return b7; break;
        case '8': return b8; break;
        case '9': return b9; break;
        default:
            // Sanity check, which normally should not get triggered.
            // Give an error message if user didn't enter one of the valid pieces
            printf("*** Invalid piece index of %d was sent in fcn getBoardPiece(). \n");
            break;
    }
    
    return '*';   // This will only get executed if an invalid position was sent
}// end getBoardPiece()


//--------------------------------------------------------------------------------
// Set the board destination to be the character previously validated
// Return ' ' upon normal completion, or '*' if the destination is invalid
void setBoardPiece(
                   char position, 				// Board position '1'..'9'
                   char thePiece,				// Piece 'A','B','C','1','2','3','a','b','c'
                   char &b1, char &b2, char &b3,
                   char &b4, char &b5, char &b6,
                   char &b7, char &b8, char &b9)
{
    // Set the board piece to the indicated character
    switch( position) {
        case '1': b1 = thePiece; break;
        case '2': b2 = thePiece; break;
        case '3': b3 = thePiece; break;
        case '4': b4 = thePiece; break;
        case '5': b5 = thePiece; break;
        case '6': b6 = thePiece; break;
        case '7': b7 = thePiece; break;
        case '8': b8 = thePiece; break;
        case '9': b9 = thePiece; break;
        default:
            // Give an error message if user didn't enter one of the valid pieces
            printf("Invalid piece index of %d was sent in fcn setPiece. \n");
            break;
    }
}// end setBoardPiece()


//--------------------------------------------------------------------------------
// Prompt for move, get user input and validate it, and then make the move
void promptForAndMakeMove(
                          char &p1, char &p2, char &p3, 	// The nine pieces that can be played
                          char &p4, char &p5, char &p6,
                          char &p7, char &p8, char &p9,
                          char &b1, char &b2, char &b3, 	// The nine board positions
                          char &b4, char &b5, char &b6,
                          char &b7, char &b8, char &b9,
                          int moveNumber, 				// Current move number
                          int player)					// Alternates between 1 or 2
{
    char piece;				//
    char position;
    char returnCharacter;
    
    // Prompt for player and piece
    printf("%d. Player %d enter piece and position: ", moveNumber, player);
    
    // loop to validate piece selection and board destination
    while( true){
        // Read in user input
        scanf("%c%c%c", &piece, &position, &returnCharacter);
        
        // Validate selected piece.
        if( getPiece(piece, p1,p2,p3,p4,p5,p6,p7,p8,p9) == ' ') {
            printf("*** Piece %c is not available. Please retry: ", piece);
            continue;
        }
        
        // Validate selected board destination.  setPiece(...) returns ' ' for valid input
        if( getBoardPiece(position, b1,b2,b3,b4,b5,b6,b7,b8,b9) != ' ') {
            printf("*** Location %c is already taken. Please retry: ", position);
            continue;
        }
        
        // If we got here, both selected piece and board destination are valid
        break;		// break out of input validation loop
    }
    
    // Now that input has been validated, blank out the piece and place it on board
    clearPiece( piece, p1,p2,p3,p4,p5,p6,p7,p8,p9);
    setBoardPiece( position, piece, b1,b2,b3,b4,b5,b6,b7,b8,b9);
    
}// end promptForAndMakeMove()


//--------------------------------------------------------------------------------
// Find minimum of two values
char getMin( char c1, char c2)
{
    if( c1<=c2) {
        return c1;
    }
    else {
        return c2;
    }
}//end getMin()


//--------------------------------------------------------------------------------
// Find maximum of two values
char getMax( char c1, char c2)
{
    if( c1>=c2) {
        return c1;
    }
    else {
        return c2;
    }
}//end getMax()


//--------------------------------------------------------------------------------
// Take the three characters passed as parameters and sort them into ascending
// alphanumerical order, returning them in order using those reference parameters.
void sortThreePieces( char &c1, char &c2, char &c3)
{
    // temporary values used for sorting
    char temp1 = c1;
    char temp2 = c2;
    char temp3 = c3;
    
    // Find the min, the max, and then subtract those two from the total to find mid
    c1 = getMin( getMin( temp1, temp2), temp3 );   // min value stored in c1
    c3 = getMax( getMax( temp1, temp2), temp3 );   // max value stored in c3
    c2 = (temp1 + temp2 + temp3) - c1 - c3;			// use math to find mid
}//end sortThreePieces()


//--------------------------------------------------------------------------------
// Check for 3 in a horizontal row. Since they are sorted, we only need to check
// a single condition for each set of 3.  Board values for checking are:
//     1 2 3
//     A B C
//     a b c
int threeAreFoundInARowOrColumn( char c1, char c2, char c3)
{
    return (c1=='A' && c2=='B' && c3=='C') ||
    (c1=='1' && c2=='2' && c3=='3') ||
    (c1=='a' && c2=='b' && c3=='c') ||
		  (c1=='1' && c2=='A' && c3=='a') ||
		  (c1=='2' && c2=='B' && c3=='b') ||
		  (c1=='3' && c2=='C' && c3=='c');
}//end areThreeInARow()


//--------------------------------------------------------------------------------
// Check for a win where one of the pieces is the first in its set ('A','1','a'),
// one piece is the second in its set ('B','2','b'), and the remaining piece is
// the third in its set ('C','3','c').  When the ASCII values of these pieces
// are added together, they should always equal 214.  For instance:
//   e.g. '1'(49) + 'B'(66) + 'c'(99) = 214
// The one exception to this is when all three pieces are middle pieces ('B','2','b')
// Since the parameters are sorted, we only have to check this single permutation.
// For reference, pieces are:
//     A B C
//     1 2 3
//     a b c
int oneIsFirstSecondAndThird( char c1, char c2, char c3)
{
    return (c1 + c2 + c3 == 214) &&
    !(c1=='2' && c2=='B' && c3=='b');
}//end oneIsFirstSecondAndThird()


//--------------------------------------------------------------------------------
// Check the board for a winning configuration of 3 in a row for the pieces
// at the 3 index positions. The three characters are put into alphanumerical
// order, to minimize the number of resulting positions that must be checked.
int checkWinFor(
                char position1, int position2, int position3,
                char b1, char b2, char b3,
                char b4, char b5, char b6,
                char b7, char b8, char b9)
{
    char c1 = getBoardPiece( position1, b1,b2,b3,b4,b5,b6,b7,b8,b9);
    char c2 = getBoardPiece( position2, b1,b2,b3,b4,b5,b6,b7,b8,b9);
    char c3 = getBoardPiece( position3, b1,b2,b3,b4,b5,b6,b7,b8,b9);
    
    // Put these 3 characters in alphanumeric order, to make it easier to check results
    // This puts numbers first, then upper-case, then lower-case
    sortThreePieces( c1, c2, c3);
    
    // Comment out the first condition below if you want to play the game only
    // with the condition of one piece from each group, where the pieces are all
    // from a different position.
    return threeAreFoundInARowOrColumn( c1, c2, c3) ||
    oneIsFirstSecondAndThird( c1, c2, c3);
}//end checkWinFor()


//--------------------------------------------------------------------------------
// Check for winning configurations.  If there is a win, return 1, else return 0
// Possible winning configurations have to be checked for every row of 3, every
// column of 3, and the two diagonals.  Index values for the checking are:
//     1 2 3
//     4 5 6
//     7 8 9
int thereIsAWin(
                char b1, char b2, char b3,
                char b4, char b5, char b6,
                char b7, char b8, char b9)
{
    return checkWinFor( '1','2','3', b1,b2,b3,b4,b5,b6,b7,b8,b9) ||  // Check rows
    checkWinFor( '4','5','6', b1,b2,b3,b4,b5,b6,b7,b8,b9) ||
    checkWinFor( '7','8','9', b1,b2,b3,b4,b5,b6,b7,b8,b9) ||
    checkWinFor( '1','4','7', b1,b2,b3,b4,b5,b6,b7,b8,b9) ||  // Check columns
    checkWinFor( '2','5','8', b1,b2,b3,b4,b5,b6,b7,b8,b9) ||
    checkWinFor( '3','6','9', b1,b2,b3,b4,b5,b6,b7,b8,b9) ||
    checkWinFor( '1','5','9', b1,b2,b3,b4,b5,b6,b7,b8,b9) ||  // Check diagonals
    checkWinFor( '7','5','3', b1,b2,b3,b4,b5,b6,b7,b8,b9);
}//end thereIsAWin


//--------------------------------------------------------------------------------
int main()
{
    // Declare and initialize playing pieces
    char p1,p2,p3,p4,p5,p6,p7,p8,p9;
    p1='A'; p2='B'; p3='C';
    p4='1'; p5='2'; p6='3';
    p7='a'; p8='b'; p9='c';
    // Declare and initialize board pieces
    char b1,b2,b3,b4,b5,b6,b7,b8,b9;
    b1=b2=b3=b4=b5=b6=b7=b8=b9=' ';
    int player = 1;         // will be 1 or 2
    int thereWasAWin = 0;   // Flag used to display message when there was a win
    
    displayIdentifyingInformationAndInstructions();
    
    // Loop for the maximum of 9 possible moves
    for( int moveNumber=1; moveNumber<=9; moveNumber++) {
        // Display the pieces remaining to play and the board
        displayBoard( p1,p2,p3,p4,p5,p6,p7,p8,p9, b1,b2,b3,b4,b5,b6,b7,b8,b9 );
        
        // Prompt for move and make move
        promptForAndMakeMove( p1,p2,p3,p4,p5,p6,p7,p8,p9, b1,b2,b3,b4,b5,b6,b7,b8,b9, moveNumber, player );
        
        // See if there was a win
        if( thereIsAWin( b1,b2,b3,b4,b5,b6,b7,b8,b9)) {
            thereWasAWin = 1;   // set flag indicating there was a win, used to display win message
            break;		       // Break out of the loop making moves
        }
        else {
            // Only alternate the player number if there was no win, to make sure the
            // game win message displays the correct winning user.
            // Player number alternates between 1 and 2.  If 1, switch to 2, and visa-versa.
            // Rather than an if-else, we could use the decision statement for this, 
            // which equivalently would be: 	player = (player==1) ? 2 : 1;
            if( player == 1) {
                player = 2;
            }   
            else {
                player = 1;
            }
        }	
    }//end for( int moveNumber...
    
    // After having made the last move, display the final board
    displayBoard( p1,p2,p3,p4,p5,p6,p7,p8,p9, b1,b2,b3,b4,b5,b6,b7,b8,b9 );
    
    // Display message there was a win
    if( thereWasAWin) {
        printf("\n");
        printf("Congratulations player %d on winning the game! \n", player);
    }
    
    cout << "\n"
	 	 << "Done. \n";
}// end main()
