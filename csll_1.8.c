// CSLL — Count Nodes

// int countCSLL(struct CSLLNode* head) {
//     if (head == NULL) return 0;

//     struct CSLLNode* temp = head;
//     int count = 0;

//     do {
//         count++;
//         temp = temp->next;
//     } while (temp != head);

//     return count;
// }

// Stack vs Heap

// Component	Memory	    Description
// head	        Stack	    Pointer to first node
// temp	        Stack	    Iterator
// count	    Stack	    Local counter
// Nodes	    Heap	    Circular singly-linked nodes

// Example: 10 → 20 → 30 → (head)
//     -> count = 0
//     -> temp = head → 10, count = 1
//     -> → 20 → count = 2
//     -> → 30 → count = 3
//     -> → back to head → exit

// Return: 3

// Stack                Heap
// ------               -------------------------------
// head ─────┐          [10 | * ] → [20 | * ] → [30 | * ]
// count = 3 └────────▶                          ↑
// temp ──────────────▶──────────────────────────┘

