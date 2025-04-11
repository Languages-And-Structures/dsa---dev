// Heap Sort — Heap + Selection Principle

// Core Concept
// Heap Sort is based on the binary heap data structure, specifically a max heap:
//     A max heap maintains the property: every parent node ≥ its children.
//     The largest element is always at the root.

// Algorithm Steps

// Build a max heap from the input array.
// Repeat:
//     Swap the first element (max) with the last element.
//     Reduce the heap size by 1 (exclude the last element).
//     Heapify the new root to restore max heap property.

//  Case	       Time	                    Notes
// Best	        O(n log n)	        Always log-time per removal
// Average	    O(n log n)
// Worst	    O(n log n)	        Predictable, no bad pivot cases
// Space	    O(1)	            In-place, no auxiliary arrays
// Stable	    No	                Order of duplicates may change

// Binary Heap Representation

// A heap is typically stored in an array (not a tree). For any index i:
//         Left child → 2*i + 1
//         Right child → 2*i + 2
//         Parent → (i - 1) / 2

// Efficient indexing allows for fast traversal and manipulation.

#include <stdio.h>

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
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
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, n);

    heapSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}

// 1. Heap Building is Linear Time
//         Though heapify() is O(log n), building the heap is O(n).
//         This is because lower levels (closer to leaves) are faster to fix —
//              the amortized cost adds up to O(n).

// 2. Not Stable
//         Swapping during heapify may rearrange equal elements arbitrarily.

// 3. In-place
//         Uses the input array as both the heap and final sorted storage.
//         More memory efficient than Merge Sort.

// 4. Cache-inefficient
//         Jumping from node to child breaks spatial locality.
//         Slower in practice than Quick Sort due to poor cache performance.

// When worst-case time guarantees are critical (e.g., real-time systems).
// When auxiliary memory is severely limited.
// When stability is not needed.
