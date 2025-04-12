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
