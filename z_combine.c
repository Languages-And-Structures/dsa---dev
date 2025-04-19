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

#include <stdio.h>

// Traversing an Array

int main() {
    int arr[5] = {10, 20, 30, 40, 50};

    for (int i = 0; i < 5; i++) {
        printf("Element at index %d: %d\n", i, arr[i]);
    }

    return 0;
}

// Inserting an Element (at a Position)

#include <stdio.h>

int main() {
    int arr[6] = {10, 20, 30, 40, 50};
    int n = 5;  // current number of elements
    int pos = 2; // index where to insert
    int value = 25;

    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos] = value;
    n++;

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}


#include <stdio.h>

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int n = 5;
    int pos = 2; // index to delete

    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    n--;

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

// Searching in an Array (Linear Search)

#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = 5, key = 30;
    int found = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("Element found at index %d\n", i);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Element not found\n");

    return 0;
}

// Advantages
//     Fast access via index.
//     Easy to implement.

// Limitations
//     Fixed size.
//     Insertion/deletion is costly (O(n)).
//     Homogeneous (same data type).


// A 2D array is like a matrix with rows and columns. 
// It’s essentially an array of arrays.

// Accessing Elements
// matrix[0][2];  // 1st row, 3rd column → value = 3

// Traversing a 2D Array

#include <stdio.h>

int main() {
    int matrix[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}

// Multidimensional Arrays (3D and beyond)

// Accessing
// cube[0][1][1];  // accesses value = 4

// Traversing

// for (int i = 0; i < 2; i++) {
//     for (int j = 0; j < 3; j++) {
//         for (int k = 0; k < 4; k++) {
//             printf("%d ", cube[i][j][k]);
//         }
//     }
// }



int main() {
    int rows = 2, cols = 3;
    int **matrix;

    matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    // Assign values
    int val = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = val++;
        }
    }

    // Print matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Free memory
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}

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


// Insertion Sort

// Insertion Sort mimics how we sort playing cards by hand:
//      Take the next unsorted element.
//      Insert it into its correct position in the sorted part of the array.
//      Shift elements to the right to make space if needed.
//      This leads to partial sortedness growing with each iteration.

// Complexity Profile

//    Case	        Time	            Notes
// Best Case	    O(n)	Already sorted — linear comparisons only
// Average 	        O(n²)	Quadratic due to nested loops
// Worst Case  	    O(n²)	Reverse sorted — every insert moves n elements
// Space	        O(1)	In-place, stable


// Stable:          Maintains relative order of equal elements.
// Adaptive:        Performs better on nearly-sorted data.
// Cache-friendly:  Access pattern is linear → good spatial locality.

// Not suitable for large arrays due to quadratic time.


// 1. Fewer Moves than Bubble Sort
//      Bubble sort can do many swaps per pass.
//      Insertion Sort shifts elements (faster in memory due to reduced writes).

// 2. Efficient for Nearly-Sorted Input
//      Only checks until the correct spot is found.
//      On sorted or almost-sorted input, it runs in near O(n) time.

// 3. Real-world use
//      Often used as the base case sort in hybrid algorithms (e.g., TimSort, Introsort) when subarray size ≤ 16.

#include <stdio.h>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];  
            j--;
        }

        arr[j + 1] = key;  
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {9, 5, 1, 4, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, n);

    insertionSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}

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


// Merge Sort — Divide and Conquer

// Merge Sort uses the Divide and Conquer strategy:

// Divide: Recursively split the array into two halves until each subarray contains one element.
// Conquer: Recursively sort the subarrays.
// Combine: Merge the sorted subarrays into a single sorted array.

//     Property	                   Description

// Time Complexity	        O(n log n)  in all cases (best, avg, worst)
// Space Complexity         O(n)        extra memory required for merging
// Stability	            Yes         (equal elements retain order)
// Adaptive	                No (        ignores existing order)
// Recursive	            Yes         uses the call stack or explicit stack
// Cache-friendly           Poor        scattered access during merging

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

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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

void countingSortR(int arr[], int n, int exp)
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
    
    for (int i = 1; max / i > 0; i *= 10)
        countingSortR(arr, n , i);
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


// 1. Linear Search — Brute Force

// Approach: Start from the first element, check each element against the key.
// No assumptions about the data structure (unsorted/duplicates/anything).

int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1; 
}


// When is it Good?
//     ->  Small arrays — performance difference is negligible.
//     ->  One-time or ad-hoc search — saves sort time.
//     ->  Data is too dynamic — sorting is costly.

// When is it Bad?
//     ->  Time complexity is O(n) even for simple queries.
//     ->  Does not scale to large datasets.
//     ->  Frequent queries → better alternatives needed (like hashing 
//                            or binary search).

// Sentinel Linear Search: Avoids checking bounds at each iteration 
// (saves 1 comparison per iteration).

int sentinelSearch(int arr[], int n, int key) {
    int last = arr[n - 1];
    arr[n - 1] = key; 

    int i = 0;
    while (arr[i] != key)
        i++;

    arr[n - 1] = last; 

    if (i < n - 1 || arr[n - 1] == key)
        return i;
    return -1;
}

// Early Exit with Access Pattern: If keys are often near the start, 
// this is actually better than binary search on large arrays.

// Linear Search suite

//   ->  Standard linear search
//   ->  Linear search with duplicate handling (first and last occurrence)
//   ->  Sentinel linear search (optimized)
//   ->  Recursive linear search (for theoretical completeness)
//   ->  Comparator-free search pattern for struct types (prepping you for more generic design)

#include <stdio.h>

// Standard linear search — returns any index of the key
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++)
        if (arr[i] == key)
            return i;
    return -1;
}

// Linear search (first occurrence) — same as standard
int linearSearchFirst(int arr[], int n, int key) {
    return linearSearch(arr, n, key);  // Alias
}

// Linear search — last occurrence
int linearSearchLast(int arr[], int n, int key) {
    int result = -1;
    for (int i = 0; i < n; i++)
        if (arr[i] == key)
            result = i;
    return result;
}

// Sentinel linear search — optimized, fewer comparisons
int sentinelLinearSearch(int arr[], int n, int key) {
    int last = arr[n - 1];
    arr[n - 1] = key;  // Inject sentinel

    int i = 0;
    while (arr[i] != key)
        i++;

    arr[n - 1] = last;  // Restore original

    if (i < n - 1 || arr[n - 1] == key)
        return i;
    return -1;
}

// Recursive linear search
int linearSearchRecursive(int arr[], int i, int n, int key) {
    if (i >= n) return -1;
    if (arr[i] == key) return i;
    return linearSearchRecursive(arr, i + 1, n, key);
}

// Comparator-based (struct or pointer support) — forward compatible
int linearSearchCmp(const void *base, int n, int size,
                    const void *key,
                    int (*cmp)(const void *, const void *)) {
    for (int i = 0; i < n; i++) {
        const void *element = (const char *)base + i * size;
        if (cmp(element, key) == 0)
            return i;
    }
    return -1;
}

// Example comparator for integers
int intCmp(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    return (x > y) - (x < y);  // 0 if equal
}

// Driver
int main() {
    int arr[] = {5, 3, 7, 3, 9, 1, 3, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 3;

    printf("Standard Linear Search: %d\n", linearSearch(arr, n, key));
    printf("First Occurrence: %d\n", linearSearchFirst(arr, n, key));
    printf("Last Occurrence: %d\n", linearSearchLast(arr, n, key));
    printf("Sentinel Linear Search: %d\n", sentinelLinearSearch(arr, n, key));
    printf("Recursive Linear Search: %d\n", linearSearchRecursive(arr, 0, n, key));
    printf("Comparator-based Linear Search: %d\n", linearSearchCmp(arr, n, sizeof(int), &key, intCmp));

    return 0;
}


//Binary Search — Divide and Conquer (Logarithmic) 

// Binary Search reduces the search space by half with every iteration:
//     -Access mid = (low + high) / 2
//     -Eliminate half depending on comparison
//     -Repeat

// Works only on monotonically sorted arrays (ascending or descending)

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2; // safer
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

// *** Prevent Integer Overflow ***
// int mid = low + (high - low) / 2;
// Avoids overflow that can happen with (low + high) / 2 when integers are large (> 2^30).


//         Situation	                           Should you use Binary Search?
// Array sorted and static	                            Absolutely
// Frequently searched	                                Efficient
// Dynamic inserts/removals	                        Use balanced trees instead
// Random access not available (e.g., linked list)     Binary search breaks


// 1. Find First Occurrence: Continue search in the left half after a match.

// if (arr[mid] == key) {
//     result = mid;
//     high = mid - 1;
// }

// 2. Find Last Occurrence: Continue in the right half.

// if (arr[mid] == key) {
//     result = mid;
//     low = mid + 1;
// }

// 2. Binary Search in Descending Array: Reverse the comparison signs:

// if (arr[mid] > key)  // go right
// else if (arr[mid] < key) // go left

// Binary Search beats Linear Search only when n is large enough (say, >30).
// For very small arrays (esp. <10), Linear Search can be faster in practice due to branch misprediction and fewer instructions.

#include <stdio.h>

// Detect whether the array is ascending or descending
int isAscending(int arr[], int n) {
    return arr[0] < arr[n - 1];
}

// Standard binary search — returns any index of key
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    int asc = isAscending(arr, n);

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;

        if (asc) {
            if (arr[mid] < key)
                low = mid + 1;
            else
                high = mid - 1;
        } else {
            if (arr[mid] > key)
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1;
}

// Recursive version
int binarySearchRecursive(int arr[], int low, int high, int key, int asc) {
    if (low > high) return -1;

    int mid = low + (high - low) / 2;

    if (arr[mid] == key)
        return mid;

    if (asc) {
        if (arr[mid] < key)
            return binarySearchRecursive(arr, mid + 1, high, key, asc);
        else
            return binarySearchRecursive(arr, low, mid - 1, key, asc);
    } else {
        if (arr[mid] > key)
            return binarySearchRecursive(arr, mid + 1, high, key, asc);
        else
            return binarySearchRecursive(arr, low, mid - 1, key, asc);
    }
}

// Find first occurrence of key
int binarySearchFirst(int arr[], int n, int key) {
    int low = 0, high = n - 1, result = -1;
    int asc = isAscending(arr, n);

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            result = mid;
            high = mid - 1; // move left
        } else if (asc ? (arr[mid] < key) : (arr[mid] > key)) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return result;
}

// Find last occurrence of key
int binarySearchLast(int arr[], int n, int key) {
    int low = 0, high = n - 1, result = -1;
    int asc = isAscending(arr, n);

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            result = mid;
            low = mid + 1; // move right
        } else if (asc ? (arr[mid] < key) : (arr[mid] > key)) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return result;
}

// Driver
int main() {
    int ascArr[] = {1, 2, 4, 4, 4, 5, 6, 8};
    int descArr[] = {9, 7, 5, 4, 4, 4, 2, 1};
    int n = sizeof(ascArr) / sizeof(ascArr[0]);
    int key = 4;

    printf("Standard Binary Search (ascending): %d\n", binarySearch(ascArr, n, key));
    printf("Recursive Binary Search (ascending): %d\n", binarySearchRecursive(ascArr, 0, n - 1, key, 1));
    printf("First occurrence (ascending): %d\n", binarySearchFirst(ascArr, n, key));
    printf("Last occurrence (ascending): %d\n", binarySearchLast(ascArr, n, key));

    printf("\nStandard Binary Search (descending): %d\n", binarySearch(descArr, n, key));
    printf("Recursive Binary Search (descending): %d\n", binarySearchRecursive(descArr, 0, n - 1, key, 0));
    printf("First occurrence (descending): %d\n", binarySearchFirst(descArr, n, key));
    printf("Last occurrence (descending): %d\n", binarySearchLast(descArr, n, key));

    return 0;
}


// traces for various sorts

// 1. Bubble Sort 

// Pass 1:
// [5, 1, 4, 2, 8]  →  compare 5,1 → swap → [1, 5, 4, 2, 8]
// [1, 5, 4, 2, 8]  →  compare 5,4 → swap → [1, 4, 5, 2, 8]
// [1, 4, 5, 2, 8]  →  compare 5,2 → swap → [1, 4, 2, 5, 8]
// [1, 4, 2, 5, 8]  →  compare 5,8 → no swap

// Pass 2:
// [1, 4, 2, 5, 8]  →  compare 1,4 → no swap
// [1, 4, 2, 5, 8]  →  compare 4,2 → swap → [1, 2, 4, 5, 8]
// [1, 2, 4, 5, 8]  →  compare 4,5 → no swap

// Pass 3:
// [1, 2, 4, 5, 8]  →  compare 1,2 → no swap
// [1, 2, 4, 5, 8]  →  compare 2,4 → no swap

// Pass 4:
// Already sorted → no swaps → early exit


// Notes:
//   ->  Worst-case: O(n²)
//   ->  Best-case with optimization: O(n) (if no swaps in a pass)
//   ->  Adaptive


// Detailed Mechanics:
// ->  Compares adjacent pairs and bubbles up the largest element to the end 
//     in each pass.
// ->  The inner loop gets shorter every time (n - i - 1), but...
// ->  Many redundant comparisons even on sorted or nearly-sorted data.

// Micro-Optimizations:
// ->  Early exit flag: If no swaps in a pass, exit — makes it adaptive.
// ->  Boundary tracking: Instead of looping till n - i - 1, track last swap
//     index to avoid unneeded comparisons.

int bubbleSort(int arr[], int n) {
    int swapped, newn;
    do {
        swapped = 0;
        newn = 0;
        for (int i = 1; i < n; i++) {
            if (arr[i - 1] > arr[i]) {
                swap(&arr[i - 1], &arr[i]);
                swapped = 1;
                newn = i;
            }
        }
        n = newn;
    } while (swapped);
}

// Edge Cases:
// Already sorted: O(n)
// Reversed      : O(n²), max swaps


// 2. Selection Sort
// Array: [5, 1, 4, 2, 8]

// Pass 1:
// Find min from index 0 to 4 → 1 → swap with index 0
// → [1, 5, 4, 2, 8]

// Pass 2:
// Find min from index 1 to 4 → 2 → swap with index 1
// → [1, 2, 4, 5, 8]

// Pass 3:
// Min at index 2 → already 4 → no swap
// → [1, 2, 4, 5, 8]

// Pass 4:
// Min at index 3 → already 5 → no swap


// Notes:
//   ->  Always O(n²), regardless of input
//   ->  Not adaptive
//   ->  Minimum swaps: good when swaps are expensive

// Detailed Mechanics:
// ->  In each pass, finds the minimum and swaps it with the beginning.
// ->  Never more than (n - 1) swaps, which is useful when write operations
//     are costly (e.g., EEPROMs).

// Issues Often Ignored:
// ->  Still does O(n²) comparisons regardless of order.
// ->  Unstable — equal elements may be swapped in wrong order.

// Optimization Tip:
// ->  Can be adapted to Double Selection Sort: find both min and max in 
//     one pass → halves the number of passes.


// 3. Insertion Sort
// Array: [5, 1, 4, 2, 8]

// i = 1 → key = 1
// Compare with 5 → shift → [5, 5, 4, 2, 8]
// Insert 1 → [1, 5, 4, 2, 8]

// i = 2 → key = 4
// Compare with 5 → shift → [1, 5, 5, 2, 8]
// Insert 4 → [1, 4, 5, 2, 8]

// i = 3 → key = 2
// Compare with 5, 4 → shift → [1, 4, 5, 5, 8], [1, 4, 4, 5, 8]
// Insert 2 → [1, 2, 4, 5, 8]

// i = 4 → key = 8
// No shifting needed


// Notes:
//   ->  Best-case O(n) (already sorted)
//   ->  Worst-case O(n²)
//   ->  Stable and adaptive

// Detailed Mechanics:
// ->  Starts from the second element and inserts it into the sorted portion 
//     by shifting elements to the right.
// ->  Efficient on small or nearly sorted data, hence used in:
// ->  Hybrid sorts (e.g., Timsort, IntroSort) as a base case.
// ->  Incremental processing, such as live data streams.

// Micro-Optimizations:
// ->  Use binary search to find insert position (but still requires shifting):
// ->  Reduces comparisons to O(log n), but time remains O(n²) due to shifts.
// ->  Can be rewritten with pointers for faster memory manipulation.


// 4. Merge Sort
// Array: [5, 1, 4, 2, 8]

// Split → [5,1,4] | [2,8]
// → [5,1] | [4] | [2] | [8]

// Merge [5,1] → [1,5]
// Merge [1,5] + [4] → [1,4,5]
// Merge [2] + [8] → [2,8]
// Merge [1,4,5] + [2,8] → [1,2,4,5,8]


// Notes:
//   ->  Always O(n log n)
//   ->  Extra space (O(n))
//   ->  Stable

// Detailed Mechanics:
// ->  Recursively splits the array in halves → sorts each half → merges them.
// ->  Always O(n log n) due to fixed divide-merge pattern.

// Efficiency Insights:
// ->  Extra space usage is often overlooked — requires O(n) auxiliary space for merge.
// ->  For large data, consider:
//         ->  In-place merge variants (very complex to implement efficiently)
//         ->  Linked list-based merge sort — more space-efficient

// Optimization:
// ->  Avoid copying during merge by alternating between two buffers.


// 5. Quick Sort
// Array: [5, 1, 4, 2, 8], Pivot = Last Element (8)

// Partition [5,1,4,2,8], pivot=8
// All < 8 → no swaps → place pivot at end → [5,1,4,2,8]

// Now recurse:
// Left: [5,1,4,2] → pivot = 2
// → [1, 2, 4, 5] after partition
// → recurse on [1], [4,5]

// Right: empty

// Final: [1,2,4,5,8]

// Notes:
//   ->  Avg-case O(n log n), worst-case O(n²)
//   ->  In-place (no extra memory)
//   ->  Not stable by default

// Detailed Mechanics:
// ->  Picks a pivot, partitions array into < pivot and > pivot segments, and recursively 
//     sorts them.
// ->  In-place and cache-friendly (locality of reference).

// Common Pitfalls:
// ->  Worst-case O(n²) occurs with already sorted or all equal elements if pivot is chosen 
//     poorly.
// ->  Unstable

// Pro Techniques:
// ->  Median-of-three pivot selection: Use median of arr[low], arr[mid], arr[high].
// ->  Tail recursion elimination: Use iteration for one half and recurse only on the other to 
//     save stack.

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Can optimize this
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot)
            swap(&arr[++i], &arr[j]);
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}


// 6. Counting Sort (For Integers)
// Array: [5, 1, 4, 2, 8]

// Range = 0–8 → Count array of size 9

// Count: [0,1,1,0,1,1,0,0,1]
// Cumulative: [0,1,2,2,3,4,4,4,5]

// Build output from end (for stability):
// → [1,2,4,5,8]

// Notes:
//   ->  O(n + k), where k = range of values
//   ->  Works only for integers in a known range
//   ->  Stable
//   ->  Not comparison-based

// Detailed Mechanics:
// ->  Builds a frequency array to count occurrences, then uses prefix sums to 
//     position elements.
// ->  Only works on non-negative integers in a limited range.

// Memory Considerations:
// ->  Needs O(k) space where k = max - min + 1.
// ->  Can be memory-inefficient for sparse input over large ranges.

// Stability:
// ->  To preserve order of equal elements (for radix sort etc.), always fill output 
//     from end to start.


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


#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

void printMemoryMap(int *base, int n) {
    printf("  [Memory Map]\n");
    for (int i = 0; i < n; i++) {
        printf("    &arr[%d] = %p, value = %d\n", i, (void*)(base + i), *(base + i));
    }
    printf("\n");
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Bubble Sort with pointer tracking
void bubbleSortPointerTrace(int *arr, int n) {
    int comp = 0, swaps = 0;
    printf("Initial memory state:\n");
    printMemoryMap(arr, n);

    for (int i = 0; i < n - 1; i++) {
        printf("Pass %d:\n", i + 1);
        int swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            int *ptr1 = arr + j;
            int *ptr2 = arr + j + 1;

            comp++;
            printf("  Comparing *(%p) = %d and *(%p) = %d\n", (void*)ptr1, *ptr1, (void*)ptr2, *ptr2);
            
            if (*ptr1 > *ptr2) {
                printf("  -> Swapping *(%p) = %d and *(%p) = %d\n", 
                        (void*)ptr1, *ptr1, (void*)ptr2, *ptr2);
                swap(ptr1, ptr2);
                swaps++;
            }

            printMemoryMap(arr, n); // Show memory after each comparison
        }
        if (!swapped) {
            printf("No swaps → early exit optimization\n");
            break;
        }
    }

    printf("Final sorted array:\n");
    printMemoryMap(arr, n);
    printf("Total comparisons: %d, total swaps: %d\n", comp, swaps);
}

int main() {
    int arr[SIZE] = {42, 13, 7, 99, 23};
    bubbleSortPointerTrace(arr, SIZE);
    return 0;
}


// Why This Is Powerful ?
//  - data layout in memory
//  - Highlights how pointer arithmetic maps directly to array indexing
//  - Crucial for debugging low-level issues in C, or writing optimized code


// 1. Initial Setup

// int arr[SIZE] = {42, 13, 7, 99, 23};

// This declares a contiguous block of memory with 5 integers. Something like:

// arr[0] → 42
// arr[1] → 13
// arr[2] → 7
// arr[3] → 99
// arr[4] → 23


// In memory, each int takes 4 bytes (usually). So their addresses will be something like:

// &arr[0] = 0x100
// &arr[1] = 0x104
// &arr[2] = 0x108
// ...

// These addresses are platform-specific and change at runtime, but this pattern holds.

// 2. Loop Mechanics & Pointer Math

// The core of Bubble Sort is:
// int *ptr1 = arr + j;
// int *ptr2 = arr + j + 1;

// This is equivalent to:
// int *ptr1 = &arr[j];
// int *ptr2 = &arr[j+1];

// Which means:
// ptr1 points to current element
// ptr2 points to next element

// The comparison is:
// if (*ptr1 > *ptr2)

// You're dereferencing the pointers to compare actual values. If *ptr1 > *ptr2, you swap them using:

// swap(ptr1, ptr2);

// 3. Memory Map Trace

// The function:
// void printMemoryMap(int *base, int n)

// Prints the layout like this:
// &arr[0] = 0x100, value = 42
// &arr[1] = 0x104, value = 13
// ...

// This shows:
//     Memory address of each element
//     Current value at that address
// After each comparison (and possible swap), you see exactly how the array’s memory layout changes.

// Example: First Comparison

// Comparing *(0x100) = 42 and *(0x104) = 13
// → Swapping them

// Then memory map becomes:
// &arr[0] = 0x100, value = 13
// &arr[1] = 0x104, value = 42

// Because you're directly manipulating the memory locations, not just values.

// Why It Matters
//     -> You see how array indexing is just pointer arithmetic in disguise: arr[j] == *(arr + j)
//     -> It shows in-place mutation — no extra memory needed
//     -> It's the basis for understanding more complex algorithms that use dynamic memory, like linked lists or trees
//     -> Knowing addresses is crucial in low-level debugging and manual memory management


// int arr[5] = {42, 13, 7, 99, 23};


// [   0x100   ] →  42
// [   0x104   ] →  13
// [   0x108   ] →   7
// [   0x10C   ] →  99
// [   0x110   ] →  23
// These addresses are 4 bytes apart because each int is 4 bytes.

// int *ptr1 = arr + 0;  // → points to 0x100 (42)
// int *ptr2 = arr + 1;  // → points to 0x104 (13)

// *ptr1 = 42, *ptr2 = 13 → 42 > 13 → swap

// After swap:

// [   0x100   ] →  13   ← now holds former value of arr[1]
// [   0x104   ] →  42   ← now holds former value of arr[0]
// [   0x108   ] →   7
// [   0x10C   ] →  99
// [   0x110   ] →  23
// Values changed, addresses did not.

// ptr1 = arr + 1 → 0x104 → 42  
// ptr2 = arr + 2 → 0x108 → 7  
// → Swap again

// [   0x100   ] →  13
// [   0x104   ] →   7
// [   0x108   ] →  42
// [   0x10C   ] →  99
// [   0x110   ] →  23

// 42 < 99 → no swap

// [   0x100   ] →  13
// [   0x104   ] →   7
// [   0x108   ] →  42
// [   0x10C   ] →  23
// [   0x110   ] →  98

// End of Pass 1 — largest value (98) bubbles to the end.

// Stack vs Heap Commentary
// Stack
//     ->  int arr[5] is a stack-allocated array
//     ->  Memory is allocated when the function runs and freed automatically when it ends
//     ->  Stack is fast, but size-limited (few MB)
//     ->  Memory addresses are contiguous and fixed during runtime

// In our trace:
//     ->  All elements like arr[0], arr[1], etc., live in stack memory
//     ->  ptr1, ptr2 also live on the stack — they're just variables holding addresses

// Heap
//     ->  Not involved in this Bubble Sort example
//     ->  But in something like Merge Sort, temporary arrays (malloc) are heap-allocated
//     ->  You must free heap memory yourself using free()
//     ->  Allows dynamic resizing, much larger than the stack
//     ->  Memory layout is non-contiguous, more fragmented, often slower


// Concept	                    Bubble Sort Example

// Pointer arithmetic	    arr + j gives address of arr[j]
// Memory mutation	        Swapping pointer values changes actual memory
// Stack memory	            Array arr[], ptr1, ptr2 live here
// Memory map	            Shows logical view of RAM as array elements
// Heap memory	            Not used here — becomes crucial in Merge Sort