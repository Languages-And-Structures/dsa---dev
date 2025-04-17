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




