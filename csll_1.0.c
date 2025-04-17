// Circular Singly Linked List (CSLL)

// ->  Structural Properties
//     ->  Nodes are connected in a circular fashion, meaning:
//             ->  The last node points back to the head.
//             ->  There's no NULL in next pointers (unless the list is empty).
//     ->  Because it's singly linked:
//             ->  Each node only stores one pointer: next.

// Memory Layout Before and After Insertion

// Before Insertion
// Let’s say list has only one node with head → 10 → head

// head
//  ▼
// ┌────────────┐
// │ data: 10   │
// │ next: *    │────┐
// └────────────┘    │
//         ▲         │
//         └─────────┘

// Insertion: Insert 20 at Beginning
//     ->  Allocate memory for a new node (malloc)
//     ->  newNode->next = head
//     ->  Traverse list to find last node (temp->next == head)
//     ->  lastNode->next = newNode
//     ->  head = newNode


// head
//  ▼
// ┌────────────┐
// │ data: 20   │
// │ next: *    │────┐
// └────────────┘    │
//                  ▼
//            ┌────────────┐
//            │ data: 10   │
//            │ next: *    │────┐
//            └────────────┘    │
//                   ▲          │
//                   └──────────┘



