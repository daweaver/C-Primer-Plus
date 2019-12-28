/**File: 1.c
 * Author: Devere A. Weaver
 * Date started: 25 Dec 2019
 * Date of current version: 28 Dec 2019
 * Purpose: Practice with pointers; Modify 10.7 so it 
 *          does the calculations using pointers 
 *          instead of subscripts. (You still have to 
 *          declare and initalize the array)
 */

/* NOTE: This could be substancially improved, possibly
*  using 2 pointers (one for the year (arrays) and one for the months (colums)),
*  but this is my first attempt using pointers in a program and this 
*  seemed to make the most sense at the time of writing.
*/

#include <stdio.h> 
#define MONTHS 12   // number of months in a year
#define YEARS 5     // number of years of data

int main(void)
{
    // initializing rainfall data for 2010-2014
    const float rain[YEARS][MONTHS] =           // 2d array, 5x12
    {   
        {4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6},      // 2010
        {8.5,8.2,1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3},
        {9.1,8.5,6.7,4.3,2.1,0.8,0.2,0.2,1.1,2.3,6.1,8.4},
        {7.2,9.9,8.4,3.3,1.2,0.8,0.4,0.0,0.6,1.7,4.3,6.2},
        {7.6,5.6,3.8,2.8,3.8,0.2,0.0,0.0,0.0,1.3,2.6,5.2}       // 2014
    };

    int year, month;
    float subtot, total = 0;          // don't forget to initialize or total will be a random value
    const float (* ptfa)[MONTHS];     // pointer to a constant array of 12 floats
    ptfa = rain;                      // assing ptfa to point to first array of rain

    /* Calculate the yearly rainfall averages */
    printf(" YEAR  RAINFALL (inches)\n");
    for (int year = 0; year < YEARS; year++)
    {
        subtot = 0;
        for (int month = 0; month < MONTHS; month++)    // Print off each element in first array of rain and add each year's values together
            subtot += *(*(ptfa + year) + month);    // traverse first array and add each value to subtotal
        printf("%5.4d: %5.1f\n", 2010 + year, subtot);  // print off subtotal
        total += subtot;        
    }
    printf("\nTotal rainfall: %.1f inches\n", total);
    printf("The yearly average is %.1f inches.\n\n", total/YEARS);

    /* Calculate the monthly rain averages across years */
    printf("MONTHLY AVERAGES:\n");
    printf("Jan | Feb | Mar | Apr | May | Jun | Jul | Aug | Sep | Oct | Nov | Dec |\n");
    for (month = 0; month < MONTHS; month++)
    {
        subtot = 0;
        for (year = 0; year < YEARS; year++)
        {
            subtot += *(*(ptfa + year) + month);  
        }
        printf("%3.1f | ", subtot/YEARS);    
    }
    putchar('\n');

    return 0;
}