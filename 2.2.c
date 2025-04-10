// Merge Sort — Divide and Conquer

// Merge Sort uses the Divide and Conquer strategy:

// Divide: Recursively split the array into two halves until each subarray contains one element.
// Conquer: Recursively sort the subarrays.
// Combine: Merge the sorted subarrays into a single sorted array.

//     Property	                   Description

// Time Complexity	        O(n log n) in all cases (best, avg, worst)
// Space Complexity        O(n) — extra memory required for merging
// Stability	            Yes (equal elements retain order)
// Adaptive	            No (ignores existing order)
// Recursive	            Yes — uses the call stack or explicit stack
// Cache-friendly          Poor — scattered access during merging

//   Why It's Efficient
// Always splits the array into log₂(n) levels.
// Merging each level takes O(n).
// Total time = O(n log n) regardless of input distribution.

// Internal Working

// For array: [38, 27, 43, 3, 9, 82, 10]

// 1. Divide
// Split until you get:
// [38] [27] [43] [3] [9] [82] [10]

// 2. Conquer + Combine
// Merge adjacent sorted arrays:
// [27, 38], [3, 43], [9, 82], [10]
// → [3, 27, 38, 43], [9, 10, 82]
// → [3, 9, 10, 27, 38, 43, 82]

#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];

    free(L);
    free(R);
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, size);

    mergeSort(arr, 0, size - 1);

    printf("Sorted array:\n");
    printArray(arr, size);

    return 0;
}


// Tail Recursion
// Merge Sort isn’t tail-recursive → can’t optimize via tail-call elimination.

// Bottom-Up Merge Sort (Iterative)

// Avoids recursion entirely.
// Starts with subarrays of size 1 and merges iteratively.
// Better control over stack usage.

// Memory Management

// Uses O(n) extra space.
// Poor fit for memory-constrained environments unless an in-place merge 
// is implemented (which is non-trivial and rarely worth it in practice).


// Used in stable systems where ordering of duplicates matters.
// Ideal for linked lists: no need for extra space — merging is O(1) in-place.
// Base sort in TimSort (used by Python, Java) when dataset is partially sorted.
