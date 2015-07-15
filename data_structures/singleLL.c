#include "singleLL.h"

LinkedList* CreateList() {
	LinkedList *ApL = malloc(sizeof(LinkedList));
	
	ApL->head = NULL;
	ApL->count = 0;
	
	return ApL;
}

void FreeList(LinkedList **ApL) {
	ClearList(*ApL);
	
	free(*ApL);
	
	*ApL = NULL;
}

boolean EmptyList(LinkedList* ApL) {
	if(ApL->head == NULL)
		return TRUE;
	else
		return FALSE;
}

NodeLinkedList* SetPosition(LinkedList* ApL, position p) {
	NodeLinkedList* current = NULL;
	position i = 0;

	if((p >= 0) && (p <= ApL->count)) {
		current = ApL->head;

		while(i < p) {
			current = current->next;
			i++;
		}
	}

	return current;
}

void InsertList(LinkedList *ApL, NodeLinkedList *new_node, position p) {
	NodeLinkedList *current = NULL;

	if((p >= 0) && (p <= ApL->count)) {
		if(p == 0) {
			new_node->next = ApL->head;
			ApL->head = new_node;
		}
		else {
			current = SetPosition(ApL, p-1);
			new_node->next = current->next;
			current->next = new_node;
		}
		
		(ApL->count)++;
	}
}

NodeLinkedList* DeleteList(LinkedList* ApL, position p) {
	NodeLinkedList *del = NULL, *current = NULL;

	if((p >= 0) && (p < ApL->count)) {
		if(p == 0) {
			del = ApL->head;
			ApL->head = del->next;
		}
		else {
			current = SetPosition(ApL, p-1);
			del = current->next;
			current->next = del->next;

		}

		(ApL->count)--;
	}
	
	return del;
}

void ClearList(LinkedList *ApL) {
	while(EmptyList(ApL) == FALSE) {
		free(DeleteList(ApL, 0));
	}
}

int SizeList(LinkedList *ApL) {
	NodeLinkedList *current = ApL->head;
	int count = 0;
	
	while(current != NULL) {
		current = current->next;
		count++;
	}
	
	return count;
}

void PrintList(LinkedList *ApL) {
	NodeLinkedList *current = ApL->head;
	
	while(current != NULL) {
		printf("%d", current->info);
		current = current->next;
	}
}
