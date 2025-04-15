// Step 3: Insert After a Given Node (by Value)

// This function inserts a new node after the first occurrence of 
// a given value in a doubly linked list.

// void insertAfterValue(struct Node* head, int key, int data) {
//     struct Node* temp = head;

//     while (temp != NULL && temp->data != key)
//         temp = temp->next;

//     if (temp == NULL) {
//         printf("Key %d not found.\n", key);
//         return;
//     }

//     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//     newNode->data = data;

//     newNode->next = temp->next;
//     newNode->prev = temp;

//     if (temp->next != NULL)
//         temp->next->prev = newNode;

//     temp->next = newNode;
// }

// What’s Happening?
//     ->  Traverse to the first node with value == key
//     ->  Allocate and initialize a new node
//     ->  Link newNode->next = temp->next
//     ->  Link newNode->prev = temp
//     ->  If temp->next exists, back-link its prev to newNode
//     ->  Set temp->next = newNode

// List before insertion:
// head → [10] <-> [20] <-> [30]

// Now do:
// insertAfterValue(head, 20, 25);

// Diagram (Before and After)
// Before:
// [10] <-> [20] <-> [30]

// After:
// [10] <-> [20] <-> [25] <-> [30]

// Pointer updates:
// [20].next = 25
// [25].prev = 20
// [25].next = 30
// [30].prev = 25

// 1. Node Exists Check
// if (temp == NULL)
// Important to avoid crashing when the key doesn’t exist.

// 2. Middle vs. End Case Handling
//     ->  If inserting after the last node, temp->next == NULL, and we don’t 
//         update temp->next->prev
//     ->  This check ensures safety:
//     if (temp->next != NULL)
//     temp->next->prev = newNode;

// 3. Avoid Memory Leaks or Corruption
// Make sure:
//     ->  newNode->prev is correctly linked
//     ->  temp->next = newNode is assigned after setting other pointers
//     ->  Freeing or reassigning nodes prematurely can corrupt the list

// 4. No Update to Head
// Unlike insert at beginning, this function never modifies head, so no need for double pointer

