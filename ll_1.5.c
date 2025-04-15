// Step 1: Node Definition + Insert at Beginning

// Node Structure

// struct Node {
//     int data;
//     struct Node* prev;
//     struct Node* next;
// };
// We use both prev and next pointers to enable bi-directional traversal 
// and updates.


// Function: Insert at Beginning
// void insertAtBeginning(struct Node** head, int data) {
//     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//     newNode->data = data;
//     newNode->prev = NULL;
//     newNode->next = *head;

//     if (*head != NULL)
//         (*head)->prev = newNode;

//     *head = newNode;
// }

// What’s Happening Internally
//     ->  Allocate memory for a new node.
//     ->  Set its data.
//     ->  Make its next point to the current head.
//     ->  Set prev of old head to new node (if it exists).
//     ->  Update the head pointer to this new node.

// Memory Trace

// Assume the list was:
// NULL <- [10] <-> [20] <-> [30] -> NULL
// Now you call:
// insertAtBeginning(&head, 5);


// Diagram (Before and After)
// Before:
// head --> [10] <-> [20] <-> [30]
// After:
// head --> [5] <-> [10] <-> [20] <-> [30]

// Pointer States:
//     ->  [5].prev = NULL
//     ->  [5].next = address of 10
//     ->  [10].prev = address of 5

// Minimal Test Code

// int main() {
//     struct Node* head = NULL;
//     insertAtBeginning(&head, 10);
//     insertAtBeginning(&head, 20);
//     insertAtBeginning(&head, 30);
//     insertAtBeginning(&head, 5);
// }



// 1. Pointer Consistency is Crucial
// If you forget to update (*head)->prev = newNode; before changing *head, 
// you'll break the back-linking logic.
//     ->  This is a common bug, especially in interview code.
//     ->  Always update internal pointers before moving external references.

// 2. Memory Allocation Check (optional but recommended)
// In real-world or embedded systems, always verify memory allocation:

// if (newNode == NULL) {
//     fprintf(stderr, "Memory allocation failed\n");
//     exit(1);
// }

// 3. Edge Case: Empty List
//     ->  If *head == NULL, we simply set newNode->next = NULL and newNode->prev = NULL.
//     ->  No need to update the prev pointer of the old head (since it doesn't exist).

// 4. Dangling Pointers Prevention
// If you free or overwrite the old head before updating prev, you'll introduce 
// a dangling pointer in the DLL — a subtle memory corruption source.

// 5. Use of Double Pointers
// Why struct Node** head?
//     ->  Because we may need to update the actual head in main.
//     ->  If we use a single pointer (struct Node* head), changes to head inside the 
//         function won't reflect outside.

// 6. Cache Optimization (Advanced)
// In systems with limited memory or high-performance requirements:
//     ->  Node locality in memory matters — placing nodes contiguously (or reusing memory 
//         pools) improves CPU cache efficiency.
//     ->  This matters more in very large lists or real-time systems.

// 7. Thread Safety (Advanced Use)
// If this function is used in multi-threaded programs:
//     ->  It must be guarded using mutex locks, because linked list operations are not atomic.
//     ->  Insertions may cause race conditions if two threads modify head concurrently.