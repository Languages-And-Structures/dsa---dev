// Step 5: Delete a Node by Value

// Removes the first node that contains the specified value.
// void deleteByValue(struct Node** head, int key) {
//     if (*head == NULL) {
//         printf("List is empty.\n");
//         return;
//     }

//     struct Node* temp = *head;

//     // Case 1: First node matches
//     if (temp->data == key) {
//         *head = temp->next;
//         if (*head != NULL)
//             (*head)->prev = NULL;
//         free(temp);
//         return;
//     }

//     while (temp != NULL && temp->data != key)
//         temp = temp->next;

//     if (temp == NULL) {
//         printf("Key %d not found.\n", key);
//         return;
//     }

//     // Bridge links across temp
//     temp->prev->next = temp->next;
//     if (temp->next != NULL)
//         temp->next->prev = temp->prev;

//     free(temp);
// }


// What’s Happening?
// 1. Check if list is empty → return.
// 2. If the first node matches the key:
//     ->  Move head forward
//     ->  Set new head’s prev = NULL
//     ->  Free the old head
// 3. Else:
//     ->  Traverse until temp->data == key
//     ->  Update pointers to exclude temp
//     ->  Free temp

// Diagram: Before and After
// Before:
// [10] <-> [20] <-> [30]

// After:
// [10] <-> [30]

// Pointer update:
// [10].next = 30
// [30].prev = 10

//     Case	                        Behavior

// Empty list	                No-op (safe)
// Key at head	                Update head safely
// Key not found	            No-op (safe)
// Node is last	                Just set prev->next = NULL
// Only one node in list	    List becomes empty

// ->  Do not call free(temp) before updating its neighbors — 
//     that would cause use-after-free
// ->  Never assume temp->prev or temp->next exists — always null-check
// ->  Only call (*head)->prev = NULL if new head exists
// ->  Segfault is likely if *head is NULL and you dereference without checking