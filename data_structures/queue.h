#ifndef QUEUE_DYNAMIC_H
#define QUEUE_DYNAMIC_H

#include <stdio.h>
#include <stdlib.h>
#include "types.h"

/* MEMORY ALLOCATION FOR A NEW QUEUE */
Queue* NewQueue();

/* MEMORY DEALLOCATION OF THE QUEUE */
void FreeQueue(Queue**);

/* CHECK IF QUEUE IS EMPTY */
boolean EmptyQueue(Queue*);

/* INSERT AN ELEMENT IN THE QUEUE */
/* MEMORY ALLOCATION FOR THAT ELEMENT MUST BE DONE OUTSIDE THIS FUNCTION */
void AppendQueue(Queue*, NodeQueue*);

/* REMOVE AN ELEMENT OF THE QUEUE */
/* MEMORY DEALLOCATION OF THAT ELEMENT MUST BE DONE OUTSIDE THIS FUNCTION */
NodeQueue* ServeQueue(Queue*);

/* REMOVE OF ALL THE ELEMENTS OF THE QUEUE */
void ClearQueue(Queue*);

/* HOW MANY ELEMENTS ARE IN THE QUEUE */
int SizeQueue(Queue*);

/* WHO IS THE ELEMENT ON THE TOP OF THE QUEUE */
NodeQueue* FrontQueue(Queue*);

/* DISPLAY OF THE INFO OF ALL THE ELEMENTS ON THE QUEUE */
void PrintQueue(Queue*);

#endif


