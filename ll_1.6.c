// Step 2: Insert at End

// void insertAtEnd(struct Node** head, int data) {
//     struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//     newNode->data = data;
//     newNode->next = NULL;

//     if (*head == NULL) {
//         newNode->prev = NULL;
//         *head = newNode;
//         return;
//     }

//     struct Node* temp = *head;
//     while (temp->next != NULL)
//         temp = temp->next;

//     temp->next = newNode;
//     newNode->prev = temp;
// }


// What’s Happening Internally?

//     ->  Allocate and initialize a new node.
//     ->  If list is empty, this new node becomes the head.
//     ->  Else, traverse to the last node (temp).
//     ->  Update temp->next = newNode
//     ->  Set newNode->prev = temp

// Initial list:
// head → [10] <-> [20] <-> [30] → NULL

// Call:
// insertAtEnd(&head, 40);

// Diagram (Before and After)
// Before:
// head → [10] <-> [20] <-> [30]

// After:
// head → [10] <-> [20] <-> [30] <-> [40]

// [40].prev = address of 30
// [30].next = address of 40
// [40].next = NULL

// 1. Avoid Memory Leaks on Traversal
//     If a pointer like temp is lost or not updated correctly, malloc()'d memory 
//     becomes inaccessible, causing a memory leak.

// 2. Tail Pointer Optimization
//     If frequent end-inserts are expected:
//         ->  Keep a tail pointer to avoid O(n) traversal.
//         ->  End insert becomes O(1) instead of O(n).

// 3. Traverse Safely
//     Always check temp != NULL before dereferencing temp->next to avoid segfaults 
//     in bad usage scenarios.

// 4. Multi-Threading Risk
//     If multiple threads are appending to the list, insertions must be guarded 
//     using a mutex lock.

// 5. Watch for Infinite Loops
//     If you mistakenly update temp->next = newNode before moving temp, and then 
//     reuse temp, you risk a circular loop or crash.

