// Circular Singly Linked List (CSLL): Insert at Position

// Concept
//     ->  You must:
//             ->  Traverse to the node just before the desired position
//             ->  Allocate and set new node’s data and next
//             ->  Rewire: prev->next = newNode and newNode->next = current
//     ->  Special cases:
//             ->  Position = 1: same as insert at beginning
//             ->  Position > size+1: invalid

// void insertAtPositionCSLL(struct CSLLNode** head, int data, int pos) {
//     struct CSLLNode* newNode = (struct CSLLNode*)malloc(sizeof(struct CSLLNode));
//     newNode->data = data;

//     if (pos < 1) {
//         printf("Invalid position.\n");
//         return;
//     }

//     if (pos == 1) {
//         insertAtBeginningCSLL(head, data);
//         return;
//     }

//     struct CSLLNode* temp = *head;
//     int count = 1;

//     while (count < pos - 1 && temp->next != *head) {
//         temp = temp->next;
//         count++;
//     }

//     if (count != pos - 1) {
//         printf("Position out of bounds.\n");
//         return;
//     }

//     newNode->next = temp->next;
//     temp->next = newNode;
// }

// 10 → 20 → 30 → (back to head)
// We insert 99 at position 2 (i.e., between 10 and 20).

// Before Insertion:
// (head)  
//   ↓
// ┌────────────┐    ┌────────────┐    ┌────────────┐
// │ data: 10   │ →  │ data: 20   │ →  │ data: 30   │
// └────────────┘    └────────────┘    └────────────┘
//        ↑                             ↓
//        └──────────────←──────────────┘


// After Allocating 99 and Finding Position
//     ->  temp = head
//     ->  count = 1
//     ->  We move till count == pos - 1
//     ->  So now temp points to node 10

// Insertion Rewiring
//     ->  newNode->next = temp->next → 99->next = 20    
//     ->  temp->next = newNode → 10->next = 99
    
// (head)
// ↓
// ┌────────────┐    ┌────────────┐    ┌────────────┐    ┌────────────┐
// │ data: 10   │ →  │ data: 99   │ →  │ data: 20   │ →  │ data: 30   │
// └────────────┘    └────────────┘    └────────────┘    └────────────┘
//      ↑                                                 ↓
//      └────────────────────────────←────────────────────┘


