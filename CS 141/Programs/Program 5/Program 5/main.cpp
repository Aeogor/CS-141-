//
//  main.cpp
//  Program 5
//
//  Created by Srinivas Lingutla on 3/22/16.
//  Copyright © 2016 Srinivas Lingutla. All rights reserved.



/* ------------------------------------------------
 *
 *
 * Class: CS 141, Spring 2016.  Tuesday 10am lab.
 * System: Mac OS X, Xcode
 * Author: Srinivas Lingutla
 * TA's Name: Itika Gupta
 * Program #5: SpeechGrade
 *
 * Todo: Assign a grade to each of the presidential cadidates' speeches
 *
 *
 * -------------------------------------------------
 */




//Headers
#include <iostream>
#include <cstring>
#include <fstream>
#include <cassert>
#include <algorithm>
#include <cstdio>
#include <cctype>
#include <string.h>
#include <cstring>
using namespace std;



//Function called when the file doesnt open
void openFail(int x)
{
    if (1 == x) cout << "Input file ";
    else cout << "Output file ";
    cout << "failed to open." << endl;
    exit(EXIT_FAILURE);
}


//COUNT WORDS and sentences

void countwords(long int size, char filename[size], double &wordcount, double &sentcount)
{ char ch;
    //open file with the name filename
    ifstream infile;
    infile.open(filename);
    ch = infile.get();
    while (ch != EOF)
    {
        //increment the wordcount if the conditions are met
        if (ch == 32  || ch==10 || ch==13 || ch==45 )  wordcount = wordcount + 1;
        //increment the sentence count if the conditions are met
        if ((ch == '.' || ch== '!' || ch=='?' ))  sentcount = sentcount + 1;
        //assign the next character to ch
        ch = infile.get();
    }
    //print out the wordcount and sentcount
    printf("Total number of words in %s are: %.0f\n",filename, wordcount);
    printf("Total number of sentences in %s are: %.0f\n",filename, sentcount);
}

//CHECK IF the character passed is VOWEL OF NOT

bool isvowel (char c){
    bool vowel = false;
    //switch case to check if the character is vowel
    switch (c) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'y':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
        case 'Y':
            //turn the boolean statement true if it is a vowel
            vowel = true;
            break;
        default:{
            vowel = false;
            break;
        }
    }
  
    return vowel;
}


//COUNT SYLLABLES

int sylableCount(long int size, char filename[size], double &syllablecount){
    //check if the file opens properly
    ifstream file;
    file.open (filename);
    if (!file.is_open()){
        return 0;
    }
    //initialise the current syllable to 0
    int currentsyllable = 0;
    string word;
    while (file >> word) //get the word
    {
        size_t len = word.length();  //get the word length
        currentsyllable = 0;
        for (long int k=len-1; k>=0; k--) { //loop through the word length
            
            if (isvowel(word[k])) { //checking if the letter is a vowel or not.
                syllablecount++;
                currentsyllable++;
            }
        }
    
        for (long int k=len-2; k>1; k--) {

            if  ((isvowel(word[k]) && isvowel(word[k-1])) || word[k]=='y') { //checking if the word has two adjacent vowels or y within a word
                currentsyllable--;
                syllablecount--;
            }
        }
      
            if (((isvowel(word[len-3]) && !isvowel(word[len-2]))  && word[len-1]=='e' && currentsyllable>1) ||
                ((isvowel(word[len-3]) && !isvowel(word[len-3])) && word[len-2]=='e' && word[len-1]=='s' && currentsyllable>1)) {
                //if condition to check if the word contains e/es with vowel-consonent
                syllablecount--;
                currentsyllable--;
            }
            else if ((isvowel(word[len-1]) && currentsyllable>1)) { //checking the last letter of the word and if it is a vowel or not.
                syllablecount--;
                currentsyllable--;
            }
        }
    
    printf("Total number of syllables in %s are: %.0f\n",filename, syllablecount); //printing out  the total number of syllables

       return 0;
    //cout << numSylable;
}





int main(){
    
    
    //displaying the personal info
    printf("Program #5: SpeechGrade\n");
    printf("Author: Srinivas Chowdhary Lingutla\n");
    printf("Lab: Tues 10am\n");
    printf("TA's Name: Itika Gupta\n");
    printf("Date: April 4, 2016\n");
    printf("System:  Xcode on MacOS X \n\n\n");

    
    
    
    // declare array of filenames
    double total[17];
    double wordcount[17], sentcount[17], syllablecount[17];
    //initialising the array to 0
    for (int j=0; j<17; j++) {
     wordcount[j]=0;
     sentcount[j] = 0;
     syllablecount[j] = 0;
    }
    //declaring the filenames
    char filenames[17][20] = {"BenCarson.txt", "BernieSanders.txt", "ChrisChristie.txt", "CarlyFiorina.txt", "DonaldTrump.txt", "HillaryClinton.txt", "JamesWebb.txt", "JebBush.txt", "JohnKasich.txt", "LindseyGraham.txt", "MarcoRubio.txt", "MikeHuckabee.txt", "RandPaul.txt", "RickPerry.txt", "RickSantorum.txt", "ScottWalker.txt", "TedCruz.txt"};
    //calling the functions to get the count and find the toatal scores
    for(int i=0; i<17; i++) {
        long int size = strlen(filenames[i]);
        countwords(size, filenames[i], wordcount[i], sentcount[i]);
        sylableCount(size, filenames[i], syllablecount[i]);
        printf("\n");
        total[i] = 0.39*(wordcount[i]/sentcount[i]) + 11.8*(syllablecount[i]/wordcount[i]) - 15.59;
    }
    
    //bubble sort through the total and filenames array to sort them accordingly
    double temp; char temp2;
    for(int i = 0; i < 17; i++)
    {
        for(int j = 0; j < 17; j++)
        {
            if(total[i] < total[j])
            {
                //swap the values
                temp = total[i];
                total[i] = total[j];
                total[j] = temp;
                
                //swap the filenames
                strcpy(&temp2, filenames[i]);
                strcpy(filenames[i], filenames[j]);
                strcpy(filenames[j], &temp2);
            }
        }
    }
    for (int i=0; i<17; i++) {
        printf("%20-s ------>   %0.1f\n", filenames[i],total[i]); //printing out the result.
    }
    return 0;
}














