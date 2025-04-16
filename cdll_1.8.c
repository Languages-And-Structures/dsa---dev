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








