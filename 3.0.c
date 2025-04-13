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