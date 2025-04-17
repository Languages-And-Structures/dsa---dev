// ->  A singly linked list where the last node’s next pointer points 
//     back to the head, forming a loop.
// ->  Only next pointer per node.
// ->  No built-in concept of a tail — traversal is needed to locate 
//     the last node.
// ->  Unidirectional traversal only.

// Let’s insert 30 at the end of this list:
// 10 → 20 → (back to head)

// Steps :
//     ->  Allocate memory for new node using malloc.
//     ->  Set newNode->data = 30
//     ->  If list is empty:
//         ->  newNode->next = newNode
//         ->  *head = newNode
//         ->  Return
//     ->  Else:
//         ->  Use temp = *head and loop until temp->
//         next == *head (i.e., last node)
        
//         ->  Set:
//             ->  temp->next = newNode
//             ->  newNode->next = *head

// Before Insertion:

// head
// ↓
// ┌────────────┐     ┌────────────┐
// │ data: 10   │ --> │ data: 20   │
// │ next:      │     │ next: head │
// └────────────┘     └────────────┘

// After Insertion:

// head
// ↓
// ┌────────────┐     ┌────────────┐     ┌────────────┐
// │ data: 10   │ --> │ data: 20   │ --> │ data: 30   │
// │            │     │            │     │ next: head │
// └────────────┘     └────────────┘     └────────────┘

// Item          Location            Description

// *head       | Stack or Global   | Pointer to first node
// newNode     | Heap              | Dynamically allocated node
// temp        | Stack             | Traversal pointer (temporary use)

// Operation                     Time

// Insert at end (no tail)     | O(n)
// Space per node              | One next pointer
// Ideal if                    | You don’t need fast insertions at end


// Case	                        Handling

// Empty list	        newNode->next = newNode; *head = newNode;
// One node	        Set temp = *head, then update next pointers
// Multiple nodes	    Traverse till temp->next == head












































