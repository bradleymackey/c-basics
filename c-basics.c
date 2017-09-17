#include <stdio.h>

#define BOOL char
#define TRUE 1
#define FALSE 0


// in the header...
extern int usemeeverywhere;
// in the implementation...
int usemeeverywhere;
// * this allows us to use it anywhere we import this file.


// "this variable is about to be used a lot, we reccomend you keep this in a CPU register."
// only a suggestion though, the program may not do so at runtime.
register int a = 9;


 /* function declaration, they all must be declared in a header or at the top of the file */ 
int foo(int bar);

int main() {
	return 0; // function exited normally.
}

// ****** SIMPLE DATA TYPES *******

int a = 3;
long i = 3243; // same as "long int"
long int j = 2342342342; // same as "long"
long long y = 437458375345345; // same as "long long int"
long long int r = 743845683457634; // same as "long long"
short someShort = 65535; // same as "short int"
short int someOtherShort = 65535; // same as "short"
float b = 4.5;
double c = 4.25;
long double lDouble = 3.324234342; // more precision still.

// ints, or long, or long long, or short can be signed or unsigned.
signed int sint = -342;
unsigned int usint = 3466;
signed short int minusThree = -3;
unsigned long long int bigNub = 485648723468;


void someFunction() {
	// STATIC VARIABLE, will maintain its value if this function gets called more than once.
	// everytime we call this function it's value will get 1 bigger, i.e. 23,24,25,26...
	static int pooper = 23;
	pooper++;
	// SEE BELOW FOR A STATIC FUNCTION...
}

int a = 1, b = 2, c = 3;
a = b - 2 * 3;
printf("%d",a);

int numbers[10]; // an array of 10 integers

int marks[10];
char vowels[] = {'A','E','I','O','U'}; // compiler knows how many elements, we don't need to specify.
char vowels[][5] = {
	{'A','E','I','O','U'},
	{'a','e','i','o','u'}
};

for(int i = 0; i < 2; i++) {
	for(int j = 0;j<5;j++) {

	}
}

switch (a) {
	case 4:
		printf("it's 4\n");
		break;
	default:
		printf("it's something else");
		break;
}

#pragma mark Strings
// ******* STRINGS ********

char *name = "John Smith"; // pointer to a character array defines a simple string. READ ONLY

char name[] = "John Smith"; // character array. MUTABLE
char name[11] = "John Smith"; // SAME AS ABOVE (complier can interpret the size though)

char *name = "John Smith";
int age = 27;
printf("%s is %d years old.\n", name, age); // "John Smith is 27 years old."

strlen(name); // length of a string

if (strncmp(name, "John Smith",11) == 0) { // strncmp compares 2 strings up to some max comparison length, returns 0 if they are equal, another number otherwise. (UNSAFE VERSION CALLED strcmp).
	// is john smith
} else {
	// is not
}

char dest[20] = "Hello"; // make array bigger than we need to because we are about to concat
char scr[20] = "World";

strncat(dest,scr,3); // append 3 characters of scr to dest -> "HelloWor"
strncat(dest,scr,20); // -> "HelloWorWorld"

/// ******* FOR/WHILE LOOPS *******

int numberArray[] = {1,2,3,4,5,6,7,8,9,10}; // compiler can interpret size
int factorial = 1;
for (int i = 0; i < 10; i++) {
	factorial *= numberArray[i];
}

while (x < 10) {
	x++;
	continue;
	break;
}


// *********** FUNCTIONS - (very simple in C) ************
// MUST BE DECLARED BEFORE THEY CAN BE USED (in header file or at top of doucment.)
// functions can have a fixed or variable number of arguments.
// they can return 1 thing, or they can return nothing.

int foo(int bar) {
    return bar * 2;
}

void moo() {
    // do something
}

// NOT LIKE STATIC IN OTHER LANGUAGES!!
// static here basically means 'private'
// so that importing files cannot access this function
static void mooSecret() {
    // do something private
}

// ********** POINTERS ***********
// hold a memory address to some value, rather than the value itself.

// pointers make use of the HEAP (different to the heap data structure)

void pointers() {

    // * STRINGS AS POINTERS *
    // called C-Strings to differentiate them from other strings when mixed with C++

    char *name = "John";
    // 1. allocates local (stack) variable to 'name', which is a pointer to a single character
    // 2. It causes the string "John" to appear somewhere in the program memory
    // 3. It initializes the name argument to point to where the J character resides at (which is followed by the rest of the string in the memory).

    // If we try to access the name variable as an array, 
    // it will work, and will return the ordinal value of the character J, 
    // since the name variable actually points exactly to the beginning of the string.

    // Since we know that the memory is sequential, 
    // we can assume that if we move ahead in the memory 
    // to the next character, we'll receive the next letter
    // in the string, until we reach the end of the string,
    // marked with a null terminator (the character which it's ordinal value is 0, noted as \0).

    // * DEREFERENCING *

    // Dereferencing is the act of referring to where the pointer points at, instead of the memory address.

    // We are already using dereferencing in arrays - but we just didn't know it yet.
    // The brackets operator - [0] for example, accesses the first item of the array. 
    // And since arrays are actually pointers, accessing the first item in the array is the same as dereferencing a pointer.

    // Dereferencing a pointer is done using the asterisk operator *.

    /* define a local variable a */
    int a = 1;

    /* define a pointer variable, and point it to a using the & operator */
    int *pointer_to_a = &a;
    // a = integer data
    // &a = memory location address e.g. 0xff54512fc

    printf("The value a is %d\n", a);
    printf("The value of a is also %d\n", *pointer_to_a);


    // a bit more on referencing and dereferencing:

    int  c1;
    int *p1;
    c1 = 5;
    p1 = &c1; // '&' gets the memory location of a value.
    //p1 references c1
	p1 // memory location of c1
	*p1 // value of c1

    int n1;
    n1 = (*p1); // use the star to access the value stored at a pointer.

    // & is the reference operator and can be read as “address of”.
    // * is the dereference operator and can be read as “value pointed by”.
}

// ***** STRUCTURES ********

// The most basic example of structures are points, which are a single entity that contains two variables - x and y. 
// Let's define a point in a two-dimensional point:

struct point {
    int x;
    int y;
}

struct point p;
p.x = 10;
p.y = 9;

// ** Typedefs **
// define new types

typedef struct {
    int x;
    int y;
} point;

point p; // don't need to use 'struct' now!

// they can also hold pointers

typedef struct {
    char *brand;
    int model;
} vehicle;

vehicle mycar;
mycar.brand = "Ford";
mycar.model = 2016;


// ******** Function arguments by reference. **********
// Function arguments are passed by value, which means they are copied in and out of functions.
// But what if we copied pointers to values instead of the values themselves?
// This will enable us to give functions control over variables and structures of the parent functions, and not just a copy of them.

// THIS WON'T WORK, we are incrementing a copy. 'n' is the raw 'int'.
void addone(int n) {
    n++;
}

// THIS WILL WORK, we are incrementing the same value. 'n' is just a pointer to an 'int'.
void addone(int *n) {
    (*n)++;
}

// * pointers to structures *

void move(point *p) {
    (*p).x++;
    (*p).y++;
}

// However, if we wish to dereference a structure and access one of it's internal members, 
// we have a shorthand syntax for that, because this operation is widely used in data structures.

void move(point *p) {
    p->x++; // the `->` means deref the left and then get the variable on the right from this de-reffed struct.
    p->y++;
}


// ********* DYNAMIC ALLOCATION **********

// Dynamic allocation of memory is a very important subject in C - 
// it allows building complex data structures such as linked lists. 

// Allocating memory dynamically helps us to store data without
// initially knowing the size of the data in the time we wrote the program.

// To allocate a chunk of memory dynamically, we have to have a pointer ready -
// which will store the location of the newly allocated memory.

// We can access memory that was allocated to us using that same pointer, 
// and we can use that pointer to free the memory we got, once we finish using it.

typedef struct {
    char *name;
    int age;
} person;

// To allocate a new person in the myperson argument, we use the following syntax:

person* myperson = (person*)malloc(sizeof(person)); // type-cast to a person pointer. (because apparently malloc returns a void pointer)

// This tells the compiler that we want to dynamically allocate 
// just enough to hold a person struct in memory,
// and then return a pointer to the newly allocated data.

// Note that sizeof is not an actual function, 
// because the compiler interprets it and translates 
// it to the actual memory size of the pointer struct.

myperson->name = "John";
myperson->age = 18;

// After we are done using the dynamically allocated struct, we can release it using free:

free(myperson);


// THE HEAP DOES NOT DO SELF CLEANING/ GARBAGE COLLECTION, ITS UP TO THE PROGRAMMER:

void usingTheHeap() {
    int *p;
    p = (int*)malloc(sizeof(int)); // returns some random address to some free memory on the heap, big enough for the thing we requested.
    *p = 10; // saves 10 to some memory location in the heap
    p = (int*)malloc(sizeof(int));
    *p = 20; // saves 20 to some memory location in the heap

    // THE 10 IS STILL THERE, BUT WE HAVE NOW LOST ITS POINTER!!

    // we need to implement like this instead:
    int *p;
    p = (int*)malloc(sizeof(int)); 
    *p = 10; 
    free(p); // FREE THE OLD MEMORY LOCATION BEFORE WE LOSE THE POINTER (and cause a leak).
    p = (int*)malloc(sizeof(int));
    *p = 20; 
    free(p);

    p = (int*)malloc(20*sizeof(int)); // allocate a big, contigous block of memory for 20 ints
    // to access the different memory locations, we have multiple notation for the same basic things:
    *p // base value
    p[0] //also base value
    *(p+1) // the next value
    p[1] // also the next value etc...

    // we can read and write to these memory locations.

    // MALLOC returns a void pointer (void*) so it generally needs to be type casted into the type that we need to use.

    // instead of doing something like this:
    malloc(3*sizeof(int));
    // we can do this (THEY ARE THE SAME [almost]):
    calloc(3,sizeof(int));

    // malloc does not alter the memory it assigns when we get it (i.e. previous data may be in there)
    // calloc 0s out all the data before we can use it

    // if you try to write to a memory location after you have freed it, WEIRD THINGS MAY HAPPEN.
    // this is because some other part of our program may be using it and if we used it something
    // may mess up in another part of our code.

    // REALLOC:
    int *A = (int*)calloc(3,sizeof(int));
    // we want it to be a little bigger (10 ints instead of 3)
    int *B = (int*)realloc(A,10*sizeof(int));

    // if the heap is in a state such that it can just increase the size of A, it will.
    // if it needs to move to a new location, it does all the heavy lifting for us:
    // [copy A to new location with more space, deallocate the old A]

    realloc(A,0); // equivilent to free(A)
    realloc(NULL,sizeof(int)) // equivilant to malloc
}

// ****** ARRAYS AND POINTERS *********

void arraysAndPointers() {
    char c = 'C';
    char *pc = &c; // remember! `&c` gets the address of c and `pc` is just a pointer, holding a memory address. 

    // Here, c is a scalar variable that can store only a single value. 
    // However, you are already familiar with arrays that can hold 
    // multiple values of the same data type in a contiguously allocated memory block.
    // So, you might wonder, can we have pointers to arrays too? 
    // Indeed, we can.

    char vowels[] = {'A', 'E', 'I', 'O', 'U'};
    char *pvowels = &vowels;
    int i;

    // Print the addresses
    for (i = 0; i < 5; i++) {
        printf("&vowels[%d]: %u, pvowels + %d: %u, vowels + %d: %u\n", i, &vowels[i], i, pvowels + i, i, vowels + i);
    }

    // Print the values
    for (i = 0; i < 5; i++) {
        printf("vowels[%d]: %c, *(pvowels + %d): %c, *(vowels + %d): %c\n", i, vowels[i], i, *(pvowels + i), i, *(vowels + i));
    }

    // ** Dynamic Memory Allocation for Arrays **
    // By now we know that we can traverse an array using pointers. 
    // Moreover, we also know that we can dynamically allocate (contiguous) 
    // memory using blocks pointers. 
    // These two aspects can be combined to dynamically allocate memory for an array.
    
    // Allocate memory to store five characters
    int n = 5;
    char *pvowels = (char *) malloc(n * sizeof(char));
    int i;

    pvowels[0] = 'A';
    pvowels[1] = 'E';
    *(pvowels + 2) = 'I';
    pvowels[3] = 'O';
    *(pvowels + 4) = 'U';

    for (i = 0; i < n; i++) {
        printf("%c ", pvowels[i]);
    }

    printf("\n");

    free(pvowels);
}

// ***** A bit more on structs/typedef *****

// --- 1 ---
// define 'Person'
struct Person {
    int age;
    char *name;
};

// create a new name variable
struct Person *me;

// --- 2 ---

// DO THEM BOTH AT ONCE
struct Person {
    int age;
    char *name;
} me;

// also create new instances in the same way
struct Person *timTheAssMan;

// --- 3 ---

// we can use typedef to simply give a new name to an existing type

typedef struct Person AwesomePerson;

// allows us to create one every time without putting 'struct':
AwesomePerson *jueywuey;

// --- 4 ---

// this can be combined with the struct definition:

typedef struct {
    int age;
    char *name;
} AwesomePerson;

// this can also be done while naming the struct, but the first name will be pointless, since we never need to use it
// WITH THE EXCEPTION OF REFERENCING ITSELF WITHIN THE STRUCT

typedef struct Person {
    int age;
    char *name;
} AwesomePerson;

// to create an instance we just call 'AwesomePerson', no need to refer to 'Person'.

AwesomePerson *sally;

// --- 5 ---

// just picture the typedef struct as..

typedef struct {...} TypeName; 
// where the struct is just some old type name.

// --- 6 ---

// if you don't want to name a struct, you must use it immediatly

struct {
    int x;
    int y;
} myCoordinate;

// --- 7 ---

// putting an '_t' after a type name is just convention that makes clear that 
// this is a type name, rather than a variable name.


// **** LINKED LISTS *****


// --- 1 ---
// create the node type

typedef struct node {
    int val;
    struct node *next;
} node_t;


// --- 2 ---
// create the head and its next element

node_t *head = (head*)malloc(sizeof(node_t)); // get a pointer so some memory we can use in the heap.
if (head == NULL) { 
    // remember, malloc returns NULL if we cannot find any space to allocate.
    return 1;
}
head->val = 1;
head->next = (head*)malloc(sizeof(node_t));
head->next->val = 2;
head->next->next = NULL;


// iterating over the list

void print_list(node_t *head) {
    node_t *current = head;
    while (current != NULL) {
        printf("%d\n",current->val);
        current = current->next;
    }
}

// adding item to the end of the list

void push(node_t *head, int val) {
    node_t *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    // now we can add a new variable
    current->next = (node_t*)malloc(sizeof(node_t));
    current->next->val = val;
    current->next->next = NULL;
}

// adding item to the begining of the list

// 1. create new item and set value
// 2. link item to point to head of the list
// 3. set the head to be our new item

void push(node_t **head, int val) {
    node_t *new_node = (node_t*)malloc(sizeof(node_t));

    new_node->val = val;
    new_node->next = *head; // deref one level, so we can get the POINTER TO THE HEAD
    *head = new_node; // pointer to the head = our new node.
}

// removing the first item (popping)

int pop(node_t **head) {
    int retval = -1; // local return value
    node_t *next_node = NULL;
    if (*head == NULL) { // the head is null!
        return -1;
    }
    next_node = (*head)->next; 
    retval = (*head)->val;
    free(*head); // free the memory taken up by the head OBJECT [free memory at this address]
    *head = next_node; // set the head ADDRESS to point to the next node [pointer to head = pointer to the next_node]

    return retval;
}


// removing the last item

// Removing the last item from a list is very similar to adding it to the end of the list, 
// but with one big exception - since we have to change one item before the last item, 
// we actually have to look two items ahead and see if the next item is the last one in the list:

int remove_last(node_t *head) {
    int retval = 0;
    /* if there is only 1 item in the list, remove it */
    if (head->next == NULL) {
        retval = head->val;
        free(head);
        return retval;
    }

    /* get to the last node in the list */
    node_t *current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    /* now current points to the last item of the list, so let's remove current->next */
    retval = current->next->val;
    free(current->next);
    current->next = NULL;
    return retval;
}

// removing a specific item

// 1. Iterate to the node before the node we wish to delete
// 2. Save the node we wish to delete in a temporary pointer
// 3. Set the previous node's next pointer to point to the node after the node we wish to delete
// 4. Delete the node using the temporary pointer

int remove_by_index(node_t **head, int n) {
    int i = 0;
    int retval = -1;
    node_t *current = *head;
    node_t *temp_node = NULL;

    if (n == 0) {
        return pop(head); // see 2 functions up
    }

    for (int i = 0; i<n-1;i++) {
        if (current->next == NULL) {
            return -1;
        }
        current = current->next;
    }

    temp_node = current->next;
    retval = temp_node->val;
    current->next = temp_node->next;
    free(temp_node);

    return retval;
}

// removing by value

// (remove first item in the list that has the value 'val')

int remove_by_value(node_t **head, int val) {
    int retval = -1;
    node_t *current = *head;
    node_t *temp_node = NULL;

    /* if the head contains the current val */
    if (current->val == val) {
        return pop(head);
    }

    /* check all the next nodes */
    while (current->next->val != val) {
        if (current->next == NULL) {
            return -1;
        }
        current = current->next;
    }

    /* do the little dance to remove the node */
    temp_node = current->next;
    retval = temp_node->val;
    current->next = temp_node->next;
    free(temp_node);

    return retval;
}


// ******** UNIONS ***********

// unions are a lot like structs
// ALTHOUGH
// instead of each variable having its own memory, a union allows for multiple names for the same variable

// i.e. YOU ARE ONLY SUPPOSED TO USE ONE OF THE ELEMENTS
// BECAUSE THEY'RE ALL STORED AT THE SAME SPOT.
// ----
// THIS IS USEFUL WHEN WE WANT TO STORE SOMETHING THAT COULD BE ONE OF SEVERAL TYPES.
// whereas structs keep memory for ALL of the objects.

union foo {
    int a; // can't use both a and b at once.
    char b;
};

struct bar {
    int a; // CAN use both a and b simultaneously
    char b;
};

union foo x;
x.a = 3; // OK
x.b = 'c'; // NO!!! this affects the value of x.a!
// which part of x.a gets overwritten depends on the size of int and char respectivley
// and also on the endian byte-order.

struct bar y;
y.a = 3; // OK
y.b = 'c'; // OK

union intParts {
    int theInt;
    char bytes[sizeof(int)];
};

// this allows us to look at each byte individually, without casting a pointer and using pointer arithmetic.

union intParts parts;
parts.theInt = 5968145; // arbitrary number > 255 (1 byte)

printf("The int is %i\nThe bytes are [%i, %i, %i, %i]\n",
parts.theInt, parts.bytes[0], parts.bytes[1], parts.bytes[2], parts.bytes[3]);


// vs

int theInt = parts.theInt;
printf("The int is %i\nThe bytes are [%i, %i, %i, %i]\n",
theInt, *((char*)&theInt+0), *((char*)&theInt+1), *((char*)&theInt+2), *((char*)&theInt+3));


// Combining this with a structure allows you to create a "tagged" 
// union which can be used to store multiple different types, one at a time.

// For example, you might have an "number" struct, but you don't want to use something like this:

struct operator {
    int intNum;
    float floatNum;
    int type;
    double doubleNum;
};

// ^ lots of memory required for all those variables! so use this:

typedef struct {
    int type;
    union { // enough memory reserved for the largest object in the union.
        int intNum;
        float floatNum;
        double doubleNum;
    } types;
} operator;

operator op;
op.type = 0; // int, would probably be better represented as an ENUM tbh.
op.types.intNum = 352;

// if you dont give the union a name, the members are accessed directly from the struct:

typedef struct {
    int type;
    union { // enough memory reserved for the largest object in the union.
        int intNum;
        float floatNum;
        double doubleNum;
    };
} operator;

operator op;
op.type = 0;
op.intNum = 352;

// ------ another, more useful feature -------
// when you always have multiple variables of the same type, 
// and you want to be able to use both names (for readability) 
// and indexes (for ease of iteration)

union Coins {
    struct {
        int quarter;
        int dime;
        int nickel;
        int penny;
    };
    int coins[4];
}

union Coins change;
for (int i = 0; i < sizeof(change)/sizeof(int); i++) {
    scanf("%i",change.coins + i);
}
printf("There are %i quarters, %i dimes, %i nickels, and %i pennies\n",
    change.quarter, change.dime, change.nickel, change.penny);

// they are often used to cast between binary representations of integers and floats

union {
    int i;
    float f;
} u;

u.f = 3.14159f;
printf("As integer: %08x\n", u.i);



// ********* POINTER ARITHMETIC ************

// increment pointer with ++
// decrement pointer with --

 int intarray[5] = {10,20,30,40,50};

    int i;
    for(i = 0; i < 5; i++)
        printf("intarray[%d] has value %d - and address @ %x\n", i, intarray[i], &intarray[i]);


// we can also add, subtract and compare pointers!

// remember the pointers are just memory addresses!

// ********** FUNCTION POINTERS **************

// Why point to a function? - we can just refer to a function by name: funcMeUp()

// Now imagine the sort function where you need to sort an array. 
// Sometimes you want to order array elements in an ascending order or decending order. 
// How would you choose? Function pointers!

// SYNTAX:
void (*pf)(int);
// *pf is the pointer
// void is the return type
// int is an argument

// another example:
char* (*pf)(int*)


// ---- Time for some real code! ----

void someFunction(int arg) {
    // TODO STUFF
}

int main() {
     void (*pf)(int);
     pf = &someFunction; // refer to the function
     (pf)(5); // call the function using a pointer
}


// Remember sort() we talked about earlier?
// We can do the same with it. 
// Instead of ordering a set in an ascending way we can do the opposite using our own comparison function as follows:

#include <stdio.h>
#include <stdlib.h> //for qsort()

int compare(const void* left, const void* right)
{
    return (*(int*)right - *(int*)left);
    // go back to ref if this seems complicated: http://www.cplusplus.com/reference/cstdlib/qsort/
}
main()
{
    int (*cmp) (const void* , const void*);
    cmp = &compare;

    int iarray[] = {1,2,3,4,5,6,7,8,9};
    qsort(iarray, sizeof(iarray)/sizeof(*iarray), sizeof(*iarray), cmp);

    int c = 0;
    while (c < sizeof(iarray)/sizeof(*iarray))
    {
        printf("%d \t", iarray[c]);
        c++;
    }
}

// --- a tad bit of info ---

const // constant
const volatile // i will not change it, but something else might i.e. it will be different every time I read it.


