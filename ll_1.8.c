// Step 4: Insert Before a Given Node (by Value)

// This operation inserts a new node before the first node that contains the given value.
// void insertBeforeValue(struct Node** head, int key, int data) {
//     if (*head == NULL) {
//         printf("List is empty.\n");
//         return;
//     }

//     struct Node* temp = *head;

//     // If inserting before head
//     if (temp->data == key) {
//         struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//         newNode->data = data;
//         newNode->prev = NULL;
//         newNode->next = temp;

//         temp->prev = newNode;
//         *head = newNode;
//         return;
//     }

//     while (temp != NULL && temp->data != key)
//         temp = temp->next;

//     if (temp == NULL) {
//         printf("Key %d not found.\n", key);
//         return;
//     }

//     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//     newNode->data = data;
//     newNode->next = temp;
//     newNode->prev = temp->prev;

//     temp->prev->next = newNode;
//     temp->prev = newNode;
// }

// What’s Happening Internally?
// 1. If the list is empty — do nothing.
// 2. If key is found at the head node:
//     ->This becomes like “Insert at Beginning”
//     ->Head must be updated.
// 3. Else:
//     ->Traverse until temp->data == key
//     ->Insert newNode before temp:
//         ->newNode->next = temp
//         ->newNode->prev = temp->prev
//         ->temp->prev->next = newNode
//         ->temp->prev = newNode

// Initial DLL:
// [10] <-> [20] <-> [30]

// Call:
// insertBeforeValue(&head, 20, 15);

// Diagram (Before and After)
// Before:
// [10] <-> [20] <-> [30]

// After:
// [10] <-> [15] <-> [20] <-> [30]

// // Pointer updates:
// [15].prev = 10
// [15].next = 20
// [10].next = 15
// [20].prev = 15

//     Scenario	                  Handled?

// List is empty	                yes
// Key is at head (1st node)	    yes
// Key not found	                yes
// Only one node in the list	    yes

// ->  You **must use struct Node** because head might change 
//     (if inserting before head)
// ->  temp->prev->next must be updated before you overwrite
//     temp->prev — pointer overwrite order matters
// ->  Function is more delicate than "insert after" because
//     you modify two existing nodes on both sides



