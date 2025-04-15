// Step 6: Delete a Node at a Given Position (0-based index)

// Removes the node located at a specific position in the 
// doubly linked list.

// void deleteAtPosition(struct Node** head, int pos) {
//     if (*head == NULL || pos < 0) {
//         printf("List is empty or invalid position.\n");
//         return;
//     }

//     struct Node* temp = *head;
//     int i = 0;

//     // Special case: deleting the head
//     if (pos == 0) {
//         *head = temp->next;
//         if (*head != NULL)
//             (*head)->prev = NULL;
//         free(temp);
//         return;
//     }

//     // Traverse to the node at index pos
//     while (temp != NULL && i < pos) {
//         temp = temp->next;
//         i++;
//     }

//     if (temp == NULL) {
//         printf("Position %d exceeds list length.\n", pos);
//         return;
//     }

//     // Remove temp
//     if (temp->prev != NULL)
//         temp->prev->next = temp->next;
//     if (temp->next != NULL)
//         temp->next->prev = temp->prev;

//     free(temp);
// }

// What’s Happening?
// 1. Reject negative positions.
// 2. If pos == 0, remove head and update new head’s prev = NULL.
// 3. Traverse using i until the pos-th node.
// 4. Relink prev->next and next->prev around the node at pos.
// 5. Free the node at that position.

// List:
// [10] <-> [20] <-> [30] <-> [40]

// Call:
// deleteAtPosition(&head, 2);

// After:
// [10] <-> [20] <-> [40]

// Pointer rewiring:
// [20].next = 40
// [40].prev = 20

// Scenario	                  Covered

// Empty list	                yes
// Position < 0	                yes
// Deleting head	            yes
// Position exceeds length	    yes
// Deleting last node	        yes

// ->  Safe traversal: always check temp != NULL during loop
// ->  Avoid pointer dereference without null checks
// ->  prev and next must be rewired before freeing the node
// ->  Positional access is inherently O(n) unless you maintain indices or 
//     shortcut traversal