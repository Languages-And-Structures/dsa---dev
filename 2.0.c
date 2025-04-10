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
