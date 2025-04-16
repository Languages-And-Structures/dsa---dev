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







