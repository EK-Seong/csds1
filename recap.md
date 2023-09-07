## Classes in Python
* Class is another type of object that has variables and functions similar to module
* - Functions in a class are called methods
* - A method takes its class object as the first and default argument
* All the types in Python are actually classes
* - int class, float class, str class, bool class
* - You can see their definitions by typing, for example, help(int)
* Class vs. Class object
* - A class is a blueprint, definition of its attributes and methods(but not real yet)
* - A class object is a class' instance(realization of  a blueprint)
* -  Example: TESLA model Y
* - - TESLA designed model Y's blueprint and produces numerous model Y objects according to the blueprint
* - - I can buy a model Y object but not the model Y blueprint
## Object-oriented Programming Principles
### Encapsulation : Contain related information in an object
* Reduce complexity and increase reusability
### Abstraction : Expose only high level interfaces to the outside world
- Reduce complexity and isolate impact of changes
### Inheritance : Child classes inherit data and behaviors from parent class
- Eliminatee redundant code
### Polymorphism : A single method acts in a different way depending on objects
- Escape from complex if/else statements

## Pointers in C
- A pointer variable contains an address of a memory object(e.g., variable)
- - \<type> *\<name>
- - - int *ptr; -> ptr is a variable that contains an address of an integer variable
- - - char *ptr; -> ptr is a variable that contains an address of a character variable
- Address operator & and indirection operator *
- - int intVariable = 10; //Assume that intVariable's address is 0xEE01
- - int *intPtr;
- - intPtr = \&intVariable;
- - - Now intPtr contains intVariable's address
- - - *intPtr is the value in the memory object that intPtr points to(i.e., intVariable's value, 10)
- - - "*intPtr = *intPtr + 2" is the same as "intVariable = intVariable + 2"
- Null pointers - A special case pointer that points to nothing
- - int *ptr;
- - ptr = NULL; // NULL is a specially defined preprocessor macro that contains a value 0
- - It is useful to initialize a pointer to NULL when it does not point anything yet
- Demystifying the syntax
- - Pointer declaration(e.g., int *ptr;)
- - - Declaring a variable ptr that, when the indirection operator * is applied to it, generates a value of type int
- - - That is, *ptr is integer type
- - Input library function - scanf("%d", &input);
- - - To change the value of the function argument "input", scanf must have the address of "input"
- - - If you omit &, C compliler will kindly give an error message
## Structures in C
* A convenient way of representing objects that are best repesented by combinarions of the basic data types
- - Similar to but different from class in that it does not have methods
- Definition - a studentType structure comprising 3 members
- > struct studentType{ \
  >   char name[10]; \
    >   int mideterm; \
    >   int final; \
    > };
- Consecutive memory allocation
- Typedef to relieve typing burden(typedef \<type>\<name>)
- > typedef struct studentType Student; \
  > - now there is a data type Student, which is synonymous with struct studentType
- Arrays of and pointers for structures?

## Stack vs. Heap
### Stack
* Grows upwards
* Allocation and deallocation are automatically done by the compiler
* Local variable access
* Faster and no fragmentation
### Heap
* Grows downwards
* Allocation and deallocation are manually done by the programmer
* Globla variable access
* Slower and fragmented

## Dynamic Memory Allocation in C
### Allocation: malloc function
* Parameter : Requested memory size(bytes)
* Reserve a contiguous memory block of the requested size in the heap space
* Return : a pointer jot the reserved block or NULL when failing to reserve the block(lack of memory)
* * Void pointer(void*) since the proper data type is not known
* * It is safe to check if the return is NULL or not
* * \<stdlib.h> needs to be included
* Heap grows downwards as more blocks are allocated
### Deallocation : free function
* Parameter : The pointer that malloc function returned
* Once a block is allocated on the heap, the block survives until we explicitly deallocate it
* * In contrast to variables in stack that are automatically added and removed

## Data Structures
### Array list
* A sequence of neighboring memory boxes
* * Know where an arbitrary(i-th) element is located, by using the neighboring rule
* Limitation : Fixed length and Expensive resizing
* * Make a brand-new array + copy all the existing elements
* Improvement : Resizing step adjustment
* Good for a dataset where data ...

### Linked list
* A list of nodes each of chich has a link to another node
* * Know only where the next element is located, by using the next pointer
* Limitation : Don't know what is where - Frequent navigation through the list
* Improvement : Caching and sentinel?
* Good for a dataset where data are frequently added or removed

### Queue : FIFO
### Stack : LIFO
### Hash in Python (? Don't remember this topic)
* Data Indexed Array
* * A data-indexed array has all possible data as its indices
* * in operation (x in di-array) can just return the value of di_array[x] : O(1)!
* * Infinite size?
* Data Indexed array with Chains
* * Each element is initially None but becomes a linked list when an item is added
* * fixed size? Imbalanced chin lengths?
* Hash Table
* * Data is hashed to be a valid index
* * Resizing
* - - Doubling, O(N)
* * Hash function
* * * Balanced chain length

### Trees
* A tree comprises a set of nodes that are connected(linked) to each other
* There is only one path between two nodes in a tree
#### Rooted tree
* There is one root node(at the top of the tree)
* Every node (except the root) has one parent - the first node on its path toward the root
* A node without a child is a leaf

#### Rooted binary tree
* Each node has at most two children nodes

#### Binary search tree
* A binary search tree is a rooted binary tree tht has the following two properties
* For every node x,
* * x's value is unique in the whole tree
* * Every node y in the left subtree of node x has value less than x's value
* * Every node z in the reight subtree of node x has value greater than x's value

### Graphs
* A graph comprises a set of nodes and a set of edges (including zero edge), each of which connects two nodes

#### Simple graph
* is such that does not have :
* Loop : an edge that connects a node to itself node, such as (v,v)
* Parallel edge : two edges that connects the same nodes, suchas e1=(v,w) and e2=(v,w)

#### Terms
* Vertex : a node : v
* Edge : a pair of vertices : (v,w) where v and w are vertices
* Two vertices which have an edge between are are adjacent
* A path is a sequence of vertices connected by edges
* A path with unique(non-repeated) vetices is a simple path
* * (v,w,y,v,z) is not simple but (v,w,y,z) is simple
* A cycle is a path where the first and last vertices are the same
* If there is a path between two vertices, the two vertices are connected
* An edge is either undirected(like a line) or directed(like an arrow)

## Algorithm