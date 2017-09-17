// some more on C structs
#include <stdio.h>
#include <stdlib.h> // standard library
#include <stdarg.h> // for variable number of args

struct dog {
    const char *name;
    const char *breed;
    int heightCm;
    int weightKg;
};

void printTheDog(struct dog theDog) {
    // do stuff with the dog.
    printf("%s is a %s and is %i high and weighs %i\n", theDog.name, theDog.breed, theDog.heightCm, theDog.weightKg);
}

void changeWeight(struct dog *theDog, int newWeight) {
    theDog->weightKg = newWeight;
    printf("%s now weighs %i\n", theDog->name, theDog->weightKg);
}

double average(int x, ...);

int main() {
    // another way to populate the values of a struct
    struct dog colcester = { "Colchester", "Jack Russell", 50, 10 }; // DESIGNATED INITALISER.
    printTheDog(colcester);

    // we may want to have a reference to the dog instead if we want to change a load of stuff
    // about a particular dog reference
    struct dog benji = { "Benji", "Sabbath", 60, 11 };
    changeWeight(&benji,15);

    // ^ DONT DO THAT THOUGH!!!
    // IF WE ARE EVER USING POINTERS TO AN OBJECT, THE OBJECT SHOULD BE ALLOCATED MEMORY ON THE HEAP
    // see below

    return 0;
}


 int* somePointer() {
     int y = 7;
     // THIS IS BAD!
     return &y;
     // because y is only being stored on the stack, it will 
     // fall out of scope when we return, and another function may modify the
     // value in its memory location.
 }

static void moreCharPointer() {
	char* name = "Jonny"; // should never use, this is just backwards compatiblity for...
	const char *name = "Jonny"; // where this is a pointer to an immutable "Jonny" on the stack.
	
	char name[] = "Jonny"; // creates a copy of "Jonny" on the stack, which is mutable, only with enough space for the current length string though.
	
	char *name = (char*)malloc(50*sizeof(char)); // make enough room for 50 chars
	*name = "joooooon";
	strncat(*name, "foooooooooood"); // it's good because we have created enough room on the heap
}

double average(int x, ...) {
	va_list valist;
	double sum = 0.0;
	int i;
	
	/* initialize valist for num number of arguments */
	va_start(valist, num);
	
	/* access all the arguments assigned to valist */
	for (i = 0; i < num; i++) {
		sum += va_arg(valist, i);
	}
	
	/* clean memory reserved for valist */
	va_end(valist);
	
	return sum/num;
}
