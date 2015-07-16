#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdio.h>
#include <stdlib.h>
#include "types.h"


/* CHECK IF TREE IS EMPTY */
boolean EmptyTree(NodeTree*);

/* SEARCH AN ELEMENT IN THE TREE */
NodeTree* SearchTree(NodeTree*, int);

/* INSERTS AN ELEMENT IN THE TREE [DOES NOT DO TREE BALANCING] */
/* MEMORY ALLOCATION FOR THAT ELEMENT MUST BE DONE OUTSIDE THIS FUNCTION */
boolean InsertNodeTree(NodeTree**, NodeTree*);

/* REMOVES AN ELEMENT OF THE TREE [DOES NOT DO TREE BALANCING] */
/* MEMORY DEALLOCATION OF THAT ELEMENT MUST BE DONE OUTSIDE THIS FUNCTION */
NodeTree* DeleteNodeTree(NodeTree**);

/* SEARCH AND REMOVE OF AN ELEMENT OF THE TREE */
/* MEMORY DEALLOCATION OF THAT ELEMENT MUST BE DONE OUTSIDE THIS FUNCTION */
NodeTree* DeleteKeyTree(NodeTree**, int);

/* REMOVES ALL THE ELEMENTS OF THE TREE */
void ClearTree(NodeTree**);



/* NUMBER OF ELEMENTS OF THE TREE */
int TreeSize(NodeTree*);

/* NUMBER OF LEAVES OF THE TREE */
int LeavesNumber(NodeTree*);

/* WEIGHT OF THE TREE*/
int TreeWeight(NodeTree*);

/* WIDTH OF THE TREE */
int TreeWidth(NodeTree*, level);

/* MAX WIDTH OF THE TREE */
int maxTreeWidth(NodeTree*);



/* VISIT THE NODE OF THE TREE [PRINT THE ELEMENT] */
void Visit(TYPE);

/* VISIT ONLY THE LEAVES OF THE TREE [PRINT THE ELEMENT] */
/* /* BASED ON THE PRE_ORDER TRAVERSE */
void VisitLeaves(NodeTree*);


/* TREE TRAVERSE */
/* VLR */
void PreOrder(NodeTree*);
/* LVR */
void InOrder(NodeTree*);
 /* LRV */
void PostOrder(NodeTree*);



/* TREE BALANCING */
/* [LEFT] */
void BalancingLeft(NodeTree**, NodeTree*);

/* [RIGHT] */
void BalancingRight(NodeTree**, NodeTree*);

/* INSERTS AN ELEMENT IN THE TREE [!! WITH TREE BALANCING !!] */
/* MEMORY ALLOCATION FOR THAT ELEMENT MUST BE DONE OUTSIDE THIS FUNCTION */
int InsertNodeTree_B(NodeTree**, NodeTree*);


#endif