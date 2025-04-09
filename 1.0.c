#include <stdio.h>

// An array is a collection of elements of the same data type, stored 
// in contiguous memory locations.
// It’s a way to group multiple values under one variable name and 
// access them using an index.

// You can also initialize it:
//     int numbers[5] = {10, 20, 30, 40, 50};
// Or let the compiler decide the size:
//     int numbers[] = {10, 20, 30, 40, 50};

// Accessing Elements
//     C uses zero-based indexing.
//     printf("%d", numbers[0]); // prints 10
// Modifying Elements
//     numbers[2] = 100;  // sets 3rd element to 100

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    
    return 0;
}
