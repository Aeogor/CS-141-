//
//  MagicSquare.c
//  
//
//  Created by Srinivas Lingutla on 1/19/16.
//
//

#include <stdio.h>
int main() {
    
    // Introductory message
    printf("This program creates a magic sqaure of a specified size.\n");
    printf("The size must be an odd number between 1 and 99.\n");
    
    // Get the users magic number and allocate to int n
    int n;
    printf("Enter size of magic square: ");
    scanf("%d", &n);
    
    // Create the array (not using VLA)
    int magic[99][99];
    int start = (n / 2); // The middle column
    int max = n * n; // The final number
    magic[0][start] = 1; // Place the number one in the middle of row 0
    
    // Loop to start placing numbers in the magic square
    int row;
    int col;
    int next_row;
    int next_col;
    int i;
    for (i = 2, row = 0, col = start; i < max + 1; i++) {
        if ((row - 1) < 0) { // If going up one will leave the top
            next_row = n - 1; // Go to the bottom row
        }
        else { next_row = row - 1; } // Otherwise go up one
        printf("In row: %d\n", row);
        
        if ((col + 1) > (n - 1)) { // If column will leave the side
            next_col = 0; // Wrap to first column
            printf("Column will leave side\n");
        }
        else { next_col = col + 1; } // Otherwise go over one
        printf("In col: %d\n", col);
        
        if (magic[next_row][next_col] > 0) { // If that position is taken
            if (row > (n - 1)) { // If going to row below leaves bottom
                next_row = 0; // Go back to the top
            }
            else {
                next_row = row + 1; // Go to the row below
                next_col = col; // But stay in same column
            }
        }
        row = next_row;
        col = next_col;
        printf("About to put %d in row %d, col %d\n", i, row, col);
        magic[row][col] = i; // Put the current value in that position
    }
    
    // Now let's print the array
    int j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%4d", magic[i][j]);
        }
        printf("\n");
    }
    return 0;
}