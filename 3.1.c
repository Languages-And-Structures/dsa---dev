// What is Time Complexity?

// Time complexity is a formal way of expressing how the running time of an algorithm grows 
// with the size of the input (n). It answers:

// “As the input grows, how much more time (steps or operations) will my algorithm take?”

// We usually express it using :
//         -  Big O notation (worst-case)
//         -  sometimes Θ (average-case)
//         -  Ω (best-case)

// Time Complexity Is About Growth Rate, Not Actual Time
// You're not measuring “seconds” but steps/instructions/operations executed as n increases.

// For example:

// Statement	                            Cost

// int x = 5;	                            O(1)
// for (int i = 0; i < n; i++)	            O(n)
// Nested loops: for i, for j	            O(n²)
// Recursion dividing input in half	    O(log n)


// Types of Time Complexities
// some common complexities:

// Complexity              Name	                                Meaning
// O(1)	            Constant time	        Doesn't grow with input. Eg, accessing an array index
// O(log n)	        Logarithmic	Cuts        input size in half each time. Eg, binary search
// O(n)	            Linear	                Grows directly with n. eg, traversing a list
// O(n log n)	    Linearithmic	        Sorting best-case (merge sort, quick sort avg)
// O(n²)	        Quadratic	            Double loops. eg, bubble sort, selection sort
// O(2ⁿ)	        Exponential	            Bruteforce recursion (eg, traveling salesman)
// O(n!)	        Factorial	            All permutations. eg, recursive brute-force sorting


// What Actually Counts in "Time"?
// We measure significant operations: comparisons, swaps, arithmetic, recursive calls, etc.

// In sorting:
// ->  Bubble sort: count of comparisons and swaps
// ->  Merge sort: count of divides + merges
// ->  Binary search: log₂(n) comparisons

// In arrays:
// ->  Accessing arr[i] → O(1) (direct address)
// ->  Searching for a value (linear search) → O(n)

// Time Complexity Importance 

// It lets you:
// Predict behavior for huge inputs (n = 10⁶ or 10⁹)
// Compare algorithms abstractly (independent of hardware)
// Avoid performance traps in scaling

// Common Traps and Misconceptions

// Misconception	                                Reality
// O(n log n)                      is always better than O(n²)	True only for large n. For 
//                                 small n, constants matter.
// O(n)                            is always optimal	Not if the data has structure (eg, 
//                                 sorted — use binary search)
// Recursion is always slower	    Depends. With memoization or divide-and-conquer, it can be 
//                                 fast.


// Time Complexity in Practice

// Let’s compare sorting 1,000,000 integers:

// Sort Algorithm	Time Complexity	        Est. Ops
// Bubble Sort	        O(n²)	        ~10¹² ops → impractical
// Merge Sort	        O(n log n)	    ~20 million ops
// Quick Sort	        O(n log n)avg	~20 million ops
// Counting Sort	    O(n + k)	    Linear for integers

// So, time complexity gives you upper bounds on algorithm cost, letting you avoid catastrophic 
// slowdowns as n increases.

// It’s not about the exact time but how the algorithm scales with input size.

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

// Swap function
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Trace version of Bubble Sort
void bubbleSortTrace(int arr[], int n) {
    int compCount = 0, swapCount = 0;

    printf("Initial array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n\n");

    for (int i = 0; i < n - 1; i++) {
        printf("Pass %d:\n", i + 1);
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            compCount++;
            printf("  Comparing arr[%d]=%d and arr[%d]=%d\n", j, arr[j], j+1, arr[j+1]);
            if (arr[j] > arr[j + 1]) {
                printf("  -> Swapping %d and %d\n", arr[j], arr[j + 1]);
                swap(&arr[j], &arr[j + 1]);
                swapCount++;
                swapped = 1;
            }
        }
        printf("  Array after pass: ");
        for (int k = 0; k < n; k++) printf("%d ", arr[k]);
        printf("\n\n");
        if (!swapped) {
            printf("No swaps in this pass → early exit.\n");
            break;
        }
    }

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    printf("Total comparisons: %d\n", compCount);
    printf("Total swaps: %d\n", swapCount);
}

int main() {
    int arr[SIZE] = {64, 25, 12, 22, 11, 7, 55, 18, 9, 33};

    bubbleSortTrace(arr, SIZE);

    return 0;
}

