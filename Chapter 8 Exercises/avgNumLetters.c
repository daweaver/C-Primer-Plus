/** File name: avgNumLetters.c
 * 
 *  Author: Devere A. Weaver
 *  
 *  Date started: 9 DEC 2019
 * 
 *  Current version completed:
 * 
 *  Purpose: Program calculates the average number of 
 *           letters per word based on input. It doesn't
 *           count whitespace and punctuation as letters.
 */

/* TO DO: Figure out a better way to calculate what is a word, if it exists. */

#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int ch;          
    float  average = 0;     // Average number of letters 
    int totalLetters = 0;   // Total number of letters input
    int totalPunct = 0;     // Total number of punctutation marks 
    int totalWhite = 0;     // Total number of whitespaces 

    while ((ch = getchar()) != EOF) 
    {
        if (isalpha(ch))        // Test if character is a letter
            totalLetters++;
        if (isspace(ch))        // Test if character is a space
            totalWhite++;
        if (ispunct(ch))        // Test if character is punctuation mark
            totalPunct++;
    }
    average = (float)totalLetters / totalWhite;
    printf("\n**** Summary ****\n");
    printf("Average number of letters per word: %.2f\n", average);
    printf("Total number of letters: %d\n", totalLetters);
    printf("Total number of word: %d\n", totalWhite);
    printf("Total number of punctuation marks: %d\n", totalPunct);
    printf("Total number of whitespaces: %d\n", totalWhite - 1);

    return 0;
}