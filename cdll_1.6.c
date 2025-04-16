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




