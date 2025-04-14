// 1. What is a struct?

// A struct (structure) in C is a user-defined data type that groups multiple 
// variables of different types under one name.

// struct Point {
//     int x;
//     int y;
// };

// This creates a new type struct Point with two members.
// You can declare and use it like:

// struct Point p1;
// p1.x = 10;
// p1.y = 20;

// Memory Layout (struct)
// For:

// struct Data {
//     char a;   // 1 byte
//     int b;    // 4 bytes
//     char c;   // 1 byte
// };

// Memory is allocated sequentially, but aligned based on the largest 
// member’s alignment requirement (typically 4 bytes for int).

// Expected size: 12 bytes (with padding).

// | a | pad | pad | pad | b | b | b | b | c | pad | pad | pad |
// You can use sizeof(struct Data) to verify.


// 2. What is a union?

// A union is also a user-defined data type, but with a crucial difference:
// All members share the same memory location.
// Only one member can be valid at a time.

// Example:

// union Data {
//     int i;
//     float f;
//     char c;
// };

// All three variables use the same memory, and the size of the union is the 
// size of its largest member.

// Memory Layout (union)
// If:

// int i takes 4 bytes
// float f takes 4 bytes
// char c takes 1 byte

// sizeof(union Data) == 4

// All members start at the same offset, so writing to one overwrites the others.

//     Feature	                    struct	                        union

// Memory Allocation	    Separate for each member	    Shared among all members
// Access	                All members at once         	Only one valid at a time
// Size	                    Sum of sizes + padding	        Size of largest member
// Use Case	                Group related values	        Store one of many possible types
// Safety	                Safer; no overwrite	            Risk of undefined behavior

#include <stdio.h>

struct S {
    char a;    // 1 byte
    int b;     // 4 bytes
    char c;    // 1 byte
};

union U {
    int i;     // 4 bytes
    float f;   // 4 bytes
    char c;    // 1 byte
};

int main() {
    struct S s = { 'A', 100, 'B' };
    union U u;

    u.i = 65;
    printf("u.c = %c\n", u.c); // might print 'A' (same 0x41 value)

    return 0;
}


// Packing Structs (__attribute__((packed)))

// Disables padding, reduces memory size (used in embedded programming)
// Risk: can cause unaligned access on some platforms

struct __attribute__((packed)) Compact {
    char a;
    int b;
};

// Tagged Unions (struct + union combo)
// Used to build type-safe variant types.

struct Variant {
    int tag; // 0 = int, 1 = float
    union {
        int i;
        float f;
    } value;
};

