/************************
ALL THE DATA TYPES USED
************************/
#ifndef TYPES_H
#define TYPES_H

#define TRUE 1
#define FALSE 0

typedef int boolean;

typedef int position;

typedef int TYPE;



typedef struct NODE_STACK NodeStack;

struct NODE_STACK{
	TYPE info;
	NodeStack *next;
}; 

typedef struct {
	NodeStack *top;
} Stack;



typedef struct NODE_QUEUE NodeQueue; 

struct NODE_QUEUE{
	TYPE info;
	NodeQueue *next;
};

typedef struct {
	NodeQueue *head;
	NodeQueue *tail;
} Queue;



typedef struct NODE_LINKED_LIST NodeLinkedList; 

struct NODE_LINKED_LIST{
	TYPE info;
	NodeLinkedList *next;
};


typedef struct {
	NodeLinkedList *head;
	int count;
} LinkedList;



typedef struct NODE_DOUBLE_LINKED_LIST NodeDoubleLinkedList;

struct NODE_DOUBLE_LINKED_LIST {
	TYPE info;
	NodeDoubleLinkedList *prev;
	NodeDoubleLinkedList *next;
};

typedef struct  {
	NodeDoubleLinkedList *current;
	position current_pos;
	int count;
} DoubleLinkedList;


#endif