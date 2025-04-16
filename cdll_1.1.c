// Circular Doubly Linked List (CDLL): Insertion at End

    // ->  A doubly linked list where:
    //     ->  Each node has next and prev
    //     ->  The last node’s next points to the head, and the head’s prev points to the last node
    // ->  Supports bi-directional traversal
    // ->  You can access both head and tail easily (via head->prev)

// Steps
// Insert 30 at the end of this: 10 <-> 20 <-> (back to head)

// Step-by-step:
//     ->  Allocate memory: newNode = malloc(...)
//     ->  newNode->data = 30
//     ->  If list is empty:
//         ->  newNode->next = newNode
//         ->  newNode->prev = newNode
//         ->  *head = newNode
//         ->  Return
//     ->  Else:
//         ->  last = (*head)->prev
//         ->  Connect new node:
//             ->  last->next = newNode
//             ->  newNode->prev = last
//             ->  newNode->next = *head
//             ->  (*head)->prev = newNode

// Before:
// head
//  ↓
// ┌────────────┐ ⇄ ┌────────────┐
// │ data: 10   │   │ data: 20   │
// │ prev: 20   │   │ next: 10   │
// └────────────┘   └────────────┘

// After Inserting 30 at End:
// head
//  ↓
// ┌────────────┐ ⇄ ┌────────────┐ ⇄ ┌────────────┐
// │ data: 10   │   │ data: 20   │   │ data: 30   │
// │ prev: 30   │   │ prev: 10   │   │ prev: 20   │
// └────────────┘   └────────────┘   └────────────┘
//      ▲                                     ↓
//      └─────────────────────────────────────┘

// Item        | Memory Type   | Description

// *head       | Stack/Global  | Tracks head of the list
// newNode     | Heap          | Contains new data
// last        | Stack         | Used temporarily, avoids traversal














