// Step 9: Search for a Value in a Doubly Linked List

// This operation scans the list and returns whether the value 
// exists — optionally its position.

// int search(struct Node* head, int key) {
//     int pos = 0;
//     struct Node* temp = head;

//     while (temp != NULL) {
//         if (temp->data == key) {
//             printf("Value %d found at position %d.\n", key, pos);
//             return 1;
//         }
//         temp = temp->next;
//         pos++;
//     }

//     printf("Value %d not found in the list.\n", key);
//     return 0;
// }

// What’s Happening?
//     ->  Begin from head, traverse using next
//     ->  Compare each node's data to the key
//     ->  Return early on match
//     ->  If loop ends, value wasn’t found

// DLL:
// [10] <-> [20] <-> [30] <-> [40]

//Call:
// search(head, 20);  // Output: found at position 1
// search(head, 99);  // Output: not found

// Operation	                Time Complexity

// Search (unsorted)	            O(n)
// Search (sorted)	                O(n), unless you switch to other data   
//                                  structures (like BSTs or skip lists)

// You can return the pointer to the node instead of a flag.
// Or return position or index.
// Or return count of occurrences for duplicates.
