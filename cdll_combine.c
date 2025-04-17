// Circular Doubly Linked List (CDLL)

// Structural Properties
//     ->  Every node has:
//             ->  next pointer (to next node)
//             ->  prev pointer (to previous node)
//     ->  It's circular:
//             ->  head->prev points to the tail
//             ->  tail->next points back to head
//     ->  This allows bidirectional traversal with no NULL

// Memory Layout Before and After Insertion

// Before Insertion
// Single node with self-pointing links:

// head
//  ▼
// ┌────────────────────┐
// │ data: 10           │
// │ prev: *            │◄────┐
// │ next: *            │─────┘
// └────────────────────┘

// Insertion: Insert 20 at Beginning
//     ->  Allocate new node
//     ->  Link newNode->next = head
//     ->  Link newNode->prev = head->prev (which is last node)
//     ->  Update head->prev->next = newNode
//     ->  Update head->prev = newNode
//     ->  head = newNode

// Key Pointers After :

// head
// ▼
// ┌────────────────────┐
// │ data: 20           │
// │ prev: 10           │◄────────────┐
// │ next: 10           │─────┐       │
// └────────────────────┘     │       │
//                            ▼       │
//           ┌────────────────────┐
//           │ data: 10           │
// ┌────────▶│ prev: 20          │
// │         │ next: 20           │◀────────┐
// │         └────────────────────┘         │
// └────────────────────────────────────────┘

// Memory Model

// Aspect	                            CSLL / CDLL

// Node allocation	                malloc from heap
// Local pointers	                On stack, e.g., temp, newNode
// Head pointer	                    Usually maintained globally or passed as **head
// Traversal	                    CSLL needs full traversal to find last node
// CDLL access	                    Uses head->prev to get last node instantly
// Efficiency	                    CDLL wins on insertion/deletion at both ends
// Cost	                            CDLL uses more memory (extra pointer per node)


//   Case	                            CSLL	                                    CDLL

// Empty list	            Set newNode->next = newNode	                Set next and prev to itself
// One node in list	        Handle self-reference loop carefully	    Self-loop both directions
// Insert in multi-node     Traverse (CSLL), or use head->prev (CDLL)	


// Circular Doubly Linked List (CDLL): Insertion at End

    // ->  A doubly linked list where:
    //     ->  Each node has next and prev
    //     ->  The last node’s next points to the head, and the head’s prev points to the last node
    // ->  Supports bi-directional traversal
    // ->  You can access both head and tail easily (via head->prev)

// Steps
// Insert 30 at the end of this: 10 <-> 20 <-> (back to head)

// Step-by-step:
//     ->  Allocate memory: newNode = malloc(...)
//     ->  newNode->data = 30
//     ->  If list is empty:
//         ->  newNode->next = newNode
//         ->  newNode->prev = newNode
//         ->  *head = newNode
//         ->  Return
//     ->  Else:
//         ->  last = (*head)->prev
//         ->  Connect new node:
//             ->  last->next = newNode
//             ->  newNode->prev = last
//             ->  newNode->next = *head
//             ->  (*head)->prev = newNode

// Before:
// head
//  ↓
// ┌────────────┐ ⇄ ┌────────────┐
// │ data: 10   │   │ data: 20   │
// │ prev: 20   │   │ next: 10   │
// └────────────┘   └────────────┘

// After Inserting 30 at End:
// head
//  ↓
// ┌────────────┐ ⇄ ┌────────────┐ ⇄ ┌────────────┐
// │ data: 10   │   │ data: 20   │   │ data: 30   │
// │ prev: 30   │   │ prev: 10   │   │ prev: 20   │
// └────────────┘   └────────────┘   └────────────┘
//      ▲                                     ↓
//      └─────────────────────────────────────┘

// Item        | Memory Type   | Description

// *head       | Stack/Global  | Tracks head of the list
// newNode     | Heap          | Contains new data
// last        | Stack         | Used temporarily, avoids traversal


// CDLL: Delete from Beginning

// head->prev gives you last node instantly.
// You need to:
//     ->  Update head->next->prev = head->prev
//     ->  Update head->prev->next = head->next
//     ->  Free head
//     ->  Set head = head->next

// void deleteFromBeginningCDLL(struct CDLLNode** head) {
//     if (*head == NULL) {
//         printf("List is empty.\n");
//         return;
//     }

//     // Only one node
//     if ((*head)->next == *head) {
//         free(*head);
//         *head = NULL;
//         return;
//     }

//     struct CDLLNode* last = (*head)->prev;
//     struct CDLLNode* temp = *head;

//     last->next = temp->next;
//     temp->next->prev = last;

//     *head = temp->next;
//     free(temp);
// }

// Before:
// head
//  ↓
// ┌────────────┐ ⇄ ┌────────────┐ ⇄ ┌────────────┐
// │ data: 10   │   │ data: 20   │   │ data: 30   │
// └────────────┘   └────────────┘   └────────────┘

// After deleting 10:
// head
//  ↓
// ┌────────────┐ ⇄ ┌────────────┐
// │ data: 20   │   │ data: 30   │
// └────────────┘   └────────────┘


// Case	                Handling
// Empty list	        Print message, return
// One node 	        Free node, set head = NULL
// Multiple nodes	    Update pointers, assign new head


// Circular Doubly Linked List (CDLL): Delete from End

// How It Works

// Since CDLL has prev pointers and the head->prev is always the 
// last node, this operation is constant-time.

// You can access:
//     ->  last = head->prev
//     ->  secondLast = last->prev
//     ->  Update their pointers to remove last

// void deleteFromEndCDLL(struct CDLLNode** head) {
//     if (*head == NULL) {
//         printf("List is empty.\n");
//         return;
//     }

//     // Only one node
//     if ((*head)->next == *head) {
//         free(*head);
//         *head = NULL;
//         return;
//     }

//     struct CDLLNode* last = (*head)->prev;
//     struct CDLLNode* secondLast = last->prev;

//     secondLast->next = *head;
//     (*head)->prev = secondLast;

//     free(last);
// }

// Before :
// head
// ↓
// ┌────────────┐ ⇄ ┌────────────┐ ⇄ ┌────────────┐
// │ data: 10   │   │ data: 20   │   │ data: 30   │
// └────────────┘   └────────────┘   └────────────┘
//      ↑                             ↓
//      └─────────────────────────────┘

// After:
// head
//   ↓
// ┌────────────┐ ⇄ ┌────────────┐
// │ data: 10   │   │ data: 20   │
// └────────────┘   └────────────┘
//        ↑             ↓
//        └─────────────┘


// Circular Doubly Linked List (CDLL): Insert at Position

// Concept
//     ->  Here, you use forward traversal just like CSLL, but update both 
//         next and prev pointers.
//     ->  For position:
//         ->  Traverse to position - 1
//         ->  Rewire both directions

// void insertAtPositionCDLL(struct CDLLNode** head, int data, int pos) {
//     struct CDLLNode* newNode = (struct CDLLNode*)malloc(sizeof(struct CDLLNode));
//     newNode->data = data;

//     if (pos < 1) {
//         printf("Invalid position.\n");
//         return;
//     }

//     if (pos == 1) {
//         insertAtBeginningCDLL(head, data);
//         return;
//     }

//     struct CDLLNode* temp = *head;
//     int count = 1;

//     while (count < pos - 1 && temp->next != *head) {
//         temp = temp->next;
//         count++;
//     }

//     if (count != pos - 1) {
//         printf("Position out of bounds.\n");
//         return;
//     }

//     newNode->next = temp->next;
//     newNode->prev = temp;
//     temp->next->prev = newNode;
//     temp->next = newNode;
// }

// Operation: Insert at Position 2
// Given CDLL:

// 10 ⇄ 20 ⇄ 30 ⇄ (back to head)
// We insert 99 at position 2 (between 10 and 20).

// (head)
//   ↓
// ┌────────────┐⇄┌────────────┐⇄┌────────────┐
// │ data: 10   │  │ data: 20   │  │ data: 30   │
// └────────────┘  └────────────┘  └────────────┘
//        ↑                         ↓
//        └──────────────←─────────┘

// After Allocating and Finding Position
// ->  temp = head
// ->  Move to position 1 (temp = 10)

// Insertion Rewiring
// ->  newNode->next    = temp->next → 99->next = 20
// ->  newNode->prev    = temp → 99->prev       = 10
// ->  temp->next->prev = newNode → 20->prev    = 99
// ->  temp->next       = newNode → 10->next    = 99

// (head)
//   ↓
// ┌────────────┐⇄┌────────────┐⇄┌────────────┐⇄┌────────────┐
// │ data: 10   │  │ data: 99   │  │ data: 20   │  │ data: 30   │
// └────────────┘  └────────────┘  └────────────┘  └────────────┘
//        ↑                                             ↓
//        └────────────────────←────────────────────────┘


// CDLL: Delete at Position

// Concept
//     ->  Traverse to desired position
//     ->  Adjust both prev and next links
//     ->  Free the node
// Special cases:
//     ->  Empty list
//     ->  Only one node
//     ->  Position = 1 → handled with deleteBeginningCDLL

// void deleteAtPositionCDLL(struct CDLLNode** head, int pos) {
//     if (*head == NULL) {
//         printf("List is empty.\n");
//         return;
//     }

//     if (pos == 1) {
//         deleteBeginningCDLL(head);
//         return;
//     }

//     struct CDLLNode* temp = *head;
//     int count = 1;

//     while (count < pos && temp->next != *head) {
//         temp = temp->next;
//         count++;
//     }

//     if (count != pos) {
//         printf("Position out of bounds.\n");
//         return;
//     }

//     temp->prev->next = temp->next;
//     temp->next->prev = temp->prev;
//     free(temp);
// }

// Given: 10 ⇄ 99 ⇄ 20 ⇄ 30, delete at position 2

// Before
// (head)
//   ↓
// ┌────────────┐⇄┌────────────┐⇄┌────────────┐⇄┌────────────┐
// │ data: 10   │  │ data: 99   │  │ data: 20   │  │ data: 30   │
// └────────────┘  └────────────┘  └────────────┘  └────────────┘
//        ↑                                             ↓
//        └────────────────────←────────────────────────┘

// temp = 99
// Adjust:
//     ->  10->next = 20
//     ->  20->prev = 10

// After
// (head)
//   ↓
// ┌────────────┐⇄┌────────────┐⇄┌────────────┐
// │ data: 10   │  │ data: 20   │  │ data: 30   │
// └────────────┘  └────────────┘  └────────────┘
//        ↑                         ↓
//        └────────────←────────────┘


// CDLL: Circular Doubly Linked List

// Concept

// Same idea, except now we follow next, but each 
// node also has prev. This doesn't affect search — 
// just improves flexibility.

// int searchCDLL(struct CDLLNode* head, int key) {
//     if (head == NULL) return 0;

//     struct CDLLNode* temp = head;
//     do {
//         if (temp->data == key)
//             return 1;
//         temp = temp->next;
//     } while (temp != head);

//     return 0;
// }

// List: 10 ⇄ 20 ⇄ 30
// Search key = 25
//     ->  temp = 10 
//     ->  → 20 
//     ->  → 30 
//     ->  → back to head → return 0

// Memory State

// Component	    Location	    Description
// head	            Stack	    Pointer to first node
// temp	            Stack	    Traversal pointer
// List nodes	    Heap	    malloc allocated

// Heap Diagram

// Stack               Heap (Nodes)
// ------              -----------------------------------
// head ─────────────▶ [10 | * | * ] ⇄ [20 | * | * ] ⇄ [30 | * | * ]
//                     ↑
// temp ───────────────┘

// search 25 → not found → return 0

// Edge Cases

//     Case	        CSLL Behavior	            CDLL Behavior

// Empty list	        Return 0	                    Same
// Key at head	        Found on first try	            Same
// Key at last node	    Check till just before head	    Same
// Key not present	    Complete one cycle	            Same
// One node only	    Checked once, then exit	        Same

// CDLL SEARCH (WITH INDEXING)

// int searchCDLLWithPosition(struct CDLLNode* head, int key) {
//     if (head == NULL) {
//         printf("List is empty.\n");
//         return -1;
//     }

//     struct CDLLNode* temp = head;
//     int pos = 1;

//     do {
//         if (temp->data == key) {
//             return pos;
//         }
//         temp = temp->next;
//         pos++;
//     } while (temp != head);

//     return -1;
// }

// List: 10 ⇄ 20 ⇄ 30 ⇄ (back to head)
// Search for 40
// ->  temp = 10, pos = 1 
// ->  → 20, pos = 2 
// ->  → 30, pos = 3 
// ->  → back to 10 → not found
// ->  return -1

// Stack and Heap Memory

// Stack                      Heap
// ------                     -----------------------------------
// head ───────┐              [10 | * | * ] ⇄ [20 | * | * ] ⇄ [30 | * | * ]
// temp ───────┘
// pos = 4 (exit after third check)

// output:
// int result = searchCSLLWithPosition(head, 30);
// if (result != -1)
//     printf("Found at position %d\n", result);
// else
//     printf("Not found\n");


// Code (Forward Only)
// void displayCDLL(struct CDLLNode* head) {
//     if (head == NULL) {
//         printf("List is empty.\n");
//         return;
//     }

//     struct CDLLNode* temp = head;
//     do {
//         printf("%d ", temp->data);
//         temp = temp->next;
//     } while (temp != head);

//     printf("\n");
// }

// Code (Backward Display)
// void displayCDLLReverse(struct CDLLNode* head) {
//     if (head == NULL) {
//         printf("List is empty.\n");
//         return;
//     }

//     struct CDLLNode* temp = head->prev;  // tail node
//     do {
//         printf("%d ", temp->data);
//         temp = temp->prev;
//     } while (temp != head->prev);

//     printf("\n");
// }

// List: 10 ⇄ 20 ⇄ 30 ⇄ (head)
//  ->  Forward: 10 → 20 → 30
//  ->  Backward: 30 → 20 → 10

// Heap Pointer Diagram (Forward)
// Stack                      Heap
// ------                     ---------------------------------------------
// head ───────┐              [10 | *next | *prev ] ⇄ [20 | * | * ] ⇄ [30 | * | * ]
// temp ───────┘

// Forward → next pointers
// Backward → prev pointers

// If only one node:
//     ->  next and prev both point to itself.
//     ->  Loop runs once, then exits.


// CDLL — Count Nodes

// int countCDLL(struct CDLLNode* head) {
//     if (head == NULL) return 0;

//     struct CDLLNode* temp = head;
//     int count = 0;

//     do {
//         count++;
//         temp = temp->next;
//     } while (temp != head);

//     return count;
// }

// Loop Trace
// Example: 10 ⇄ 20 ⇄ 30 ⇄ (head)
//     ->  count = 0
//     → 10 → count = 1
//     → 20 → count = 2
//     → 30 → count = 3
//     → back to 10 → exit

// Stack                Heap
// ------               ----------------------------------------
// head ─────┐          [10 | *next | *prev ] ⇄ [20 | * | * ] ⇄ [30 | * | * ]
// count = 3 └────────▶                                   ↑
// temp ──────────────▶───────────────────────────────────┘


// Reverse Traversal in CDLL

// void displayCDLLReverse(struct CDLLNode* head) {
//     if (head == NULL) {
//         printf("List is empty.\n");
//         return;
//     }

//     struct CDLLNode* tail = head->prev; // Last node
//     struct CDLLNode* temp = tail;

//     do {
//         printf("%d ", temp->data);
//         temp = temp->prev;
//     } while (temp != tail);

//     printf("\n");
// }

// Concept	                        Explanation

// head->prev	                    Points to the last node (tail) in a CDLL
// Traversal via prev	            Moves backward through the list
// Loop stops at original tail	    Ensures no infinite loop due to circularity

// Example List: 10 ⇄ 20 ⇄ 30 ⇄ (circular)
// Initial: head = 10, tail = 30 (head->prev)

// Step 1: temp = 30 → print 30
// Step 2: temp = 20 → print 20
// Step 3: temp = 10 → print 10
// Step 4: temp = 30 → loop condition false → exit

// Output: 30 20 10

// Heap Pointer Layout

// prev                         prev
// [10] ◀──────── [20] ◀──────── [30] ◀───────┐
//  ↑             ↑             ↑            │
//  │             │             │            ▼
//  └────────────▶└────────────▶└────────────┘
//           next                         next

// Stack During Loop

// Stack Frame:
// -------------
// head ───────────→ [10]
// tail ───────────→ [30]
// temp ───────────→ [30] → [20] → [10] → (exit)

// Edge Case: One Node Only

// head->next == head
// head->prev == head

// So tail = head, and:
//     ->  temp = tail = head
//     ->  Print once
//     ->  temp = temp->prev → still head
//     ->  Condition false: exits after one iteration
// Output: node printed once only

// Efficiency Considerations

//     Optimization Idea	                        Impact
// Use tail pointer in the struct	    O(1) tail access if frequently needed
// Stop condition: temp != tail	        Ensures precise cycle control
// Use printf buffering (when large)	Faster output for large lists

// how to store tail in the struct permanently for optimized reverse access ?


// Insertion at Position in Circular Doubly Linked List (CDLL)

// void insertAtPositionCDLL(struct CDLLNode** head, int data, int pos) {
//     struct CDLLNode* newNode = createNodeCDLL(data);

//     if (*head == NULL && pos == 1) {
//         newNode->next = newNode;
//         newNode->prev = newNode;
//         *head = newNode;
//         return;
//     }

//     if (pos == 1) {
//         struct CDLLNode* tail = (*head)->prev;

//         newNode->next = *head;
//         newNode->prev = tail;
//         tail->next = newNode;
//         (*head)->prev = newNode;
//         *head = newNode;
//         return;
//     }

//     struct CDLLNode* temp = *head;
//     int count = 1;

//     while (count < pos - 1 && temp->next != *head) {
//         temp = temp->next;
//         count++;
//     }

//     if (count != pos - 1) {
//         printf("Invalid position.\n");
//         free(newNode);
//         return;
//     }

//     newNode->next = temp->next;
//     newNode->prev = temp;
//     temp->next->prev = newNode;
//     temp->next = newNode;
// }

// List: 10 ⇄ 20 ⇄ 30 ⇄ (head)
// Insert: 15 at position 2
//      ->  temp = 10
//      ->  newNode = 15
//      ->  newNode->next = 20, newNode->prev = 10
//      ->  20->prev = 15, 10->next = 15
// Result: 10 ⇄ 15 ⇄ 20 ⇄ 30 ⇄ (head)


// Deletion by Key in Circular Doubly Linked List (CDLL)

// void deleteNodeCDLL(struct CDLLNode** head, int key) {
//     if (*head == NULL) return;

//     struct CDLLNode *curr = *head;

//     // Head node deletion
//     if (curr->data == key) {
//         if (curr->next == curr) {
//             free(curr);
//             *head = NULL;
//             return;
//         }

//         struct CDLLNode* tail = curr->prev;

//         *head = curr->next;
//         (*head)->prev = tail;
//         tail->next = *head;

//         free(curr);
//         return;
//     }

//     curr = curr->next;

//     while (curr != *head && curr->data != key)
//         curr = curr->next;

//     if (curr == *head) {
//         printf("Key not found.\n");
//         return;
//     }

//     curr->prev->next = curr->next;
//     curr->next->prev = curr->prev;

//     free(curr);
// }

// Initial: 10 ⇄ 20 ⇄ 30 ⇄ (head)
// Delete: 20
//     ->  curr = 10, curr->data != key
//     ->  curr = 20, match found
//     ->  20->prev = 10, 20->next = 30
//     ->  10->next = 30, 30->prev = 10 → free 20
// Updated: 10 ⇄ 30 ⇄ (head)

// Before:
// [10] ⇄ [20] ⇄ [30]
//  ↑               ↓
//  └───────────────┘

// After:
// [10] ⇄ [30]
//  ↑        ↓
//  └────────┘

// Optimization Notes
//  ->  Avoid double traversal by keeping a tail pointer (if frequent tail access)
//  ->  Use free() carefully after pointer updates
//  ->  Insertion/Deletion in CDLL is costlier (more pointer rewiring) but more expressive


#include <stdio.h>
#include <stdlib.h>

// Definition of CDLL Node
struct CDLLNode {
    int data;
    struct CDLLNode* next;
    struct CDLLNode* prev;
};

// Create a new node
struct CDLLNode* createNodeCDLL(int data) {
    struct CDLLNode* newNode = (struct CDLLNode*)malloc(sizeof(struct CDLLNode));
    newNode->data = data;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

// Insert at end
void insertEndCDLL(struct CDLLNode** head, int data) {
    struct CDLLNode* newNode = createNodeCDLL(data);

    if (*head == NULL) {
        newNode->next = newNode->prev = newNode;
        *head = newNode;
        return;
    }

    struct CDLLNode* tail = (*head)->prev;

    tail->next = newNode;
    newNode->prev = tail;
    newNode->next = *head;
    (*head)->prev = newNode;
}

// Insert at beginning
void insertBeginningCDLL(struct CDLLNode** head, int data) {
    insertEndCDLL(head, data);
    *head = (*head)->prev; // Move head back to new node
}

// Insert at position
void insertAtPositionCDLL(struct CDLLNode** head, int data, int pos) {
    int count = 1;
    struct CDLLNode* temp = *head;

    if (*head == NULL && pos == 1) {
        insertBeginningCDLL(head, data);
        return;
    }

    if (pos == 1) {
        insertBeginningCDLL(head, data);
        return;
    }

    struct CDLLNode* newNode = createNodeCDLL(data);
    while (count < pos - 1 && temp->next != *head) {
        temp = temp->next;
        count++;
    }

    if (count != pos - 1) {
        printf("Invalid position\n");
        free(newNode);
        return;
    }

    struct CDLLNode* after = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    newNode->next = after;
    after->prev = newNode;
}

// Display Forward
void displayForwardCDLL(struct CDLLNode* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct CDLLNode* temp = head;
    printf("Forward: ");
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

// Display Reverse
void displayReverseCDLL(struct CDLLNode* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct CDLLNode* tail = head->prev;
    struct CDLLNode* temp = tail;
    printf("Reverse: ");
    do {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    } while (temp != tail);
    printf("(tail)\n");
}

// Count nodes
int countNodesCDLL(struct CDLLNode* head) {
    if (head == NULL) return 0;
    int count = 0;
    struct CDLLNode* temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}

// Search with position
void searchCDLL(struct CDLLNode* head, int key) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    int pos = 1, found = 0;
    struct CDLLNode* temp = head;
    do {
        if (temp->data == key) {
            printf("Found at position %d\n", pos);
            found = 1;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);
    if (!found)
        printf("Key %d not found in list\n", key);
}

// Delete node by value
void deleteNodeCDLL(struct CDLLNode** head, int key) {
    if (*head == NULL) return;

    struct CDLLNode* curr = *head;
    struct CDLLNode* temp = NULL;

    // Search for node with key
    do {
        if (curr->data == key)
            break;
        curr = curr->next;
    } while (curr != *head);

    if (curr->data != key) {
        printf("Key %d not found\n", key);
        return;
    }

    // Single node case
    if (curr->next == curr && curr->prev == curr) {
        free(curr);
        *head = NULL;
        return;
    }

    if (curr == *head)
        *head = curr->next;

    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    free(curr);
}

// Driver program to test CDLL
int main() {
    struct CDLLNode* head = NULL;

    insertEndCDLL(&head, 10);
    insertEndCDLL(&head, 20);
    insertEndCDLL(&head, 30);
    displayForwardCDLL(head);
    displayReverseCDLL(head);

    insertBeginningCDLL(&head, 5);
    displayForwardCDLL(head);

    insertAtPositionCDLL(&head, 25, 4);
    displayForwardCDLL(head);

    printf("Total nodes: %d\n", countNodesCDLL(head));
    searchCDLL(head, 20);
    searchCDLL(head, 50);

    deleteNodeCDLL(&head, 5);
    displayForwardCDLL(head);

    deleteNodeCDLL(&head, 30);
    displayForwardCDLL(head);

    deleteNodeCDLL(&head, 100); // Non-existent
    displayForwardCDLL(head);

    return 0;
}


#include <stdio.h>
#include <stdlib.h>

struct CDLLNode {
    int data;
    struct CDLLNode* next;
    struct CDLLNode* prev;
};

// Create a new node
struct CDLLNode* createNode(int data) {
    struct CDLLNode* newNode = (struct CDLLNode*)malloc(sizeof(struct CDLLNode));
    newNode->data = data;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

// Insert at end
void insertEnd(struct CDLLNode** head, int data) {
    struct CDLLNode* newNode = createNode(data);
    if (*head == NULL) {
        newNode->next = newNode->prev = newNode;
        *head = newNode;
        return;
    }
    struct CDLLNode* tail = (*head)->prev;
    tail->next = newNode;
    newNode->prev = tail;
    newNode->next = *head;
    (*head)->prev = newNode;
}

// Insert at position
void insertAtPosition(struct CDLLNode** head, int data, int pos) {
    struct CDLLNode* newNode = createNode(data);
    if (*head == NULL || pos <= 1) {
        insertEnd(head, data);
        *head = (*head)->prev; // Insert at head
        return;
    }

    struct CDLLNode* temp = *head;
    for (int i = 1; i < pos - 1 && temp->next != *head; i++)
        temp = temp->next;

    struct CDLLNode* nextNode = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
    newNode->next = nextNode;
    nextNode->prev = newNode;
}

// Delete by value
void deleteByValue(struct CDLLNode** head, int value) {
    if (*head == NULL) return;

    struct CDLLNode *curr = *head, *toDelete = NULL;

    do {
        if (curr->data == value) {
            toDelete = curr;
            break;
        }
        curr = curr->next;
    } while (curr != *head);

    if (toDelete == NULL) {
        printf("Value %d not found\n", value);
        return;
    }

    if (toDelete->next == toDelete) {
        free(toDelete);
        *head = NULL;
    } else {
        toDelete->prev->next = toDelete->next;
        toDelete->next->prev = toDelete->prev;
        if (toDelete == *head)
            *head = toDelete->next;
        free(toDelete);
    }
}

// Search
void search(struct CDLLNode* head, int value) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    int pos = 1;
    struct CDLLNode* temp = head;
    do {
        if (temp->data == value) {
            printf("Value %d found at position %d\n", value, pos);
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);
    printf("Value %d not found\n", value);
}

// Display forward
void displayForward(struct CDLLNode* head) {
    if (!head) {
        printf("List is empty.\n");
        return;
    }
    struct CDLLNode* temp = head;
    printf("CDLL Forward: ");
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

// Display reverse
void displayReverse(struct CDLLNode* head) {
    if (!head) {
        printf("List is empty.\n");
        return;
    }
    struct CDLLNode* temp = head->prev;
    printf("CDLL Reverse: ");
    do {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    } while (temp != head->prev);
    printf("(tail)\n");
}

// Menu
int main() {
    struct CDLLNode* head = NULL;
    int choice, data, pos;

    do {
        printf("\n1. Insert End\n2. Insert at Position\n3. Delete by Value\n4. Search\n5. Display Forward\n6. Display Reverse\n7. Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &data);
                insertEnd(&head, data);
                break;
            case 2:
                printf("Enter value and position: ");
                scanf("%d %d", &data, &pos);
                insertAtPosition(&head, data, pos);
                break;
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &data);
                deleteByValue(&head, data);
                break;
            case 4:
                printf("Enter value to search: ");
                scanf("%d", &data);
                search(head, data);
                break;
            case 5:
                displayForward(head);
                break;
            case 6:
                displayReverse(head);
                break;
            case 7:
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 7);

    return 0;
}
