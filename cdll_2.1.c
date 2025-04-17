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

