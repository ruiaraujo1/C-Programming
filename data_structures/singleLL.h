#ifndef SINGLE_LINKED_LIST
#define SINGLE_LINKED_LIST

#include <stdio.h>
#include <stdlib.h>
#include "types.h"


/* MEMORY ALLOCATION FOR A NEW LIST */
LinkedList* CreateList();

/* MEMORY DEALLOCATION OF THE LIST */
void FreeList(LinkedList**);

/* CHECK IF LIST IS EMPTY */
boolean EmptyList(LinkedList*);

/* GIVEN A POSITION, CREATES AND RETURNS A POINTER TO A CERTAIN NODE OF THE LIST */
NodeLinkedList* SetPosition(LinkedList*, position);

/* INSERT AN ELEMENT IN THE LIST */
/* MEMORY ALLOCATION FOR THAT ELEMENT MUST BE DONE OUTSIDE THIS FUNCTION */
void InsertList(LinkedList*, NodeLinkedList*, position);

/* REMOVE AN ELEMENT OF THE LIST */
/* MEMORY DEALLOCATION OF THAT ELEMENT MUST BE DONE OUTSIDE THIS FUNCTION */
NodeLinkedList* DeleteList(LinkedList*, position);

/* REMOVE OF ALL THE ELEMENTS OF THE LIST */
void ClearList(LinkedList*);

/* HOW MANY ELEMENTS ARE IN THE LIST */
int SizeList(LinkedList*);

/* DISPLAY OF THE INFO OF ALL THE ELEMENTS ON THE LIST */
void PrintList(LinkedList*);

#endif
