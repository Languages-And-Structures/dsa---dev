// Quick Sort — Divide and Conquer with Partitioning

// Core Idea:

// Choose a pivot.
// Partition the array such that:
//     Left of pivot → elements ≤ pivot
//     Right of pivot → elements > pivot
// Recursively sort both sides.

// It doesn't need merging like Merge Sort. Instead, it rearranges in-place.

//  Case	      Time	          Notes
// Best Case	O(n log n)	Balanced partitions
// Average	    O(n log n)	Random pivot or shuffled input
// Worst Case	O(n²)	    Pivot is smallest or largest repeatedly
// Space	    O(log n)	Due to recursion (O(n) worst if unbalanced)


// Why Is It So Fast?

// In-place: No extra arrays like Merge Sort → better cache behavior.
// Partitioning is local: High spatial locality.
// Adaptive (with good pivot choice): Can avoid worst-case in practice. 
// Used in the standard libraries of C++, Java (dual-pivot), Python (for small inputs inside TimSort).


// Partition Scheme – Lomuto (Simple and Popular)

// Process:
//     Choose last element as pivot.
//     Use a pointer i to track the boundary of values ≤ pivot.
//     Iterate j, and if arr[j] <= pivot, increment i and swap arr[i] and arr[j].
//     Finally, swap pivot with arr[i+1].


#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // pivot
    int i = low - 1;       // index of smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]); // place pivot at correct position
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}


// 1. Pivot Choice Matters
//     Worst case arises if array is already sorted.
//     Use random pivot, median-of-three, or median-of-medians for better balance.

// 2. Tail Call Optimization
//     Always recurse on the smaller half and iterate over the larger one to avoid stack overflow.

//           while (low < high) {
//              int pi = partition(arr, low, high);
//              if (pi - low < high - pi) {
//                  quickSort(arr, low, pi - 1);
//                  low = pi + 1;
//              } else {
//                  quickSort(arr, pi + 1, high);
//                  high = pi - 1;
//              }
//          }



