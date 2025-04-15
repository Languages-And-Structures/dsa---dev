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

