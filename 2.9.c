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
