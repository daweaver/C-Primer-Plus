/** File name: printAsciiPairs.c 
 * 
 *  Author: Devere A. Weaver
 * 
 *  Date started: 7 DEC 2019
 * 
 *  Current version completed: 9 DEC 2019
 * 
 *  Purpose: Program reads characters from user input 
 *           and displays the charcter and it's ASCII 
 *           decimal value. 
*/

#include <stdio.h> 
#include <stdlib.h>
char charconvert(char ch);

int main(void)
{
    
    system("clear");        // *Nix specific function call

    int ch = 0;    // Character input 
    char charCount; // Keep track of characters input 
    int charInt = 0;    // Keep track of character ASCII decimal number value
    printf("Instructions: Type in a character and the program will\n");
    printf("return the character along with its equivalent ASCII decimal value.\n");

    printf("\nInput (press ^d to quit): ");
    while ( (ch = getchar()) != EOF)        // Execute until user inputs EOF signal 
    {    
       if (ch == 10)                      // Create a newline when return is entered
       {
           printf("\n\nInput (press ^d to quit): ");
           charCount = 0;                   // Reset character count to 0
           continue;                        // Jump back up to top of loop to get user input
        }
        else if (ch == 9)                   // If char is a tab (\t), print \t instead
            printf("\\t ");
        else if ((ch >= 0 && ch < 9) || (ch > 10 && ch < 32))
        {
            charInt = ch;                   // Save ch to charInt to save its decimal before converting
            ch = charconvert(ch);           // Convert ch to a printing character value
            printf("|^%c = %d| ", ch, charInt);     // Print the char's control character notation
        }     
        else 
            printf("|%c = %d| ", ch, ch);  // Print user input as character and it's ASCII decimal value 
        charCount++;                       // Increment charCount to keep track of 10 characters 
        if (charCount == 10)
        {
            charCount = 0;                  // Reset charCount to 0 when charCount reaches 10
            putchar('\n');                  // Create a newline when charCount reaches 10 
        } 
    }        
    
    printf("\n\nGood bye.\n");
    return 0;
}

char charconvert(char ch){
    /** Function takes a nonprinting character, compares 
     *  it's ASCII decimal number to a switchcase, and then
     *  matches the ASCII decimal number to corresponding 
     *  printing character. (Ex: if user ch input is nonprinting character
     *  such as '^A', then printing character 'A' is returned to main function
     *  to print out.) 
     */

    char returnChar;

    switch (ch)
    {
    case 1:
        returnChar = 'A';
        break;
    case 2:
        returnChar = 'B';
        break;
    case 5:
        returnChar = 'E';
        break;    
    case 6:
        returnChar = 'F';
        break;
    case 7:
        returnChar = 'G';
        break;
    case 8:
        returnChar = 'H';
        break;
    case 11:
        returnChar = 'K';
        break;
    case 12:
        returnChar = 'L';
        break;
    case 14:
        returnChar = 'N';
        break;
    case 15:
        returnChar = 'O';
        break;
    case 16:
        returnChar = 'P';
        break;
    case 20:
        returnChar = 'T';
        break;
    case 24:
        returnChar = 'X';
        break;
    case 25:
        returnChar = 'Y';
        break;
    case 27:
        returnChar = '[';
        break;
    case 29:
        returnChar = ']';
        break;
    case 30:
        returnChar = '^';
        break;
    case 31:
        returnChar = '_';
        break;
    default:
        break;
    }    
    return returnChar;   
}