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

