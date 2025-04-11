// Bucket Sort — Distribution-Based Sorting

// Core Idea
//     Distribute elements into buckets based on value ranges.
//     Sort each bucket individually (usually with Insertion Sort or Quick Sort).
//     Concatenate all buckets for the final sorted array.

// Think of this as distribution sort: exploit known distribution to avoid
// unnecessary comparisons.

// Assumptions (Where It Shines)
//     Input is real numbers (floats) or uniformly spread integers.
//     Values are within a known bounded interval (e.g., 0 to 1).
//     Works best when input is evenly spread — this keeps buckets balanced.

// Algorithm Steps
//     Create n empty buckets (number depends on data distribution).
//     Distribute elements into appropriate buckets using a bucket index function.
//     Sort each bucket individually (often using Insertion Sort for small subarrays).
//     Concatenate buckets.

// Time and Space Complexity

//   Metric	             Value	            Notes
// Best Case	        O(n + k)	Perfect distribution, light sorting
// Average Case	        O(n + k)	With uniform distribution
// Worst Case	        O(n²)	    If all fall into one bucket
// Space Complexity	    O(n + k)	For buckets
// Stable?	            Yes         (if sub-sort is)
// In-place?	        No          (uses buckets)

#include <stdio.h>
#include <stdlib.h>

#define N 10

void insertionSort(float arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        float key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void bucketSort(float arr[], int n)
{

    float *buckets[n];
    int count[n];

    for (int i = 0; i < n; i++)
    {
        buckets[i] = (float *)malloc(n * sizeof(float));
        count[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        int index = (int)(arr[i] * n);
        buckets[index][count[index]++] = arr[i];
    }

    for (int i = 0; i < n; i++)
        insertionSort(buckets[i], count[i]);

    int idx = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < count[i]; j++)
            arr[idx++] = buckets[i][j];

    for (int i = 0; i < n; i++)
        free(buckets[i]);
}

void printArray(float arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%.2f ", arr[i]);
    printf("\n");
}

int main()
{
    float arr[N] = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};
    printf("Original array:\n");
    printArray(arr, N);

    bucketSort(arr, N);

    printf("Sorted array:\n");
    printArray(arr, N);

    return 0;
}


// 1. Bucket Index Function is Crucial
//     ->For inputs in [0, 1), index = floor(n × value).
//     ->For range [a, b), normalize: index = floor(n × (val - a) / (b - a)).

// 2. Small Buckets = Use Insertion Sort
//     ->or small, almost-sorted arrays, Insertion Sort is cache-efficient and fast.

// 3. Can Generalize to Integers
//     ->Use hashing or range partitioning to map into buckets.

// 4. When It Fails
//     ->If input is not uniformly distributed, you'll get skewed buckets and 
//     ->degrade to O(n²).


// Input is floating point numbers, bounded, and uniformly distributed.
// You care about linear performance in practice.
// Input size is large, and performance of O(n log n) is not enough.

