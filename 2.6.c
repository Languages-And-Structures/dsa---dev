// Radix Sort — Digit-Wise Sorting

// Core Idea
// Radix Sort sorts numbers digit by digit, either from least
// significant digit (LSD) or most significant digit (MSD).
// At each digit, it uses a stable sort, typically Counting Sort.

// LSD Radix Sort is more common and easier to implement.

// Applicability
// Works only for data types where a "digit" can be extracted
// (e.g., integers, strings of fixed length).

// Ideal for:
//     Integers with bounded number of digits
//     Uniform-length strings
//     Large data sets where comparison-based sorts are too slow

// Parameter	        Meaning
// b	            Base of number system (e.g., 10 for decimal)
// d	            Max number of digits
// n	            Number of elements

// Metric	        Value	            Notes
// Time	    O(d × (n + b))	    Linear if d is constant
// Space	    O(n + b)	    Counting sort at each digit
// Stable?	    yes	            Required for correct digit pass
// In-place?	No              (needs output buffer)

// LSD Radix Sort Flow (Base 10, Integers)

// Extract the least significant digit of each number.
// Stable-sort all elements based on this digit (using Counting Sort).
// Repeat for next more significant digit, up to the most significant digit.
// After the final digit, array is sorted.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getMax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void countingSort(int arr[], int n, int exp)
{
    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--)
    {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixSort(int arr[], int n)
{
    int max = getMax(arr, n);

    for (int exp = 1; max / exp > 0; exp *= 10)
        countingSort(arr, n, exp);
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, n);

    radixSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}

// 1. Radix Choice Affects Performance
//         For base-10: 3–4 digit passes → O(3n)
//         For base-256 (bytes): fewer passes, but counting sort takes more memory.

// 2. Stable Sort Requirement
//         Each digit pass must use a stable sort (usually Counting Sort).
//         If not stable, the final result may be incorrect.

// 3. Handles Negative Numbers?
//         Not directly — you must preprocess:
//         Separate negatives and positives
//         Invert negatives → Radix sort → re-invert and recombine

// 4. Better for Fixed-Length Keys
//         Uniform strings, IDs, timestamps, IP addresses
//         Avoids overhead from variable digit sizes
