#include "queue.h"

Queue* NewQueue() {
	Queue *ApQ = malloc(sizeof(Queue));
	
	ApQ->head = NULL;
	ApQ->tail = NULL;
	
	return ApQ;
		
}

void FreeQueue(Queue** ApQ) {
	ClearQueue(*ApQ);
		
	free(*ApQ);
	
	*ApQ = NULL;
}

boolean EmptyQueue(Queue* ApQ) {
		
	if(ApQ->head == NULL)
		return TRUE;
	else
		return FALSE;	
}

void AppendQueue(Queue* ApQ, NodeQueue* new_node) {
	
	if(EmptyQueue(ApQ) == TRUE) {
		ApQ->head = new_node;
		ApQ->tail = new_node;
	}
	else {
		ApQ->tail->next = new_node;
		ApQ->tail = new_node;
	}

	new_node->next = NULL;
}

NodeQueue* ServeQueue(Queue* ApQ) {
	NodeQueue *aux = ApQ->head;
	
	if(EmptyQueue(ApQ) == FALSE) {
		ApQ->head = ApQ->head->next;
		
		if(EmptyQueue(ApQ) == TRUE)	
			ApQ->tail = NULL;
	}
	
	return aux;
}

void ClearQueue(Queue* ApQ) {
	
	while(EmptyQueue(ApQ) == FALSE) {
		free(ServeQueue(ApQ));
	}
}

int SizeQueue(Queue* ApQ) {
	NodeQueue *aux = ApQ->head;
	int count = 0;
	
	while(aux != NULL) {
		count++;
		aux = aux->next;
	}
	
	return count;
}

NodeQueue* FrontQueue(Queue* ApQ) {
	
	return ApQ->head;
}

void PrintQueue(Queue* ApQ) {
	NodeQueue *aux = ApQ->head;
	
	while(aux != NULL) {
		printf("%d", aux->info);
		aux = aux->next;
	}
}
