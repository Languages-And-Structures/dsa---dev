// Reverse Traversal in CDLL

// void displayCDLLReverse(struct CDLLNode* head) {
//     if (head == NULL) {
//         printf("List is empty.\n");
//         return;
//     }

//     struct CDLLNode* tail = head->prev; // Last node
//     struct CDLLNode* temp = tail;

//     do {
//         printf("%d ", temp->data);
//         temp = temp->prev;
//     } while (temp != tail);

//     printf("\n");
// }

// Concept	                        Explanation

// head->prev	                    Points to the last node (tail) in a CDLL
// Traversal via prev	            Moves backward through the list
// Loop stops at original tail	    Ensures no infinite loop due to circularity

// Example List: 10 ⇄ 20 ⇄ 30 ⇄ (circular)
// Initial: head = 10, tail = 30 (head->prev)

// Step 1: temp = 30 → print 30
// Step 2: temp = 20 → print 20
// Step 3: temp = 10 → print 10
// Step 4: temp = 30 → loop condition false → exit

// Output: 30 20 10

// Heap Pointer Layout

// prev                         prev
// [10] ◀──────── [20] ◀──────── [30] ◀───────┐
//  ↑             ↑             ↑            │
//  │             │             │            ▼
//  └────────────▶└────────────▶└────────────┘
//           next                         next

// Stack During Loop

// Stack Frame:
// -------------
// head ───────────→ [10]
// tail ───────────→ [30]
// temp ───────────→ [30] → [20] → [10] → (exit)

// Edge Case: One Node Only

// head->next == head
// head->prev == head

// So tail = head, and:
//     ->  temp = tail = head
//     ->  Print once
//     ->  temp = temp->prev → still head
//     ->  Condition false: exits after one iteration
// Output: node printed once only

// Efficiency Considerations

//     Optimization Idea	                        Impact
// Use tail pointer in the struct	    O(1) tail access if frequently needed
// Stop condition: temp != tail	        Ensures precise cycle control
// Use printf buffering (when large)	Faster output for large lists
