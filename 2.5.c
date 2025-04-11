// Counting Sort

// Core Concept
// Counting Sort works on the idea of counting the number of occurrences
// of each element and then computing positions based on cumulative frequency.

// It’s not comparison-based. Instead, it relies on knowing the range and
// distribution of values.

// Precondition (Critical)
// Works only for integers within a known range (e.g., 0 to k).
// Suitable when k (the range of values) is not excessively larger than n.

// Algorithm Steps

// ->  Find max value (k) in input.
// ->  Allocate a count array of size k + 1.
// ->  Count the frequency of each element.
// ->  Modify count array to store prefix sums (cumulative positions).
// ->  Build output array using position from count array.
// ->  Copy back to original array (if in-place result needed).

// Metric	                Value
// Time Complexity	    O(n + k)
// Space Complexity	O(k + n)
// Stable?	            Yes
// In-place?	        No (uses extra space)

#include <stdio.h>
#include <string.h>

void countingSort(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];

    int count[max + 1];
    memset(count, 0, sizeof(count));

    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];

    int output[n];
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, n);

    countingSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}

// 1. Linear Time – But Not Always Practical
//         Only linear if k = O(n). If k >> n, it can be worse than O(n log n) sorts.

// 2. Highly Stable
//         Used in Radix Sort as the stable subroutine.

// 3. Poor Memory Efficiency
//         Needs O(k) extra space.
//         Not suitable if value range is huge or unbounded (e.g., floating points or strings).

// 4. Can Sort Negative Numbers
//         Just offset the entire array by abs(min).


// When range k is small and known.
// Input is only integers.
// Stability is needed (e.g., sort by digit, color codes, grades, etc.).
// Used internally in Radix Sort for digit-level sorting.

