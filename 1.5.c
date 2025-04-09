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

