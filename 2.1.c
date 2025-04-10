// Selection Sort

// Selection Sort divides the array into two parts:
//      Sorted (initially empty)
//      Unsorted (initially the full array)
// In every iteration, it:
//      Finds the minimum element in the unsorted part.
//      Swaps it with the first element of the unsorted part.
// This way, the smallest values get selected and placed at their final
// position one by one — hence the name.

// For array: [29, 10, 14, 37, 13]

// Pass 1
// Find min in [29, 10, 14, 37, 13] → 10

// Swap 10 with 29 → [10, 29, 14, 37, 13]

// Pass 2
// Find min in [29, 14, 37, 13] → 13

// Swap 13 with 29 → [10, 13, 14, 37, 29]

// And so on...

// Time & Space Complexity

// Case        Time	        Notes
// Best Case	O(n²)	Still does full scan every time
// Worst Case	O(n²)	No early exit optimization
// Space	    O(1)	In-place, no extra memory

// Unlike Bubble Sort, Selection Sort minimizes swaps — only one per outer iteration
// (best for systems where write operations are costly, like EEPROM).

// Total swaps = n - 1, regardless of array order.

// Not adaptive: Doesn’t benefit from pre-sorted input.
// Unstable: May change the order of equal elements.

// In-place sorting: Doesn’t need extra memory.
// Non-adaptive: Performs the same number of operations regardless of input state.
// Unstable: Could swap equal elements, changing relative order.
// Cache inefficiency: Access pattern jumps around the array. Poor locality of reference.
// Write-intensive systems: Fewer swaps make it better than bubble sort when minimizing
//                         writes is critical (e.g., flash memory).
// Selection sort is selection-heavy: Requires frequent comparisons, but fewer writes.

#include <stdio.h>

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIdx = i;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIdx])
            {
                minIdx = j;
            }
        }

        if (minIdx != i)
        {
            int temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;
        }
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
    int arr[] = {29, 10, 14, 37, 13};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, n);

    selectionSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}

// Sorting small datasets where code clarity matters.
// Write-limited memory (flash, EEPROM, etc.).
// Embedded systems with memory constraints.

