#ifndef STACK_DYNAMIC_H
#define STACK_DYNAMIC_H

#include <stdio.h>
#include <stdlib.h>
#include "types.h"

/* MEMORY ALLOCATION FOR A NEW STACK */
Stack* NewStack();

/* MEMORY DEALLOCATION OF THE STACK */
void FreeStack(Stack**);

/* CHECK IF STACK IS EMPTY */
boolean EmptyStack(Stack*);

/* INSERT AN ELEMENT IN THE STACK */
/* MEMORY ALLOCATION FOR THAT ELEMENT MUST BE DONE OUTSIDE THIS FUNCTION */
void PushStack(Stack*, NodeStack*);

/* REMOVE AN ELEMENT OF THE STACK */
/* MEMORY DEALLOCATION OF THAT ELEMENT MUST BE DONE OUTSIDE THIS FUNCTION */
NodeStack* PopStack(Stack*);

/* REMOVE OF ALL THE ELEMENTS OF THE STACK */
void ClearStack(Stack*);

/* HOW MANY ELEMENTS ARE IN THE STACK */
int SizeStack(Stack*);

/* WHO IS THE ELEMENT ON THE TOP OF THE STACK */
NodeStack* TopStack(Stack*);

/* DISPLAY OF THE INFO OF ALL THE ELEMENTS ON THE STACK */
void PrintStack(Stack*);

#endif