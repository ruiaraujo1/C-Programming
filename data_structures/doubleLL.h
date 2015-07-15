#ifndef DOUBLE_LINKED_LIST
#define DOUBLE_LINKED_LIST

#include <stdio.h>
#include <stdlib.h>
#include "types.h"


/* MEMORY ALLOCATION FOR A NEW LIST */
DoubleLinkedList* CreateList();

/* MEMORY DEALLOCATION OF THE LIST */
void FreeList(DoubleLinkedList**);

/* CHECK IF LIST IS EMPTY */
boolean EmptyList(DoubleLinkedList*);

/* GIVEN A POSITION, SETS THE "current" OINTER TO A CERTAIN NODE OF THE LIST */
void SetPosition(DoubleLinkedList*, position);

/* INSERT AN ELEMENT IN THE LIST */
/* MEMORY ALLOCATION FOR THAT ELEMENT MUST BE DONE OUTSIDE THIS FUNCTION */
void InsertList(DoubleLinkedList*, NodeDoubleLinkedList*, position);

/* REMOVE AN ELEMENT OF THE LIST */
/* MEMORY DEALLOCATION OF THAT ELEMENT MUST BE DONE OUTSIDE THIS FUNCTION */
NodeDoubleLinkedList* DeleteList(DoubleLinkedList*, position);

/* REMOVE OF ALL THE ELEMENTS OF THE LIST */
void ClearList(DoubleLinkedList*);

/* HOW MANY ELEMENTS ARE IN THE LIST */
int SizeList(DoubleLinkedList*);

/* DISPLAY OF THE INFO OF ALL THE ELEMENTS ON THE LIST */
void PrintList(DoubleLinkedList*);

#endif

