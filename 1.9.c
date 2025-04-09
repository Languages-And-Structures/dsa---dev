// Bubble Sort

// Bubble Sort repeatedly steps through the array, compares adjacent elements,
// and swaps them if they’re in the wrong order. This process is repeated
// until the array is sorted.

// How it works
//    In each pass:
//      Compare adjacent elements.
//      Swap if left > right.
//      Largest element "bubbles up" to the end.

#include <stdio.h>

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int swapped = 0; // Optimization flag
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        // If no elements were swapped, the array is sorted
        if (!swapped)
            break;
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, n);

    bubbleSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}

// Efficiency Trick – Early Exit
// If no swaps happen in a full pass, we can exit early.
// This makes Bubble Sort adaptive — efficient on already/
// almost sorted arrays.

// That's why the swapped flag is used.

// Stable Sort
// If two elements are equal, Bubble Sort does not swap them,
// keeping their relative order.

// When Not to Use
//   Large datasets
//   Time-critical systems
//   When better algorithms like Merge Sort, Quick Sort, or
//   Heap Sort are available
