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
