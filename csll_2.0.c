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