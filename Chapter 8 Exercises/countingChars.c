/** File name: countingChars.c
 * 
 *  Author: Devere A. Weaver
 * 
 *  Date started: 9 DEC 2019
 * 
 *  Current version completed: 9 DEC 2019
 * 
 *  Purpose: Read user input and report the number 
 *           of lowercase, uppercase, and "other"
 *           characters. 
 */

#include <stdio.h>
#include <ctype.h>

int main(void)
{
    // Variable declarations
        int ch;         // User input variable (int for EOF)
        int alphaCount = 0; // Alpha count 
        int upperCount = 0; // Uppercase count 
        int lowerCount = 0; // Lowercase count
        int otherCount = 0; // Other count
        int totalCount = 0; // Count all characters entered

    while ((ch = getchar()) != EOF)     // Read user input until EOF
    {
        if (isalpha(ch))        // Check if ch is an alphabet character
        {
            alphaCount++;       // Increment the total count of alphabet characters
            if (islower(ch))    // Check if ch is lowercase
                lowerCount++;
            else                // Ch is uppoercase
                upperCount++;
        }
        else                    // Increment count of other characters
            otherCount++;  
    } 
    printf("\n**** Summary of Characters ****\n");
    printf("Total alphabet characters enters: %d\n", alphaCount);
    printf("Total lowercase characters entered: %d\n", lowerCount);
    printf("Total uppercase characters entered: %d\n", upperCount);
    printf("Total other characters entered: %d\n", otherCount);

    return 0;
}