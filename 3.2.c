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
// [   0x110   ] →  99

// End of Pass 1 — largest value (99) bubbles to the end.

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
// Stack memory	        Array arr[], ptr1, ptr2 live here
// Memory map	            Shows logical view of RAM as array elements
// Heap memory	            Not used here — becomes crucial in Merge Sort