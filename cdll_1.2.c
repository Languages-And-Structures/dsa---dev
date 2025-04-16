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

