// 1. What is a struct?

// A struct (structure) in C is a user-defined data type that groups multiple 
// variables of different types under one name.

// struct Point {
//     int x;
//     int y;
// };

// This creates a new type struct Point with two members.
// You can declare and use it like:

// struct Point p1;
// p1.x = 10;
// p1.y = 20;

// Memory Layout (struct)
// For:

// struct Data {
//     char a;   // 1 byte
//     int b;    // 4 bytes
//     char c;   // 1 byte
// };

// Memory is allocated sequentially, but aligned based on the largest 
// member’s alignment requirement (typically 4 bytes for int).

// Expected size: 12 bytes (with padding).

// | a | pad | pad | pad | b | b | b | b | c | pad | pad | pad |
// You can use sizeof(struct Data) to verify.


// 2. What is a union?

// A union is also a user-defined data type, but with a crucial difference:
// All members share the same memory location.
// Only one member can be valid at a time.

// Example:

// union Data {
//     int i;
//     float f;
//     char c;
// };

// All three variables use the same memory, and the size of the union is the 
// size of its largest member.

// Memory Layout (union)
// If:

// int i takes 4 bytes
// float f takes 4 bytes
// char c takes 1 byte

// sizeof(union Data) == 4

// All members start at the same offset, so writing to one overwrites the others.

//     Feature	                    struct	                        union

// Memory Allocation	    Separate for each member	    Shared among all members
// Access	                All members at once         	Only one valid at a time
// Size	                    Sum of sizes + padding	        Size of largest member
// Use Case	                Group related values	        Store one of many possible types
// Safety	                Safer; no overwrite	            Risk of undefined behavior

#include <stdio.h>

struct S {
    char a;    // 1 byte
    int b;     // 4 bytes
    char c;    // 1 byte
};

union U {
    int i;     // 4 bytes
    float f;   // 4 bytes
    char c;    // 1 byte
};

int main() {
    struct S s = { 'A', 100, 'B' };
    union U u;

    u.i = 65;
    printf("u.c = %c\n", u.c); // might print 'A' (same 0x41 value)

    return 0;
}


// Packing Structs (__attribute__((packed)))

// Disables padding, reduces memory size (used in embedded programming)
// Risk: can cause unaligned access on some platforms

struct __attribute__((packed)) Compact {
    char a;
    int b;
};

// Tagged Unions (struct + union combo)
// Used to build type-safe variant types.

struct Variant {
    int tag; // 0 = int, 1 = float
    union {
        int i;
        float f;
    } value;
};


// A linked list is a linear dynamic data structure made of nodes, 
// where each node contains data and a pointer to the next node in the sequence.

// The Core Building Block: The Node
struct Node {
    int data;
    struct Node* next;
};

// Each Node contains:
//   ->  data: the actual value to store
//   ->  next: a pointer to the next node in the list (or NULL if it's the last)

// This allows for dynamic data storage and efficient insertion and deletion of 
// elements since linked lists do not require contiguous memory like arrays do.

// Let’s build a list with the values 10 → 20 → 30.
// struct Node* head;

// Imagine it in memory like:
//    head
//     ↓
// [10| o-] → [20| o-] → [30| X]

// Each [data|next] block is a heap-allocated node
// The last node points to NULL (X)

// Memory Allocation
//     ->  Unlike arrays (which are contiguous in memory), each node in a linked list is:
//     ->  Independently allocated on the heap
//     ->  Connected using pointers
//     ->  Can live anywhere in memory

// This is why it’s called a non-contiguous data structure.

//     Feature	                    Arrays	                    Linked Lists

// Memory layout	            Contiguous	                Non-contiguous (heap)
// Insert/Delete (middle)	    Costly (O(n) shifts)	    Efficient (O(1) if pointer known)
// Size flexibility	        Fixed after allocation	    Fully dynamic (malloc as needed)
// Indexing	                O(1) via arr[i]	            O(n) traversal required
// Cache locality	            High	                    Poor (fragmented memory)

// Each of these has unique pointer mechanics:

// 1.Traversal (iterating through the list)
// 2.Insertion
//     ->  At the beginning
//     ->  In the middle (after a given node)
//     ->  At the end
// 3.Deletion
//     ->  By value
//     ->  By position
// 4.Searching
// 5.Reversing the list

// All these operations manipulate pointers directly — unlike arrays, where you deal with indices.

//   Operation	        Time Complexity     	Notes

// Access (random)	        O(n)	        No direct indexing like arr[i]
// Search	                O(n)	        Linear traversal
// Insert (beginning)	    O(1)	        Just change head
// Insert (middle)	        O(n)	        Must traverse to the point
// Delete (known node)	    O(1)	        If you have pointer to previous node
// Delete (by value)	    O(n)	        Traverse to find it


// 1. Pointer Ownership
//     ->  Who owns the next pointer matters during deletion or insertion.
// 2. Dangling Pointers
//     ->  Deleting a node without updating all references to it causes dangling pointers.
// 3. Memory Leaks
//     ->  Every malloc must be matched with a free, or you leak memory over time.
// 4. Cache Unfriendliness
//     ->  Nodes scattered in memory → worse cache performance compared to arrays

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node* head = (struct Node*) malloc(sizeof(struct Node));
    struct Node* second = (struct Node*) malloc(sizeof(struct Node));
    struct Node* third = (struct Node*) malloc(sizeof(struct Node));

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = third;

    third->data = 30;
    third->next = NULL;

    return 0;
}

// Struct Definition

// struct Node {
//     int data;
//     struct Node* next;
// };

// - Defines a custom user-defined type, struct Node
// - Each Node has:
//      ->  data: stores an integer (4 bytes)
//      ->  next: pointer to the next node, or NULL if it's the last one (typically 8 bytes on 
//          64-bit systems)

// Memory Allocation with malloc()
// struct Node* head = (struct Node*) malloc(sizeof(struct Node));

// ->  malloc(sizeof(struct Node)):
//         ->  Reserves heap memory for one node
//         ->  sizeof(struct Node) = 4 bytes (int) + 8 bytes (pointer) = 12 bytes (may be padded to 16)
//         ->  Returns a pointer to that heap-allocated node
// ->  head lives on the stack and points to that heap memory block

// Same thing repeats for second and third.

// Stack vs Heap Breakdown

// Stack (local variables)	        Heap (dynamically allocated nodes)
// head → points to 0x1000	            `0x1000: [10
// second → points to 0x2000	        `0x2000: [20
// third → points to 0x3000	        `0x3000: [30

// Assigning Data and Linking Nodes
// head->data = 10;
// head->next = second;

// ->  head->data = 10 stores 10 in the memory block pointed to by head
// ->  head->next = second sets the next pointer inside the first node to point to the second 
//     node’s address (i.e., link)
// This is pointer assignment: you're saying, “the next node after head is second.”

// The same logic applies for:
// second->data = 20;
// second->next = third;

// third->data = 30;
// third->next = NULL;

// You now have a linked chain of nodes:

//   ->  head → Node1 (10)
//   ->  Node1 → Node2 (20)
//   ->  Node2 → Node3 (30)
//   ->  Node3 → NULL

// Heap Memory Layout (Diagram)

// Let’s represent each node like:
// [ DATA | NEXT ]

// Now the memory looks like:
// head → [10 | 0x2000] → [20 | 0x3000] → [30 | NULL]

// What’s Actually Happening in Memory?
// ->  All nodes are scattered in heap memory (non-contiguous)
// ->  The next field contains actual memory addresses
// ->  The chain is constructed via pointer wiring

// Pointer Mechanics
// head->next = second;
// Assume:
//     ->  head = 0x1000
//     ->  second = 0x2000

// Then:
//     ->  head->next translates to *((0x1000) + 4) if data is at offset 0 and next at offset 4/8
//     ->  You're assigning 0x2000 to that memory location
//     ->  So the memory at 0x1000 + offset now stores address 0x2000
// This builds the chain.

// Flow Control & Safety

// You must manually terminate the list by doing:
// third->next = NULL;
// Without this, traversal will access garbage and crash.

// If you forget to allocate memory for third and still set second->next = third, 
// it will point to an invalid memory area.

//   Action	                       Memory Effect

// Define struct	            Blueprint for nodes
// Use malloc()	                Allocates individual nodes in heap memory
// Set data field	            Writes integer value at the allocated block
// Set next pointer	            Links one node to the next via memory addresses
// Set next = NULL	            Terminates the list
// No freeing of nodes here	    Causes memory leak unless handled separately


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


#include <stdio.h>
#include <stdlib.h>

// Define Node structure
struct Node
{
    int data;
    struct Node *next;
};

// Function to create a new node with given data
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at beginning
void insertAtBeginning(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Insert at end
void insertAtEnd(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Insert after a given value
void insertAfterValue(struct Node *head, int key, int data)
{
    struct Node *temp = head;
    while (temp != NULL && temp->data != key)
        temp = temp->next;
    if (temp == NULL)
    {
        printf("Value %d not found.\n", key);
        return;
    }
    struct Node *newNode = createNode(data);
    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete node by value
void deleteByValue(struct Node **head, int key)
{
    struct Node *temp = *head, *prev = NULL;

    if (temp != NULL && temp->data == key)
    {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Value %d not found.\n", key);
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// Delete node by position
void deleteAtPosition(struct Node **head, int position)
{
    if (*head == NULL || position < 0)
        return;

    struct Node *temp = *head;

    if (position == 0)
    {
        *head = temp->next;
        free(temp);
        return;
    }

    for (int i = 0; temp != NULL && i < position - 1; i++)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL)
        return;

    struct Node *toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
}

// Traverse and print
void traverse(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Search a value
int search(struct Node *head, int key)
{
    int index = 0;
    while (head != NULL)
    {
        if (head->data == key)
            return index;
        head = head->next;
        index++;
    }
    return -1;
}

// Count nodes
int countNodes(struct Node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

// Free memory
void freeList(struct Node **head)
{
    struct Node *temp;
    while (*head != NULL)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

// Driver code to test everything
int main()
{
    struct Node *head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtBeginning(&head, 5);
    insertAfterValue(head, 10, 15);

    printf("Linked List: ");
    traverse(head);

    printf("Node count: %d\n", countNodes(head));

    int pos = search(head, 15);
    printf("Value 15 found at position: %d\n", pos);

    deleteByValue(&head, 10);
    printf("After deleting 10: ");
    traverse(head);

    deleteAtPosition(&head, 1);
    printf("After deleting at position 1: ");
    traverse(head);

    freeList(&head);
    printf("After freeing: ");
    traverse(head); // should print nothing

    return 0;
}


// Add a Menu-Drive
//     ->  Insert elements at beginning or end
//     ->  Insert after a value
//     ->  Delete by value or position
//     ->  Search, count, print
//     ->  Exit program

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode)
    {
        printf("Memory error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    struct Node *temp = *head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

void insertAfterValue(struct Node *head, int key, int data)
{
    struct Node *temp = head;
    while (temp && temp->data != key)
        temp = temp->next;
    if (!temp)
    {
        printf("Key not found.\n");
        return;
    }
    struct Node *newNode = createNode(data);
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteByValue(struct Node **head, int key)
{
    struct Node *temp = *head, *prev = NULL;
    if (temp && temp->data == key)
    {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }
    if (!temp)
    {
        printf("Value not found.\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

void deleteAtPosition(struct Node **head, int pos)
{
    if (*head == NULL || pos < 0)
        return;
    struct Node *temp = *head;
    if (pos == 0)
    {
        *head = temp->next;
        free(temp);
        return;
    }
    for (int i = 0; i < pos - 1 && temp; i++)
        temp = temp->next;
    if (!temp || !temp->next)
        return;
    struct Node *del = temp->next;
    temp->next = del->next;
    free(del);
}

int search(struct Node *head, int key)
{
    int i = 0;
    while (head)
    {
        if (head->data == key)
            return i;
        head = head->next;
        i++;
    }
    return -1;
}

int countNodes(struct Node *head)
{
    int count = 0;
    while (head)
    {
        count++;
        head = head->next;
    }
    return count;
}

void traverse(struct Node *head)
{
    printf("List: ");
    while (head)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void freeList(struct Node **head)
{
    struct Node *temp;
    while (*head)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

int main()
{
    struct Node *head = NULL;
    int choice, data, key, pos;

    while (1)
    {
        printf("\n1. Insert at Beginning\n2. Insert at End\n3. Insert after Value\n4. Delete by Value\n");
        printf("5. Delete at Position\n6. Search\n7. Count\n8. Traverse\n9. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            insertAtBeginning(&head, data);
            break;
        case 2:
            printf("Enter data: ");
            scanf("%d", &data);
            insertAtEnd(&head, data);
            break;
        case 3:
            printf("Insert after which value? ");
            scanf("%d", &key);
            printf("Enter new data: ");
            scanf("%d", &data);
            insertAfterValue(head, key, data);
            break;
        case 4:
            printf("Enter value to delete: ");
            scanf("%d", &data);
            deleteByValue(&head, data);
            break;
        case 5:
            printf("Enter position: ");
            scanf("%d", &pos);
            deleteAtPosition(&head, pos);
            break;
        case 6:
            printf("Enter value to search: ");
            scanf("%d", &data);
            pos = search(head, data);
            if (pos >= 0)
                printf("Found at position %d\n", pos);
            else
                printf("Not found.\n");
            break;
        case 7:
            printf("Node count: %d\n", countNodes(head));
            break;
        case 8:
            traverse(head);
            break;
        case 9:
            freeList(&head);
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice.\n");
        }
    }
}


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


// Step 2: Insert at End

// void insertAtEnd(struct Node** head, int data) {
//     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//     newNode->data = data;
//     newNode->next = NULL;

//     if (*head == NULL) {
//         newNode->prev = NULL;
//         *head = newNode;
//         return;
//     }

//     struct Node* temp = *head;
//     while (temp->next != NULL)
//         temp = temp->next;

//     temp->next = newNode;
//     newNode->prev = temp;
// }


// What’s Happening Internally?

//     ->  Allocate and initialize a new node.
//     ->  If list is empty, this new node becomes the head.
//     ->  Else, traverse to the last node (temp).
//     ->  Update temp->next = newNode
//     ->  Set newNode->prev = temp

// Initial list:
// head → [10] <-> [20] <-> [30] → NULL

// Call:
// insertAtEnd(&head, 40);

// Diagram (Before and After)
// Before:
// head → [10] <-> [20] <-> [30]

// After:
// head → [10] <-> [20] <-> [30] <-> [40]

// [40].prev = address of 30
// [30].next = address of 40
// [40].next = NULL

// 1. Avoid Memory Leaks on Traversal
//     If a pointer like temp is lost or not updated correctly, malloc()'d memory 
//     becomes inaccessible, causing a memory leak.

// 2. Tail Pointer Optimization
//     If frequent end-inserts are expected:
//         ->  Keep a tail pointer to avoid O(n) traversal.
//         ->  End insert becomes O(1) instead of O(n).

// 3. Traverse Safely
//     Always check temp != NULL before dereferencing temp->next to avoid segfaults 
//     in bad usage scenarios.

// 4. Multi-Threading Risk
//     If multiple threads are appending to the list, insertions must be guarded 
//     using a mutex lock.

// 5. Watch for Infinite Loops
//     If you mistakenly update temp->next = newNode before moving temp, and then 
//     reuse temp, you risk a circular loop or crash.


// Step 3: Insert After a Given Node (by Value)

// This function inserts a new node after the first occurrence of 
// a given value in a doubly linked list.

// void insertAfterValue(struct Node* head, int key, int data) {
//     struct Node* temp = head;

//     while (temp != NULL && temp->data != key)
//         temp = temp->next;

//     if (temp == NULL) {
//         printf("Key %d not found.\n", key);
//         return;
//     }

//     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//     newNode->data = data;

//     newNode->next = temp->next;
//     newNode->prev = temp;

//     if (temp->next != NULL)
//         temp->next->prev = newNode;

//     temp->next = newNode;
// }

// What’s Happening?
//     ->  Traverse to the first node with value == key
//     ->  Allocate and initialize a new node
//     ->  Link newNode->next = temp->next
//     ->  Link newNode->prev = temp
//     ->  If temp->next exists, back-link its prev to newNode
//     ->  Set temp->next = newNode

// List before insertion:
// head → [10] <-> [20] <-> [30]

// Now do:
// insertAfterValue(head, 20, 25);

// Diagram (Before and After)
// Before:
// [10] <-> [20] <-> [30]

// After:
// [10] <-> [20] <-> [25] <-> [30]

// Pointer updates:
// [20].next = 25
// [25].prev = 20
// [25].next = 30
// [30].prev = 25

// 1. Node Exists Check
// if (temp == NULL)
// Important to avoid crashing when the key doesn’t exist.

// 2. Middle vs. End Case Handling
//     ->  If inserting after the last node, temp->next == NULL, and we don’t 
//         update temp->next->prev
//     ->  This check ensures safety:
//     if (temp->next != NULL)
//     temp->next->prev = newNode;

// 3. Avoid Memory Leaks or Corruption
// Make sure:
//     ->  newNode->prev is correctly linked
//     ->  temp->next = newNode is assigned after setting other pointers
//     ->  Freeing or reassigning nodes prematurely can corrupt the list

// 4. No Update to Head
// Unlike insert at beginning, this function never modifies head, so no need for double pointer







