// Step 7: Forward Traversal (Head → Tail)
// Prints the list in natural left-to-right order.

// void printForward(struct Node* head) {
//     struct Node* temp = head;
//     printf("Forward: ");
//     while (temp != NULL) {
//         printf("%d ", temp->data);
//         temp = temp->next;
//     }
//     printf("\n");
// }

// Key Concepts
//     ->  Starts at head
//     ->  Moves right using temp = temp->next
//     ->  O(n) time
//     ->  Simple but essential for correctness checks


// Step 8: Reverse Traversal (Tail → Head)
// Prints the list in reverse, starting from the tail.

// void printReverse(struct Node* head) {
//     if (head == NULL) {
//         printf("List is empty.\n");
//         return;
//     }

//     struct Node* temp = head;
//     while (temp->next != NULL)  // Reach the tail
//         temp = temp->next;

//     printf("Reverse: ");
//     while (temp != NULL) {
//         printf("%d ", temp->data);
//         temp = temp->prev;
//     }
//     printf("\n");
// }


// DLL:
// [10] <-> [20] <-> [30] <-> [40]

// Forward:
// 10 20 30 40

// Reverse:
// 40 30 20 10

// ->  Forward uses .next, reverse uses .prev
// ->  For reverse, you must reach tail first
// ->  Reverse traversal shows the integrity of prev pointers — good for debugging corruption
// ->  Still O(n), just starts at the opposite end


