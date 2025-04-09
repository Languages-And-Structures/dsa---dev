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
