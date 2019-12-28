/** Name: exercise2.c 
 * Author: Devere A. Weaver 
 * Date started: 28 DEC 2019
 * Date of current version: 28 DEC 2019
 * Purpose: Practice with using pointer notation
 *          in functions with arrays in C.
 */

#include <stdio.h>
#define SIZE 5      

/* Function protoypes */
void copy_arr(double source[], double target[], int num_elements);
void copy_ptr(double source[], double target[], int num_elements);
void copy_ptrs(double source[], double target[], double last_element[]);

int main(void)
{
    double source[SIZE] = {1.0, 2.0, 3.0, 4.0, 5.0};   // original
    double t1[SIZE], t2[SIZE], t3[SIZE];               // used to hold copies of original

    // function calls 
    copy_arr(source, t1, SIZE);   
    copy_ptr(source, t2, SIZE);
    copy_ptrs(source, t3, source + SIZE);

    // print results of function calls 
    printf("Results after copy_addr():\n");
    printf("SOURCE ARRAY: \n");
    for (int i = 0; i < SIZE; i++)
        printf("%.1lf ", source[i]);
    putchar('\n');

    printf("\nT1 ARRAY: \n");
    for (int i = 0; i < SIZE; i++)
        printf("%.1lf ", t1[i]);
    putchar('\n');
    printf("*************************\n");

    printf("Results after copy_ptr():\n");
    printf("SOURCE ARRAY: \n");
    for (int i = 0; i < SIZE; i++)
        printf("%.1lf ", source[i]);
    putchar('\n');

    printf("\nT2 ARRAY: \n");
    for (int i = 0; i < SIZE; i++)
        printf("%.1lf ", t2[i]);
    putchar('\n');
    printf("*************************\n");

    printf("Results after copy_ptrs():\n");
    printf("SOURCE ARRAY: \n");
    for (int i = 0; i < SIZE; i++)
        printf("%.1lf ", source[i]);
    putchar('\n');

    printf("\nT3 ARRAY: \n");
    for (int i = 0; i < SIZE; i++)
        printf("%.1lf ", t3[i]);
    putchar('\n');

    return 0;
}

/* Functions */
void copy_arr(double source[], double target[], int num_elements)
{
    /** Function uses array notation to copy array elements from 
     * the source array to the target array.
     */
    for (int index = 0; index < num_elements; index++)
        target[index] = source[index];
}

void copy_ptr(double source[], double target[], int num_elements)
{
    /** Function uses pointer notation and pointer incrementation
     * to copy array elements from the source array to the target
     * array.
     */
    double * pts;   // declare two pointer-to-double variables for values in arrays
    double * ptt;

    /** Set the pointers to point to beginning of arrays. Execute until the element 
    * after the last element in the source array is reached. Increment both pointers 
    * by 1 to move them to the next element in the arrays. Set the values of the source
    * array equal to the values of the target array
    */
    for (pts = source, ptt = target; pts < source + num_elements; pts++, ptt++)
        *ptt = *pts;
}

void copy_ptrs(double source[], double target[], double last_element[])
{
    /** Function uses pointers to copy array elements from the source array
     * to the target array. Similiar to copy_ptr() function, but its last
     * argument is a pointer to the next element after the final element 
     * in the source array. In other words, it is one element past the end 
     * of the source array.
     */
    double * pts;   
    double * ptt;

    for (pts = source, ptt = target; pts < last_element; pts++, ptt++)
        *ptt = *pts;
}