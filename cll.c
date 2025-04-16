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