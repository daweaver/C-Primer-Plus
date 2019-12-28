/**File: exercise3.c
 * Author: Devere A. Weaver
 * Date started: 28 DEC 2019 
 * Date of current version: 28 DEC 2019
 * Purpose: Practice using pointers with functions
 *          in the C programming langauge.
 */ 

#include <stdio.h>
#define SIZE 5
int get_largest(int source[], int arr_length);

int main(void)
{
    int source[SIZE] = {9000, 20, 3, 4, 5};
    printf("%d is the largest value is the array.\n", 
            get_largest(source, SIZE));

    return 0;
}

/* Function definitions */
int get_largest(int source[], int arr_length)
{
    /** Takes an array of integer value and returns 
     * the largest value. arr_length indicates the 
     * length of the source array. 
     */
    int largest = 0;
    int * ptr = source; 

    for (int i = 0; i < arr_length; i++, ptr++)
    {
        if (*ptr > largest)
            largest = *ptr;
    }
    
    return largest;
}