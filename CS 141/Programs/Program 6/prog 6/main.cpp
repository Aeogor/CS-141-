//
//  main.cpp
//  prog 6
//
//  Created by Srinivas Lingutla on 4/8/16.
//  Copyright © 2016 Srinivas Lingutla. All rights reserved.
//


/* ------------------------------------------------
 *
 *
 * Class: CS 141, Spring 2016.  Tuesday 10am lab.
 * System: Mac OS X, Xcode
 * Author: Srinivas Lingutla
 * TA's Name: Itika Gupta
 * Program #6: Hunt the Wumpus
 *
 * Todo: Create a game to kill the wumpus!
 *
 *
 * -------------------------------------------------
 */


//Header files
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sstream>
#include <iostream>

using namespace std;

static int userinput[3]; //gets and stores the userinput

static int movenumber; //variable containing the move location

static int j, k, arrows, temp_loc;

static int location[7];	/* locations */
//location[0] = my location
//location[1] = wumpus location
//location[2] = pit1
//location[3] = pit2
//location[4] = bat1
//location[5] = bat2
//location[6] = arrow location

static int finished;

static bool arrow_check;

//------------------------------------------------------------------------------------------------------------------------------------------//

//create a node to store the values
 struct Node {
    int room_number;
    int moveNumber;
    int bat1_location;
    int bat2_location;
    int arrow_location;
     int wumpus_location;
     //node pointer to move through the list
    Node * pNext;
 };

static Node *pHead;      // pointer to head of list
static Node *pTemp;
//--------------------------------------------------------------------------------
// Create a new node.
//    Function receives the board and the move number and returns address of a new
//    node with all values set.
Node * createNode( int room_number, int moveNumber, int bat1_location, int bat2_location, int arrow_location, int wumpus_location)
{
    // allocate memory for new node.
    Node *pTemp = new Node();
    
    // place copy of current values into node
    pTemp->room_number = room_number;
    pTemp->moveNumber = moveNumber;
    pTemp->bat1_location = bat1_location;
    pTemp->bat2_location = bat2_location;
    pTemp->wumpus_location = wumpus_location;
    pTemp->arrow_location = arrow_location;
    
    //return ptemp
    return pTemp;
    
}//end createNode()

//------------------------------------------------------------------------------------------------------------------------------------------//

// Take the values from the linked list node and reset the current playing values
// and move number using those values.  This allows undoing a move.
void restoreValues( Node *pHead,
                   int room_number, int moveNumber, int bat1_location, int bat2_location, int arrow_location, int wumpus_location)
{
    // restore the location values
    location[0] = pHead->room_number;
    location[4] = pHead->bat1_location;
    location[5] = pHead->bat2_location;
    location[6] = pHead->arrow_location;
    location[1] = pHead->wumpus_location;
    moveNumber = pHead->moveNumber;
    
    //code to check whether I have collected the arrow.
    if(location[6]+1==location[0])
        arrow_check = true;
}//end restoreValues()

//------------------------------------------------------------------------------------------------------------------------------------------//

//setting up the array for the caves with tunnels-1
static int cave[20][3] =
{
    {1,4,7},
    {0,2,9},
    {1,3,11},
    {2,4,13},
    {0,3,5},
    {4,6,14},
    {5,7,16},
    {0,6,8},
    {7,9,17},
    {1,8,10},
    {9,11,18},
    {2,10,12},
    {11,13,19},
    {3,12,14},
    {5,13,15},
    {14,16,19},
    {6,15,17},
    {8,16,18},
    {10,17,19},
    {12,15,18},
};


//------------------------------------------------------------------------------------------------------------------------------------------//


//printing out the instructions
void print_the_instructions()
{

    printf("Author: Srinivas Lingutla             ______18______ \n");
    printf("CS 141 Program #6: Wumpus            /      |       \\    \n");
    printf("TA: Itika Gupta, T 10:00AM          /      _9__      \\    \n");
    printf("April 21, 2016                     /      /    \\      \\   \n");
    printf("System: Xcode on Mac              /      /      \\      \\  \n");
    printf("                                 17     8        10     19\n");
    printf("Hunt the Wumpus:                |  \\   / \\      /  \\   / |\n");
    printf("The Wumpus lives in a           |   \\ /   \\    /    \\ /  |\n");
    printf("completely dark cave of         |    7     1---2     11  |\n");
    printf("20 rooms. Each room has         |    |    /     \\    |   |\n");
    printf("3 tunnels leading to other      |    6----5     3---12   |\n");
    printf("rooms as shown:                 |    |     \\   /     |   |\n");
    printf("                                |    \\       4      /    |\n");
    printf("                                |     \\      |     /     |\n");
    printf("                                 \\     15---14---13     /\n");
    printf("                                  \\   /           \\    /\n");
    printf("                                   \\ /             \\  / \n");
    printf("                                   16---------------20  \n");
    
    cout << "Hazards:" << endl;
    cout << "1. Two rooms have bottomless pits in them.  If you go there you fall and die." << endl;
    cout << "2. Two other rooms have super-bats.  If you go there, the bats grab you and" << endl;
    cout << "   fly you to some random room, which could be troublesome.  Then those bats" << endl;
    cout << "   go to some random room." << endl;
    cout << "3. The Wumpus is not bothered by the pits or bats, as he has sucker feet and" << endl;
    cout << "   is too heavy for a bat to lift.  Usually he is asleep.  Two things wake" << endl;
    cout << "   him up: Anytime you shoot an arrow, or you entering his room.  When he  " << endl;
    cout << "   wakes he moves one room 75% of the time, staying still the other 25% of   " << endl;
    cout << "   the time. After that, if he is in your room, he eats you and you die!" << endl << endl;
    cout << "Moves:" << endl;
    cout << "On each move you can:" << endl;
    cout << "1. Move into an adjacent room.  To move enter 'M' followed by a space and " << endl;
    cout << "   then a room number.  " << endl;
    cout << "2. Shoot your guided arrow through a list of three adjacent rooms, which " << endl;
    cout << "   you specify.  Your arrow ends up in the final room. If an arrow " << endl;
    cout << "   can't go a direction because there is no connecting tunnel, it ricochets " << endl;
    cout << "   and moves to a randomly selected adjacent room and continues" << endl;
    cout << "   doing this until it has traveled 3 rooms in total.  If the arrow " << endl;
    cout << "   hits the Wumpus, you win! If the arrow hits you, you lose. You " << endl;
    cout << "   automatically pick up an arrow if you go through a room with an arrow in  " << endl;
    cout << "   it. To shoot enter 'S' followed by a list of up to 3 adjacent room numbers " << endl;
    cout << "   separated by spaces." << endl;
    cout << "3. Undo your last move by entering 'U'" << endl << endl;
    cout << "Good luck!" << endl;
}

//------------------------------------------------------------------------------------------------------------------------------------------//

//function to check the hazards
void hazards_check()
{
    int wumpus_check = 0, draft_check = 0, bats_check = 0;
    
    //set the location of the arrow, if the user has it
    if(arrow_check == true)
        location[6] = location[0] +1 ;
    
    //call the function createNode and set current values to the node
    pTemp = createNode( location[0], movenumber, location[4], location[5], location[6], location[1]);      // create the new node
    pTemp->pNext = pHead;                           // Connect new node to the old head of list
    pHead = pTemp;                                  // This new node becomes the new head of the list
    
    //Check the near by tunnels for hazards
    for (k = 0; k < 3; k++)
    {
        int room = cave[location[0]][k];
        
        //check the wumpus
        if (room == location[1] && wumpus_check == 0){
            puts("   I SMELL A WUMPUS!");
            wumpus_check = 1;
        }
        else if ((room == location[2] || room == location[3]) && draft_check == 0){
            puts("   I FEEL A DRAFT");
            draft_check = 1;
        }
        else if ((room == location[4] || room == location[5]) && bats_check == 0 ){
            puts("   BATS NEARBY!");
            bats_check = 1;
        }
    }
    //Increase the move number
    movenumber++;
    //Print the move instructions
     printf("\n%d. You are in room: %d.  ",movenumber, location[0]+1);
    
     printf("Tunnels lead to : %d %d %d\n",
                  cave[location[0]][0]+1, cave[location[0]][1]+1, cave[location[0]][2]+1);
    
    
}

//------------------------------------------------------------------------------------------------------------------------------------------//

//get user input whether he wants to move or shoot

int move_or_shoot()
{
    char move;

badin:
    //get the move
    string line;
    cout << "   Your Move: ";
    scanf("%c", &move);
    int i = 0;
    cout << endl;
    
    //get the array of userinput based on the shoot
    if (move == 'S' || move == 's'){
        getline(cin, line);
        istringstream stream(line);
        while (stream.good() && stream.peek()!='\n' && i<4){
            stream >> userinput[i];
            ++i;
            if(!stream) break;
        }
        cout << endl;
        return(1);
    }
    
    //Get the moving number
    else if (move == 'M' || move == 'm'){
        
        cin >> userinput[0];
        cin.ignore();
        return(0);
    }
    
    //print out the cheat code
    else if (move == 'c' || move == 'C'){
        cin.ignore();
        printf("   ***CHEAT***\n   Wumpus is at %d, pits at %d & %d, bats at %d & %d. The Arrow is now located at: %d. Move Number: %d\n",
               location[1]+1,
               location[2]+1, location[3]+1,
               location[4]+1, location[5]+1, location[6], movenumber);
        goto badin;
    }
    
    //code for undo
    else if( move == 'U' || move == 'u') {
        // Undo move
        cout << "Undo was selected.  Restoring game back to previous move.\n";
        movenumber--;
        
        if (pHead->pNext != NULL) {
            pTemp = pHead;          // Remember old list head so we can delete it
            pHead = pHead->pNext;   // advance list head pointer
            delete pTemp;           // Release the memory from the node no longer needed
            restoreValues( pHead, location[0], movenumber, location[4], location[5], location[6], location[1]); //get the old values
        }
        else {
            cout << "Sorry, you cannot undo past the beginning of the game.  Please retry move.";
            movenumber++;
        }
        printf("\n%d. You are in room: %d.  ",movenumber, location[0]+1);
        
        printf("Tunnels lead to : %d %d %d\n",
               cave[location[0]][0]+1, cave[location[0]][1]+1, cave[location[0]][2]+1);
       
        cin.ignore();
        goto badin;
    }
    
    //for invalid input
    else{
        printf("   That move is invalid.  Please retry\n");
        goto badin;
    }
    
}

//------------------------------------------------------------------------------------------------------------------------------------------//
//if the user selected to shoot
void shoot()
{
    extern void check_shot(), move_wumpus();
    finished = 0;
    
badrange:
    //get the location of the arrow
    temp_loc = location[0];
    bool check = 0;
    for (int k = 0; k < 3; k++) //for three rooms
    {
        int	k1;
        check =0;
        
        for (k1 = 0; k1 < 3; k1++) //for the adjacent rooms
        {
            //cout << "  My Number: " << userinput[k] << "  Nearby Tunnel: " << cave[scratchloc][k1]+1;
            
            if (cave[temp_loc][k1]+1 == userinput[k]) //set the value of the arrow to userinput
            {
                //cout << numbers.at(k);
                temp_loc =  userinput[k];
                cout <<  "\n   Arrow is now at: " << temp_loc << endl;
                location[6] = temp_loc;
                temp_loc--;
                check_shot();
                if (finished == 1)
                    return; //if won, return
                check =1;
            }
            
        }
        
        
        if(check == 0){
            temp_loc = cave[temp_loc][(rand() % 3)]; //if the user input is invalid
            check_shot();
            if (finished == 1)
                return;
        }
        
    }
}

//------------------------------------------------------------------------------------------------------------------------------------------//
//Checking the arrow shot
void check_shot()
{
    if (temp_loc == location[1]) //if the arrow location is same as that of the wumpus
    {
        puts("AHA! YOU KILLED THE WUMPUS!");
        finished = 1;
    }
    
    else if (temp_loc == location[0]) //if my location is the arrow
    {
        puts("OUCH! ARROW KILLED YOU!");
        finished = -1;
    }
}

//------------------------------------------------------------------------------------------------------------------------------------------//
//move the wumpus.
void move_wumpus()
{
    
    k = (rand() % 4);
    
    if (k < 3) //75% then move
        location[1] = cave[location[1]][k];
    
    if (location[1] != location[0]) //if you die
        return;
    
    puts("OOPS -- WUMPUS GOT YOU!");
    
    finished = -1;
    
}

//------------------------------------------------------------------------------------------------------------------------------------------//

void move()
{
    finished = 0;
    
badmove:
    //getting the moving input
    temp_loc = userinput[0];
    //cout << "My intended location: " << scratchloc << endl;
    temp_loc--;
    
    for (k = 0; k < 3; k++)
    {
        /*  *** CHECK IF LEGAL MOVE ***				*/
        if (cave[location[0]][k] == temp_loc)
            goto goodmove;
    }
    //if the move is incorrect
    if (temp_loc != location[0])
    {
        puts("   NOT POSSIBLE -- Please try again: ");
        move_or_shoot();
        
        goto badmove;
    }
    
goodmove:
    /* *** CHECK FOR HAZARDS ***				*/
    location[0] = temp_loc;
    
    if (temp_loc == location[1]) //If I am in the room of the wumpus
    {
        //puts("... OOPS! BUMPED A WUMPUS!");
        move_wumpus();
    }
    else if (temp_loc == location[2] || temp_loc == location[3]) //if I  am in a pit
    {
        puts("YYYYIIIIEEEE . . . FELL IN PIT");
        finished = -1;
    }
    else if (temp_loc == location[4] ) //if I am in the bat 1 room
    {
        puts("ZAP--SUPER BAT SNATCH! ELSEWHEREVILLE FOR YOU!");
        temp_loc = location[0] = (rand() % 20); //gets relocated
        int random = (rand() % 20);
        do
            location[4] = random;
        
        while(random == temp_loc || random == location[5]); //bats get relocated
        goto goodmove;
        
    }
    else if(temp_loc == location[5]) //if i am in the bat 2 room
    {
        puts("ZAP--SUPER BAT SNATCH! ELSEWHEREVILLE FOR YOU!");
        temp_loc = location[0] = (rand() % 20);
        int random = (rand() % 20);
        do
            location[5] = random;
        
        while(random == temp_loc || random == location[4]);
        goto goodmove;
    }
}

//------------------------------------------------------------------------------------------------------------------------------------------//

int main(){
    srand((int)time((long *) 0)); //random seeding
    movenumber = 0; //starting the move number
    arrow_check = true; //the arrow is with the player
        print_the_instructions(); //print the instructions
    Node *pHead = NULL;      // pointer to head of list
    Node *pTemp = NULL;      // pointer used to allocate nodes

    
badlocs:
    
    location[j] = (rand() % 20); //assigning random location to the user
    //printf("%d\n", loc[j]);
    
    for (j = 0; j < 7; j++)
        for (k = 0; k < 7; k++)
            if (j == k)
                continue;
            else if (location[j] == location[k])
                goto badlocs;
    
    arrows = 1; //setting the arrows
    temp_loc = location[0];
    location[6] = location[0] +1 ; //setting the arrow lcoation
    pHead = createNode( location[0], movenumber, location[4], location[5], location[6], location[1]);  //saving the values into a node

nextmove:

    hazards_check(); //check for hazards
    
    
    if (move_or_shoot())
    {
        if(location[0] +1 == location[6])  //shooting if the arrow is with me
            arrow_check = true;
        
        if(arrow_check == true){
        shoot(); //return 1
        arrow_check = false;
        }
        else{ //other wise print this
            movenumber--;
            puts("Sorry, you ran out of arrows.");
        }
        
        if (finished == 0) //check if game is over
            goto nextmove;
        
    }
    else
    {
        move(); //if return 0
        
        if (finished == 0) //check if game is over
            goto nextmove;
    }
    
    if (finished == -1) //check if game is over
    {
        //if the player loses
        puts("HA HA HA - YOU LOSE!");
    }
    else
    {
        //if the player wins
        puts("Wumpus just got whomped. You win!!!");
    }
    
}