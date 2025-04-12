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

