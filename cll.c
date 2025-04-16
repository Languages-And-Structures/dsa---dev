// Circular Singly Linked List (CSLL)

//     ->  Operations:
//             ->  Creation, insertion (beginning, end, after value)
//             ->  Deletion (value/position)
//             ->  Traversal (infinite loop prevention)
//             ->  Applications (e.g., round-robin scheduling)


// Circular Doubly Linked List (CDLL)

//     ->  Operations:
//             ->  Similar to DLL but with circular pointer behavior
//             ->  Proper pointer management in circular scenarios
//             ->  Traversal (forward & reverse)
//             ->  Edge cases: 1-node list, full circle

// Feature                     | CSLL                      | CDLL

// Tail access                 | Requires traversal (O(n)) | Instant via head->prev (O(1))
// Memory per node             | 1 pointer                 | 2 pointers
// Bi-directional traversal    | No                        | Yes
// Simpler implementation      | Yes                       | Slightly more complex
// Insert at end speed         | Slower                    | Faster


// Aspect	                            CSLL	            CDLL

// Delete time         	        O(n) (find last node)	O(1) (direct via head->prev)
// Directional support	        Forward only	        Forward + Backward
// Pointer update complexity	Simpler (1 pointer)	    More (2 pointers)
// Space overhead per node	    Lower	                Higher (stores prev)
// Risk of dangling pointer	    Moderate	            Moderate


// Feature	                               CSLL	                CDLL

// Time Complexity	                O(n) (must traverse)	O(1) (use prev)
// Traversal needed	                Yes	                    No
// Pointer rewiring	                1 pointer	            2 pointers
// Risk of leak (if mishandled)	    High	                Medium


// Case	                CSLL handling	                    CDLL handling

// Empty list	        Print + return	                    Print + return
// One node	            Free node + head = NULL	            Free node + head = NULL
// Multiple nodes	    Traverse or use prev + free last	Use head->prev, adjust links


//     Case	                            CSLL	                        CDLL
\
// Insert at position 1	     Reuse insert at beginning	            Reuse insert at beginning
// Insert at last position   Traverse till last, handle links	    Traverse till tail, handle prev/next
// Insert in empty list	     Treated as insert at beginning	        Same
// Position > size + 1	     Rejected as "Position out of bounds"	Same