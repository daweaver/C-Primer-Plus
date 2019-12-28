#include <stdio.h>

int main(void)
{
    int rain[2][5] = 
    {
        {1, 89, 3, 4, 5},
        {6, 7, 8, 9, 10}
    };

    int (*ptr)[5];

    ptr = rain;

    // printf("Value of ptr = %d\n", **ptr);
    // printf("Value of rain[0][1] = %d\n", *(*(ptr) + 1));
    // printf("Value of rain[1][3] = %d\n", *(*(ptr + 1) + 3));
    
    // Add rain[0][0] and rain[1][0] to get a value of 6
    int val1 ,val2, sum;
    val1 = **ptr;   // rain[0][0]
    val2 = *(*(ptr + 1));   // rain[1][0]
    printf("val1 = %d\n", val1);
    printf("val2 = %d\n", val2);
    printf("val1 + val2 = %d\n", val1 + val2);

    return 0;
}