

//Headers
#include <iostream>
#include <cstring>
#include <fstream>
#include <cassert>
#include <algorithm>
#include <cstdio>
#include <cctype>



/* ------------------------------------------------
 *
 *
 * Class: CS 141, Spring 2016.  Tuesday 10am lab.
 * System: Mac OS X, Xcode
 * Author: Srinivas Lingutla and Michael Lederer
 * TA's Name: Itika Gupta
 * Program #4: CryptoFile\
 *
 * Todo: Encrypt and Decrypt separate files
 *
 *
 * -------------------------------------------------
 */


using namespace std;

//Function called when the file doesnt open
void openFail(int x)
{
    if (1 == x) cout << "Input file ";
    else cout << "Output file ";
    cout << "failed to open." << endl;
    exit(EXIT_FAILURE);
}




//Function to go through each character in a file and change it and then output it to a different file.
void lookup_word(char letters[26], char shuffled_lower[26], char filename1[6], char filename2[6]){
    
    //Create an array to contain the capital letters of the key
    char shuffled_capital_letters[26];
    //for loop to covert and store the capital letters
    for (int i=0; i<26; i++) {
        shuffled_capital_letters[i] = toupper(shuffled_lower[i]);
        //    printf("%c\n", SampleAphabetsCapital[i]);
    }
    
    //Used for the length of the line
    size_t num = 0;
    
    // open the output file
    ifstream inputFile;
    inputFile.open(filename1); // qualified path would be better
    if (inputFile.fail()) openFail(1);
    
    //Create a new file in the name of the filename 2
    std::ofstream pfile(filename2);
    
    // read in each line as a string
    string inputLine;
    //While loop to get every line
    while (getline(inputFile, inputLine))
    {
        // convert each string to a char*
        char* line = (char*)malloc(sizeof(char)*inputLine.length());
        //Copy the string into an array of chars
        strcpy(line, inputLine.c_str());
        
        //counting the total number of letters
        num = num+strlen(line);
        
        //A for loop to go through each character
        for (int i=0; i<strlen(line); i++) {
            char c = line[i];
            
            //Converting the letters to small
            if ('A'<=c && c<='Z') {
                c=char(((int)c)+32);
            }
            //for loop to run through 26 letters of the alphabet
            for (int k=0; k<26; k++) {
                if (c==letters[k]){
                    if ('A'<=line[i] && line[i]<='Z') {
                        //c2=char(((int)c2)+32);
                        line[i]=shuffled_capital_letters[k];
                    }
                    else{
                        tolower(line[i]);
                        line[i]=shuffled_lower[k];
                    }
                }
            }
            //Output the character into the file
            pfile << line[i];
            //output the character into the terminal
            if (num<=1500) {
                printf("%c",line[i]);
            }
        }
        if(num<=1500){
            //add a new line in the terminal
            cout << endl;
        }
        pfile << std::endl;
        //Free the line
        free(line);
    }
    //close the file
    pfile.close();
    inputFile.close();
}

/****************************************************************************************************/

//function to count the total number of characters.
void increment(char letter, int (&numcount)[26]){
    
    switch (letter) {
        case 'a': numcount[0]++; break;
        case 'b': numcount[1]++; break;
        case 'c': numcount[2]++; break;
        case 'd': numcount[3]++; break;
        case 'e': numcount[4]++; break;
        case 'f': numcount[5]++; break;
        case 'g': numcount[6]++; break;
        case 'h': numcount[7]++; break;
        case 'i': numcount[8]++; break;
        case 'j': numcount[9]++; break;
        case 'k': numcount[10]++; break;
        case 'l': numcount[11]++; break;
        case 'm': numcount[12]++; break;
        case 'n': numcount[13]++; break;
        case 'o': numcount[14]++; break;
        case 'p': numcount[15]++; break;
        case 'q': numcount[16]++; break;
        case 'r': numcount[17]++; break;
        case 's': numcount[18]++; break;
        case 't': numcount[19]++; break;
        case 'u': numcount[20]++; break;
        case 'v': numcount[21]++; break;
        case 'w': numcount[22]++; break;
        case 'x': numcount[23]++; break;
        case 'y': numcount[24]++; break;
        case 'z': numcount[25]++; break;
        case 'A': numcount[0]++; break;
        case 'B': numcount[1]++; break;
        case 'C': numcount[2]++; break;
        case 'D': numcount[3]++; break;
        case 'E': numcount[4]++; break;
        case 'F': numcount[5]++; break;
        case 'G': numcount[6]++; break;
        case 'H': numcount[7]++; break;
        case 'I': numcount[8]++; break;
        case 'J': numcount[9]++; break;
        case 'K': numcount[10]++; break;
        case 'L': numcount[11]++; break;
        case 'M': numcount[12]++; break;
        case 'N': numcount[13]++; break;
        case 'O': numcount[14]++; break;
        case 'P': numcount[15]++; break;
        case 'Q': numcount[16]++; break;
        case 'R': numcount[17]++; break;
        case 'S': numcount[18]++; break;
        case 'T': numcount[19]++; break;
        case 'U': numcount[20]++; break;
        case 'V': numcount[21]++; break;
        case 'W': numcount[22]++; break;
        case 'X': numcount[23]++; break;
        case 'Y': numcount[24]++; break;
        case 'Z': numcount[25]++; break;
        default:  break;
    }
    //for my own purpose to check everything is properly done
    // printf("%d",numcount[0]);
    
    
}

/****************************************************************************************************/

//A function the count the frequencies of the characters in the files.
void frequencycounter( char (&letters)[27], char filename[11], int (&numcount)[26], char (&capital_letters)[26]){
    
    // open the output file
    ifstream inputFile;
    inputFile.open(filename); // qualified path would be better
    if (inputFile.fail()) openFail(1);
    // read in each line as a string
    string inputLine;
    while (getline(inputFile, inputLine))
    {
        // convert each string to a char*
        char* line = (char*)malloc(sizeof(char)*inputLine.length());
        strcpy(line, inputLine.c_str());
        
        // now each line is an array of characters
        //loop through each character and replace it accordingly
        for (int index=0; index<strlen(line); index++) {
            for (int j2=0; j2<26; j2++) {
                
                
                
                if (line[index]==letters[j2]) {
                    increment(letters[j2],numcount);}
                
                else if (line[index]==capital_letters[j2]) {
                    islower(capital_letters[j2]);
                    increment(capital_letters[j2],numcount);}
                
            }
        }
        //erase the line array
        free(line);
    }
    
    //declare variables for the sorting the arrays
    int n=26;
    int temp;
    char temp1;
    
    //sorting for small letters
    for(int i=0;i<n;++i)
    {
        for(int j=i+1;j<n;++j)
            if(numcount[i]<numcount[j])
            {
                //sorting the numbers
                temp=numcount[i];
                numcount[i]=numcount[j];
                numcount[j]=temp;
                //sorting the letters
                temp1 = letters[i];
                letters[i]=letters[j];
                letters[j]=temp1;
            }
    }
    
    //displaying the final sorted array
    //printf("\t%s\n", filename);
    for (int i=0; i<26; i++) {
        //printf("%c  -->  %d\t\t\n",letters[i],numcount[i]);
    }
    printf("\n\n");
}

/****************************************************************************************************/

//Function to go through each character in a file and change it and then output it to a different file.
void output(char cipherAlpha[26], char sampleAlpha[26], char filename1[6], char filename2[6]){
    
    //Create an array to contain the capital letters of the key
    char SampleAphabetsCapital[26];
    
    for (int i=0; i<26; i++) {
        SampleAphabetsCapital[i] = toupper(sampleAlpha[i]);
    //    printf("%c\n", SampleAphabetsCapital[i]);
    }
    
    size_t num = 0;
    // open the output file
    ifstream inputFile;
    inputFile.open(filename1); // qualified path would be better
    if (inputFile.fail()) openFail(1);
    
    //open a file
    std::ofstream pfile(filename2);
    
    // read in each line as a string
    string inputLine;
    while (getline(inputFile, inputLine))
    {
        // convert each string to a char* and allocating appropriate memory
        char* Ciphers_line = (char*)malloc(sizeof(char)*inputLine.length());
        strcpy(Ciphers_line, inputLine.c_str());
        // now each line is an array of characters
        
        //counter for printing out 1500 char
        num = num+strlen(Ciphers_line);
        //for loop to  go through each character
        for (int i=0; i<strlen(Ciphers_line); i++) {
            char c = Ciphers_line[i];
            
            //Converting the letters to small
            if ('A'<=c && c<='Z') {
                c=char(((int)c)+32);
           
            }
            for (int k=0; k<26; k++) {
                if (c==cipherAlpha[k]){
                    if ('A'<=Ciphers_line[i] && Ciphers_line[i]<='Z') {
                        //c2=char(((int)c2)+32);
                        Ciphers_line[i]=SampleAphabetsCapital[k];
                    }
                    else{
                        tolower(Ciphers_line[i]);
                    Ciphers_line[i]=sampleAlpha[k];
                    
                    }
                }
            }
            //display the character inthe file
            pfile << Ciphers_line[i];
            
            //display the character in the terminal
            if (num<=1500) {
                printf("%c",Ciphers_line[i]);
            }
        }
        if(num<=1500){
            cout << endl;
        }
        pfile << std::endl;
        free(Ciphers_line);
    }
    //close the files
    pfile.close();
    inputFile.close();
}
/****************************************************************************************************/

//seering random numbers every time
int myrandom (int i) { return std::rand()%i;}

int main(){
    
    //displaying the personal info
    printf("Program #4: CryptoFile\n");
    printf("Author: Srinivas Chowdhary Lingutla and Michael Lederer\n");
    printf("Lab: Tues 10am\n");
    printf("TA's Name: Itika Gupta\n");
    printf("Date: March 11, 2016\n");
    printf("System:  Xcode on MacOS X \n\n\n");
    
    int choice;
    //options for the reader
    printf("Choose Your Option: \n");
    printf("1. Encrypt a file\n");
    printf("2. Decrypt a file\n");
    //input the choice
    scanf("%d", &choice);
    
    
    switch (choice) {
        case 1:
        {
            //initialize the letters.
            char letters[27] = "abcdefghijklmnopqrstuvwxyz";
            
            char shuffled_lower[27] = "abcdefghijklmnopqrstuvwxyz";
            
            //randomly shuffle the array elements
            random_shuffle(&shuffled_lower[0], &shuffled_lower[26], myrandom);
            
            printf("You entered option 1 to encrypt file sample.txt\nThe first part of that encrypted file looks like:\n");
            printf("\n\n\n");
            //declaring the file names
            char filename1[] = "sample.txt";
            char filename2[] = "cipher.txt";
            //caliing the function
            lookup_word(letters, shuffled_lower, filename1, filename2);
            printf("\n\n");
            
            //displaying the key code for the encryption
            for (int i=0; i<26; i++) {
                printf("\n%c   -->   %c", letters[i],shuffled_lower[i]);
            }
            printf("\n\n\n");
            break;
        }
            
        case 2:
        {
            //FOR THE FIRST FILE (THE NORMAL ENGLISH CODE)
            
            printf("You entered option 2 to decrypt file cipher.txt using sample.txt. \n\n\n ");
            //intialise the characters
            char letters[27] = "abcdefghijklmnopqrstuvwxyz";
            char capital_letters[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
            //declaring the filename
            int n=15;
            char filename1[15] = "lifeonmiss.txt";
            //array to keep the total count of the characters
            int numcount1[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
            //calling the function
            frequencycounter(letters, filename1, numcount1, capital_letters);
            
            //FOR THE SECOND PART OF THE FILE (THE ENCRYPTED CODE)
            
            char letters1[27] = "abcdefghijklmnopqrstuvwxyz";
            char capital_letters1[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
            n=11;
            char filename2[11] = "cipher.txt";
            int numcount3[26] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
            frequencycounter(letters1, filename2, numcount3, capital_letters1);
            
            char filename5[11] = "result.txt";
            
            printf("\n\tThe first part of that encrypted file looks like:\n\n\n\n");
            //calling the function to substitute the characters from file1 to file 2
            output(letters1, letters, filename2, filename5);
            
        }
        default:
        {
            printf("Incorrect input");
            break;}
    }
    
    return 0;
}

/****************************************************************************************************/
//THE END






