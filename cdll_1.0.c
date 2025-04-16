// Circular Doubly Linked List (CDLL)

// Structural Properties
//     ->  Every node has:
//             ->  next pointer (to next node)
//             ->  prev pointer (to previous node)
//     ->  It's circular:
//             ->  head->prev points to the tail
//             ->  tail->next points back to head
//     ->  This allows bidirectional traversal with no NULL

// Memory Layout Before and After Insertion

// Before Insertion
// Single node with self-pointing links:

// head
//  ▼
// ┌────────────────────┐
// │ data: 10           │
// │ prev: *            │◄────┐
// │ next: *            │─────┘
// └────────────────────┘

// Insertion: Insert 20 at Beginning
//     ->  Allocate new node
//     ->  Link newNode->next = head
//     ->  Link newNode->prev = head->prev (which is last node)
//     ->  Update head->prev->next = newNode
//     ->  Update head->prev = newNode
//     ->  head = newNode

// Key Pointers After :

// head
// ▼
// ┌────────────────────┐
// │ data: 20           │
// │ prev: 10           │◄────────────┐
// │ next: 10           │─────┐       │
// └────────────────────┘     │       │
//                            ▼       │
//           ┌────────────────────┐
//           │ data: 10           │
// ┌────────▶│ prev: 20          │
// │         │ next: 20           │◀────────┐
// │         └────────────────────┘         │
// └────────────────────────────────────────┘

// Memory Model

// Aspect	                            CSLL / CDLL

// Node allocation	                malloc from heap
// Local pointers	                On stack, e.g., temp, newNode
// Head pointer	                    Usually maintained globally or passed as **head
// Traversal	                    CSLL needs full traversal to find last node
// CDLL access	                    Uses head->prev to get last node instantly
// Efficiency	                    CDLL wins on insertion/deletion at both ends
// Cost	                            CDLL uses more memory (extra pointer per node)


//   Case	                            CSLL	                                    CDLL

// Empty list	            Set newNode->next = newNode	                Set next and prev to itself
// One node in list	        Handle self-reference loop carefully	    Self-loop both directions
// Insert in multi-node     Traverse (CSLL), or use head->prev (CDLL)	
