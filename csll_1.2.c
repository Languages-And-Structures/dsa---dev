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