// Step 4: Delete from End
// We will again explore this in CSLL and CDLL, side by side, in full depth.

// Circular Singly Linked List (CSLL): Delete from End
// How It Works
// In CSLL:
//     ->  No prev pointer, so you must traverse the entire list to find the 
//         second-last node.
    
//     ->  You need both:
//         ->  last → node to delete
//         ->  prev → node before last, which becomes the new last node

// void deleteFromEndCSLL(struct CSLLNode** head) {
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

//     struct CSLLNode* temp = *head;
//     struct CSLLNode* prev = NULL;

//     // Traverse to the last node
//     while (temp->next != *head) {
//         prev = temp;
//         temp = temp->next;
//     }

//     prev->next = *head;
//     free(temp);
// }

//Before :
// head
// ↓
// ┌────────────┐ → ┌────────────┐ → ┌────────────┐
// │ data: 10   │   │ data: 20   │   │ data: 30   │
// └────────────┘   └────────────┘   └────────────┘
//      ↑                             ↓
//      └─────────────────────────────┘

// After:
//  head
//   ↓
// ┌────────────┐ → ┌────────────┐
// │ data: 10   │   │ data: 20   │
// └────────────┘   └────────────┘
//        ↑             ↓
//        └─────────────┘


// Concern	                Details

// Traversal needed	    Yes (O(n))
// Need prev	        Yes, to remove last node safely
// One node case	    Detected separately