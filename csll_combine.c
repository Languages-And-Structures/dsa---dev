// Circular Singly Linked List (CSLL)

// ->  Structural Properties
//     ->  Nodes are connected in a circular fashion, meaning:
//             ->  The last node points back to the head.
//             ->  There's no NULL in next pointers (unless the list is empty).
//     ->  Because it's singly linked:
//             ->  Each node only stores one pointer: next.

// Memory Layout Before and After Insertion

// Before Insertion
// Let’s say list has only one node with head → 10 → head

// head
//  ▼
// ┌────────────┐
// │ data: 10   │
// │ next: *    │────┐
// └────────────┘    │
//         ▲         │
//         └─────────┘

// Insertion: Insert 20 at Beginning
//     ->  Allocate memory for a new node (malloc)
//     ->  newNode->next = head
//     ->  Traverse list to find last node (temp->next == head)
//     ->  lastNode->next = newNode
//     ->  head = newNode


// head
//  ▼
// ┌────────────┐
// │ data: 20   │
// │ next: *    │────┐
// └────────────┘    │
//                  ▼
//            ┌────────────┐
//            │ data: 10   │
//            │ next: *    │────┐
//            └────────────┘    │
//                   ▲          │
//                   └──────────┘



// ->  A singly linked list where the last node’s next pointer points 
//     back to the head, forming a loop.
// ->  Only next pointer per node.
// ->  No built-in concept of a tail — traversal is needed to locate 
//     the last node.
// ->  Unidirectional traversal only.

// Let’s insert 30 at the end of this list:
// 10 → 20 → (back to head)

// Steps :
//     ->  Allocate memory for new node using malloc.
//     ->  Set newNode->data = 30
//     ->  If list is empty:
//         ->  newNode->next = newNode
//         ->  *head = newNode
//         ->  Return
//     ->  Else:
//         ->  Use temp = *head and loop until temp->
//         next == *head (i.e., last node)
        
//         ->  Set:
//             ->  temp->next = newNode
//             ->  newNode->next = *head

// Before Insertion:

// head
// ↓
// ┌────────────┐     ┌────────────┐
// │ data: 10   │ --> │ data: 20   │
// │ next:      │     │ next: head │
// └────────────┘     └────────────┘

// After Insertion:

// head
// ↓
// ┌────────────┐     ┌────────────┐     ┌────────────┐
// │ data: 10   │ --> │ data: 20   │ --> │ data: 30   │
// │            │     │            │     │ next: head │
// └────────────┘     └────────────┘     └────────────┘

// Item          Location            Description

// *head       | Stack or Global   | Pointer to first node
// newNode     | Heap              | Dynamically allocated node
// temp        | Stack             | Traversal pointer (temporary use)

// Operation                     Time

// Insert at end (no tail)     | O(n)
// Space per node              | One next pointer
// Ideal if                    | You don’t need fast insertions at end


// Case	                        Handling

// Empty list	        newNode->next = newNode; *head = newNode;
// One node	        Set temp = *head, then update next pointers
// Multiple nodes	    Traverse till temp->next == head


// Step 3: Delete from Beginning

// ->  In CSLL, head points to the first node.
// ->  The last node’s next pointer points back to head.
// ->  To delete the first node:
//         ->  We need to find the last node (because it still points to head).
//         ->  Update last->next = head->next
//         ->  Free head
//         ->  Update head = head->next

// void deleteFromBeginningCSLL(struct CSLLNode** head) {
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

//     struct CSLLNode* last = *head;
//     while (last->next != *head)
//         last = last->next;

//     struct CSLLNode* temp = *head;
//     last->next = (*head)->next;
//     *head = (*head)->next;
//     free(temp);
// }

// Before:
// head
//  ↓
// ┌────────────┐    ┌────────────┐
// │ data: 10   │ →  │ data: 20   │
// │ next: ...  │    │ next: head │
// └────────────┘    └────────────┘

// After Deletion:
// head
//  ↓
// ┌────────────┐
// │ data: 20   │
// │ next: head │
// └────────────┘

// Case	            Handling

// Empty list	    Print message, return
// One node	        Free node, set head = NULL
// Multiple nodes	Traverse to last, relink circularity


// Step 4: Delete from End
// We will again explore this in CSLL and CDLL, side by side, in full depth.

// Circular Singly Linked List (CSLL): Delete from End
// How It Works
// In CSLL:
//     ->  No prev pointer, so you must traverse the entire list to find the 
//         second-last node.
    
//     ->  You need both:
//         ->  last → node to delete
//         ->  prev → node before last, which becomes the new last node

// void deleteFromEndCSLL(struct CSLLNode** head) {
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

//     struct CSLLNode* temp = *head;
//     struct CSLLNode* prev = NULL;

//     // Traverse to the last node
//     while (temp->next != *head) {
//         prev = temp;
//         temp = temp->next;
//     }

//     prev->next = *head;
//     free(temp);
// }

//Before :
// head
// ↓
// ┌────────────┐ → ┌────────────┐ → ┌────────────┐
// │ data: 10   │   │ data: 20   │   │ data: 30   │
// └────────────┘   └────────────┘   └────────────┘
//      ↑                             ↓
//      └─────────────────────────────┘

// After:
//  head
//   ↓
// ┌────────────┐ → ┌────────────┐
// │ data: 10   │   │ data: 20   │
// └────────────┘   └────────────┘
//        ↑             ↓
//        └─────────────┘


// Concern	                Details

// Traversal needed	    Yes (O(n))
// Need prev	        Yes, to remove last node safely
// One node case	    Detected separately


// Circular Singly Linked List (CSLL): Insert at Position

// Concept
//     ->  You must:
//             ->  Traverse to the node just before the desired position
//             ->  Allocate and set new node’s data and next
//             ->  Rewire: prev->next = newNode and newNode->next = current
//     ->  Special cases:
//             ->  Position = 1: same as insert at beginning
//             ->  Position > size+1: invalid

// void insertAtPositionCSLL(struct CSLLNode** head, int data, int pos) {
//     struct CSLLNode* newNode = (struct CSLLNode*)malloc(sizeof(struct CSLLNode));
//     newNode->data = data;

//     if (pos < 1) {
//         printf("Invalid position.\n");
//         return;
//     }

//     if (pos == 1) {
//         insertAtBeginningCSLL(head, data);
//         return;
//     }

//     struct CSLLNode* temp = *head;
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
//     temp->next = newNode;
// }

// 10 → 20 → 30 → (back to head)
// We insert 99 at position 2 (i.e., between 10 and 20).

// Before Insertion:
// (head)  
//   ↓
// ┌────────────┐    ┌────────────┐    ┌────────────┐
// │ data: 10   │ →  │ data: 20   │ →  │ data: 30   │
// └────────────┘    └────────────┘    └────────────┘
//        ↑                             ↓
//        └──────────────←──────────────┘


// After Allocating 99 and Finding Position
//     ->  temp = head
//     ->  count = 1
//     ->  We move till count == pos - 1
//     ->  So now temp points to node 10

// Insertion Rewiring
//     ->  newNode->next = temp->next → 99->next = 20    
//     ->  temp->next = newNode → 10->next = 99
    
// (head)
// ↓
// ┌────────────┐    ┌────────────┐    ┌────────────┐    ┌────────────┐
// │ data: 10   │ →  │ data: 99   │ →  │ data: 20   │ →  │ data: 30   │
// └────────────┘    └────────────┘    └────────────┘    └────────────┘
//      ↑                                                 ↓
//      └────────────────────────────←────────────────────┘


// CSLL: Delete at Position

// Concept
//     ->  Traverse to node just before the one to delete.
//     ->  Unlink and free the target node.
//     ->  Special care if:
//             ->  List is empty
//             ->  Position = 1 (use deleteBeginning)
//             ->  Deleting last node (update link to head)

// void deleteAtPositionCSLL(struct CSLLNode** head, int pos) {
//     if (*head == NULL) {
//         printf("List is empty.\n");
//         return;
//     }

//     if (pos == 1) {
//         deleteBeginningCSLL(head);
//         return;
//     }

//     struct CSLLNode *temp = *head, *prev = NULL;
//     int count = 1;

//     while (count < pos && temp->next != *head) {
//         prev = temp;
//         temp = temp->next;
//         count++;
//     }

//     if (count != pos) {
//         printf("Position out of bounds.\n");
//         return;
//     }

//     prev->next = temp->next;
//     free(temp);
// }

// Given: 10 → 99 → 20 → 30 → (head), Delete at position 2

// Before Deletion:
// (head)
//   ↓
// ┌────────────┐ → ┌────────────┐ → ┌────────────┐ → ┌────────────┐
// │ data: 10   │   │ data: 99   │   │ data: 20   │   │ data: 30   │
// └────────────┘   └────────────┘   └────────────┘   └────────────┘
//        ↑                                           ↓
//        └────────────────────←──────────────────────┘

// temp = 10
// prev = NULL
// Count = 1 → move to 99 (count = 2)
// Now delete node 99:
//     ->  prev->next = temp->next = 20
//     ->  Free node 99

// After Deletion:
// (head)
//   ↓
// ┌────────────┐ → ┌────────────┐ → ┌────────────┐
// │ data: 10   │   │ data: 20   │   │ data: 30   │
// └────────────┘   └────────────┘   └────────────┘
//        ↑                               ↓
//        └────────────←──────────────────┘


// CSLL: Circular Singly Linked List

// Concept
// We start from head and move forward using next until either:
//     ->  We find the target data, or
//     ->  We reach head again (full circle)

// int searchCSLL(struct CSLLNode* head, int key) {
//     if (head == NULL) return 0;

//     struct CSLLNode* temp = head;
//     do {
//         if (temp->data == key)
//             return 1;
//         temp = temp->next;
//     } while (temp != head);

//     return 0;
// }

// List: 10 → 20 → 30 → (back to head)
// Search key = 20
//     ->  temp = head (10)
//     ->  Compare: 10 
//     ->  Move to 20 → match 
//     ->  Return 1

// Memory State

// Component	Location	    Description

// head	        Stack	    Pointer to first node
// temp	        Stack	    Traversal pointer
// List nodes	Heap	    malloc allocated

// Stack               Heap (Nodes)
// ------              ------------------------------
// head ─────────────▶ [10 | * ] ─────────▶ [20 | * ]
//                     ↑                       │
// temp ───────────────┘                       ▼
//                                       [30 | head]

// Search key = 20 → found at second node → return 1


//CSLL SEARCH (WITH INDEX)

// CSLL Search with Position Reporting
// int searchCSLLWithPosition(struct CSLLNode* head, int key) {
//     if (head == NULL) {
//         printf("List is empty.\n");
//         return -1;
//     }

//     struct CSLLNode* temp = head;
//     int pos = 1;

//     do {
//         if (temp->data == key) {
//             return pos;
//         }
//         temp = temp->next;
//         pos++;
//     } while (temp != head);

//     return -1;  // not found
// }

// List: 10 → 20 → 30 → (back to head)
// Search for 30
//      ->  temp = 10, pos = 1 
//      ->  → 20, pos = 2 
//      ->  → 30, pos = 3 
//      ->  return 3

// Stack                      Heap
// ------                     ------------------------
// head ───────┐              [10 | * ] ─▶ [20 | * ] ─▶ [30 | * ] ─┐
// temp ───────┘                                               │
// pos = 3                                                     └──→ back to head

// Stack: temp, pos are loop variables
// Heap: List nodes live here, allocated via malloc


// CSLL Traversal / Display

// void displayCSLL(struct CSLLNode* head) {
//     if (head == NULL) {
//         printf("List is empty.\n");
//         return;
//     }

//     struct CSLLNode* temp = head;
//     do {
//         printf("%d ", temp->data);
//         temp = temp->next;
//     } while (temp != head);

//     printf("\n");
// }

// Stack vs Heap

// Component	Memory	    Description

// head	        Stack	    Head of list
// temp	        Stack	    Current node being printed
// Nodes	    Heap	    Dynamically allocated via malloc

// Loop Unwinding (Example)

// List: 10 → 20 → 30 → (back to head)
// Steps:
//     ->  temp = head → prints 10
//     ->  temp = temp->next → 20 → prints 20
//     ->  temp = temp->next → 30 → prints 30
//     ->  temp = temp->next → back to head → exits loop

// Stack                      Heap (Circular)
// ------                     --------------------------------
// head ───────┐              [10 | * ] ─▶ [20 | * ] ─▶ [30 | * ]
// temp ───────┘                                ▲           │
//                                              └───────────┘

// CSLL — Count Nodes

// int countCSLL(struct CSLLNode* head) {
//     if (head == NULL) return 0;

//     struct CSLLNode* temp = head;
//     int count = 0;

//     do {
//         count++;
//         temp = temp->next;
//     } while (temp != head);

//     return count;
// }

// Stack vs Heap

// Component	Memory	    Description
// head	        Stack	    Pointer to first node
// temp	        Stack	    Iterator
// count	    Stack	    Local counter
// Nodes	    Heap	    Circular singly-linked nodes

// Example: 10 → 20 → 30 → (head)
//     -> count = 0
//     -> temp = head → 10, count = 1
//     -> → 20 → count = 2
//     -> → 30 → count = 3
//     -> → back to head → exit

// Return: 3

// Stack                Heap
// ------               -------------------------------
// head ─────┐          [10 | * ] → [20 | * ] → [30 | * ]
// count = 3 └────────▶                          ↑
// temp ──────────────▶──────────────────────────┘


// Insertion at Position in Circular Singly Linked List (CSLL)

// void insertAtPositionCSLL(struct CSLLNode** head, int data, int pos) {
//     struct CSLLNode* newNode = createNodeCSLL(data);

//     if (*head == NULL && pos == 1) {
//         newNode->next = newNode;
//         *head = newNode;
//         return;
//     }

//     if (pos == 1) {
//         struct CSLLNode* temp = *head;
//         while (temp->next != *head) {
//             temp = temp->next;
//         }
//         newNode->next = *head;
//         temp->next = newNode;
//         *head = newNode;
//         return;
//     }

//     struct CSLLNode* temp = *head;
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
//     temp->next = newNode;
// }

// List: 10 → 20 → 30 → (head)
// Insert: 15 at position 2
//     ->  temp = head = 10
//     ->  count = 1 < 2 - 1 → no
//     ->  newNode = 15
//     ->  newNode->next = temp->next = 20
//     ->  temp->next = newNode
// Updated list: 10 → 15 → 20 → 30 → (head)

// Memory Diagram

// [10] → [15] → [20] → [30]
//  ↑                         ↓
//  └────────────────────────┘


// Deletion by Key in Circular Singly Linked List (CSLL)

// void deleteNodeCSLL(struct CSLLNode** head, int key) {
//     if (*head == NULL) return;

//     struct CSLLNode *curr = *head, *prev = NULL;

//     // If head is to be deleted
//     if (curr->data == key) {
//         if (curr->next == curr) {
//             free(curr);
//             *head = NULL;
//             return;
//         }

//         while (curr->next != *head)
//             curr = curr->next;  // get tail

//         curr->next = (*head)->next;
//         free(*head);
//         *head = curr->next;
//         return;
//     }

//     prev = *head;
//     curr = (*head)->next;

//     while (curr != *head && curr->data != key) {
//         prev = curr;
//         curr = curr->next;
//     }

//     if (curr == *head) {
//         printf("Key not found.\n");
//         return;
//     }

//     prev->next = curr->next;
//     free(curr);
// }

// Initial: 10 → 20 → 30 → (head)
// Delete: 20
//     ->  head = 10, curr = 10, curr->data != key
//     ->  prev = 10, curr = 20
//     ->  Match found → prev->next = curr->next (30) → free 20
// Updated: 10 → 30 → (head)


// Before:
// [10] → [20] → [30]
//  ↑                ↓
//  └────────────────┘


// After deleting 20:
// [10] → [30]
//  ↑         ↓
//  └─────────┘


#include <stdio.h>
#include <stdlib.h>

// Definition of CSLL Node
struct CSLLNode {
    int data;
    struct CSLLNode* next;
};

// Create new node
struct CSLLNode* createNodeCSLL(int data) {
    struct CSLLNode* newNode = (struct CSLLNode*)malloc(sizeof(struct CSLLNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
void insertEndCSLL(struct CSLLNode** head, int data) {
    struct CSLLNode* newNode = createNodeCSLL(data);
    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
        return;
    }
    struct CSLLNode* temp = *head;
    while (temp->next != *head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = *head;
}

// Insert at beginning
void insertBeginningCSLL(struct CSLLNode** head, int data) {
    struct CSLLNode* newNode = createNodeCSLL(data);
    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
        return;
    }
    struct CSLLNode* temp = *head;
    while (temp->next != *head)
        temp = temp->next;

    newNode->next = *head;
    temp->next = newNode;
    *head = newNode;
}

// Insert at position
void insertAtPositionCSLL(struct CSLLNode** head, int data, int pos) {
    struct CSLLNode* newNode = createNodeCSLL(data);

    if (*head == NULL && pos == 1) {
        newNode->next = newNode;
        *head = newNode;
        return;
    }

    if (pos == 1) {
        insertBeginningCSLL(head, data);
        return;
    }

    struct CSLLNode* temp = *head;
    int count = 1;
    while (count < pos - 1 && temp->next != *head) {
        temp = temp->next;
        count++;
    }

    if (count != pos - 1) {
        printf("Invalid position\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Display list
void displayCSLL(struct CSLLNode* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct CSLLNode* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}

// Count nodes
int countNodesCSLL(struct CSLLNode* head) {
    if (head == NULL) return 0;
    int count = 0;
    struct CSLLNode* temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}

// Search for element and return position(s)
void searchCSLL(struct CSLLNode* head, int key) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct CSLLNode* temp = head;
    int pos = 1, found = 0;
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
void deleteNodeCSLL(struct CSLLNode** head, int key) {
    if (*head == NULL) return;

    struct CSLLNode *curr = *head, *prev = NULL;

    // If head to be deleted
    if (curr->data == key) {
        if (curr->next == curr) {
            free(curr);
            *head = NULL;
            return;
        }

        while (curr->next != *head)
            curr = curr->next;

        curr->next = (*head)->next;
        free(*head);
        *head = curr->next;
        return;
    }

    prev = *head;
    curr = (*head)->next;

    while (curr != *head && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }

    if (curr == *head) {
        printf("Key not found\n");
        return;
    }

    prev->next = curr->next;
    free(curr);
}

// Main function for quick testing
int main() {
    struct CSLLNode* head = NULL;

    insertEndCSLL(&head, 10);
    insertEndCSLL(&head, 20);
    insertEndCSLL(&head, 30);
    displayCSLL(head);

    insertBeginningCSLL(&head, 5);
    displayCSLL(head);

    insertAtPositionCSLL(&head, 25, 4);
    displayCSLL(head);

    printf("Total nodes: %d\n", countNodesCSLL(head));
    searchCSLL(head, 20);
    searchCSLL(head, 40);

    deleteNodeCSLL(&head, 5);
    displayCSLL(head);

    deleteNodeCSLL(&head, 30);
    displayCSLL(head);

    deleteNodeCSLL(&head, 100); // Non-existent
    displayCSLL(head);

    return 0;
}



#include <stdio.h>
#include <stdlib.h>

struct CSLLNode {
    int data;
    struct CSLLNode* next;
};

// Utility
struct CSLLNode* createNode(int data) {
    struct CSLLNode* newNode = (struct CSLLNode*)malloc(sizeof(struct CSLLNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
void insertEnd(struct CSLLNode** head, int data) {
    struct CSLLNode* newNode = createNode(data);
    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
        return;
    }
    struct CSLLNode* temp = *head;
    while (temp->next != *head)
        temp = temp->next;
    temp->next = newNode;
    newNode->next = *head;
}

// Insert at position
void insertAtPosition(struct CSLLNode** head, int data, int pos) {
    struct CSLLNode* newNode = createNode(data);
    if (pos <= 1 || *head == NULL) {
        if (*head == NULL) {
            newNode->next = newNode;
            *head = newNode;
        } else {
            struct CSLLNode* temp = *head;
            while (temp->next != *head) temp = temp->next;
            newNode->next = *head;
            temp->next = newNode;
            *head = newNode;
        }
        return;
    }
    struct CSLLNode* temp = *head;
    for (int i = 1; i < pos - 1 && temp->next != *head; i++) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Search
void search(struct CSLLNode* head, int target) {
    if (!head) {
        printf("List is empty.\n");
        return;
    }
    int pos = 1;
    struct CSLLNode* temp = head;
    do {
        if (temp->data == target) {
            printf("Element %d found at position %d\n", target, pos);
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);
    printf("Element %d not found\n", target);
}

// Delete by value
void deleteByValue(struct CSLLNode** head, int val) {
    if (!*head) return;

    struct CSLLNode *curr = *head, *prev = NULL;
    do {
        if (curr->data == val) break;
        prev = curr;
        curr = curr->next;
    } while (curr != *head);

    if (curr->data != val) {
        printf("Value %d not found.\n", val);
        return;
    }

    if (curr == *head) {
        struct CSLLNode* last = *head;
        while (last->next != *head) last = last->next;
        if (last == *head) {
            free(*head);
            *head = NULL;
        } else {
            last->next = (*head)->next;
            free(*head);
            *head = last->next;
        }
    } else {
        prev->next = curr->next;
        free(curr);
    }
}

// Display
void display(struct CSLLNode* head) {
    if (!head) {
        printf("List is empty.\n");
        return;
    }
    struct CSLLNode* temp = head;
    printf("CSLL: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head)\n");
}


// Menu
int main() {
    struct CSLLNode* head = NULL;
    int choice, data, pos;

    do {
        printf("\n1. Insert End\n2. Insert at Position\n3. Delete by Value\n4. Search\n5. Display\n6. Exit\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: "); scanf("%d", &data);
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
                display(head);
                break;
            case 6:
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 6);

    return 0;
}




