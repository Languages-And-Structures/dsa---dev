// 1. Pointer Ownership & Traversal Invariants
//  What’s Often Missed:
//     ->  When manipulating a list (insert/delete), always track pointer ownership:       ->  
//     ->  Who is currently holding a valid reference to a node?
//     ->  Do you maintain a pointer to the previous node (in insertion/deletion)?
//     ->  Do you safely terminate traversal when current == NULL?

//  Traversal Invariant:

// while (temp != NULL) {
//     // safe: temp->data
//     temp = temp->next;
// }
// Never access temp->next after temp == NULL. That leads to segmentation faults.

// 2. Heap Memory & Lifetime Management
//  What’s Often Missed:
//     ->  Every malloc requires a corresponding free to prevent memory leaks
//     ->  Nodes must be freed after unlinking them to avoid dangling pointers
//     ->  If free(temp) is called but other pointers still point to that node: undefined behavior

//  Proper Deallocation Example:
// struct Node* temp;
// while (head != NULL) {
//     temp = head;
//     head = head->next;
//     free(temp); // release memory
// }

// 3. Data Alignment & Padding
//  What’s Often Missed:
//     ->  Due to structure alignment, sizeof(struct Node) may be larger than expected
//     ->  On 64-bit systems: int (4 bytes) + pointer (8 bytes) may cause padding

//     printf("%zu\n", sizeof(struct Node)); // Likely prints 16

//     This impacts memory footprint in large-scale lists.

// 4. Null-Termination Is Manual
//  What’s Often Missed:
//     ->  You must explicitly set next = NULL in the last node
//     ->  If you forget, traversal may run into garbage memory, crash, or enter infinite loop

//     if (newNode->next != NULL) {
//         printf("ERROR: New tail node must point to NULL!\n");
//     }

// 5. Sentinel Nodes (Dummy Nodes)
// What’s Often Missed:
// Using a dummy head node simplifies insertion logic (especially at head).

// struct Node* dummy = malloc(sizeof(struct Node));
// dummy->next = NULL; // initially empty list

// No need to treat head insertion as a special case
// Uniform insert/delete logic

// 6. Loss of Random Access
// Unlike arrays, SLLs do not support constant-time indexing.

// // Inefficient access
// for (int i = 0; i < index; i++)
//     temp = temp->next;

// If your algorithm needs frequent indexed access, linked lists are suboptimal.

// 7. Cache Performance: Poor Locality
// What’s Often Missed:
//     ->  Arrays: contiguous, prefetchable, cache-friendly
//     ->  Linked lists: scattered across heap, poor spatial locality

// In modern CPUs, this leads to cache misses, even if asymptotic complexity is good.

// 8. Struct Packing for Embedded Use
// In memory-constrained environments:

// struct __attribute__((packed)) Node {
//     int data;
//     struct Node* next;
// };

// Avoids alignment padding. Use with caution — platform-specific and can lead to slow 
// unaligned memory access.

// 9. NULL Checks & Defensive Programming
// Always validate malloc and pointers:

// struct Node* n = malloc(sizeof(struct Node));
// if (n == NULL) {
//     perror("malloc failed");
//     exit(1);
// }

// And before dereferencing:

// if (head != NULL)
//     printf("%d\n", head->data);


// 10. Tail Pointer Optimization (for End Insertions)
// If your use case involves frequent insertions at the end, maintain a tail pointer:

// struct Node* tail = head;
// tail->next = newNode;
// tail = newNode;

// Avoids O(n) traversal to append at the end — makes it O(1).

// 11. Self-Referential Structures Need Forward Declaration
// struct Node {
//     int data;
//     struct Node* next; // valid because of self-reference
// };

// This works because C allows a pointer to an incomplete type. You cannot do:

// struct Node {
//     struct Node next; // invalid: full type needed
// };

// 12. Reentrancy and Thread Safety
// Singly Linked Lists are not thread-safe by default.
//     ->  Use mutexes if accessed concurrently
//     ->  Avoid modifying while traversing unless safe







