// Step 10: Count the Number of Nodes
// Simple utility to count how many nodes are currently in the list.

// Function Code

// int countNodes(struct Node* head) {
//     int count = 0;
//     struct Node* temp = head;

//     while (temp != NULL) {
//         count++;
//         temp = temp->next;
//     }

//     return count;
// }

// What’s Happening?
//     ->  Start at head
//     ->  Increment count as you move through each node
//     ->  Traverse till NULL

// Time & Space Complexity
// Metric	Value
// Time Complexity	O(n)
// Space Complexity	O(1)


// Step 11: Free/Destroy the Entire List
// Prevents memory leaks by deallocating all dynamically allocated nodes.

// Function Code

// void freeList(struct Node** head) {
//     struct Node* temp = *head;

//     while (temp != NULL) {
//         struct Node* next = temp->next;
//         free(temp);
//         temp = next;
//     }

//     *head = NULL;  // Avoid dangling pointer
// }


// ->  Always hold next before free(temp) to avoid losing the rest of the list
// ->  Use *head = NULL after freeing to prevent accidental reuse
// ->  Important when exiting a program or reinitializing the list

// Operation	  Cleanliness	        Purpose

// countNodes	    Stats	        Know size for bounds
// freeList	        Hygiene	        Prevent memory leaks