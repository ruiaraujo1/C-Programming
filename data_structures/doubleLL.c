#include "doubleLL.h"

DoubleLinkedList* CreateList() {

	DoubleLinkedList* ApL = malloc(sizeof(DoubleLinkedList));
	
	ApL->current = NULL;
	
	ApL->current_pos = -1;

	ApL->count = 0;

	return ApL;
	
}

void FreeList(DoubleLinkedList **ApL) {
	ClearList(*ApL);
	
	free(*ApL);
	
	*ApL = NULL;
}

boolean EmptyList(DoubleLinkedList* ApL) {
	if(ApL->current == NULL)
		return TRUE;
	else
		return FALSE;
}

void SetPosition(DoubleLinkedList* ApL, position p) {
	
	if((p >= 0) && (p <= ApL->count)) {
		
		while(p < ApL->current_pos) {
			ApL->current = ApL->current->prev;
			ApL->current_pos -= 1;
		}
		
		while(p > ApL->current_pos) {
			ApL->current = ApL->current->next;
			ApL->current_pos += 1;
		}
	}
}

void InsertList(DoubleLinkedList *ApL, NodeDoubleLinkedList *new_node, position p) {
	NodeDoubleLinkedList* next = NULL;
	
	if((p >= 0) && (p <= ApL->count)) {
		if(p == 0) {										
			new_node->prev = NULL;
			
			if(EmptyList(ApL) == TRUE) {	
				new_node->next = NULL;
			}
			else {
				SetPosition(ApL, 0);
				new_node->next = ApL->current;
				ApL->current->prev = new_node;
			}
		}
		else {												
			SetPosition(ApL, p-1);
			
			next = ApL->current->next;
			
			new_node->next = next;
			new_node->prev = ApL->current;
			
			if(next != NULL) {							
				next->prev = new_node;
			}
		}
		ApL->current = new_node;
		ApL->current_pos = p;
		ApL->count += 1;
	}
}

NodeDoubleLinkedList* DeleteList(DoubleLinkedList* ApL, position p) {
	NodeDoubleLinkedList *next = NULL, *del = NULL;
	
	if((p >= 0) && (p < ApL->count)) {
	
		SetPosition(ApL, p);
		del = ApL->current;
		next = del->next;
		
		if(next != NULL) {
			next->prev = ApL->current->prev;
			ApL->current_pos = p;
		}
		else {
			ApL->current_pos = p-1;
		}
		
		if(p == 0) {
			ApL->current = next;
		}
		else {
			ApL->current->prev->next = next;
			ApL->current = ApL->current->prev;
		}
		
		ApL->count -= 1;
	}
		
	return del;
}

void ClearList(DoubleLinkedList *ApL) {
	while(EmptyList(ApL) == FALSE) {
		free(DeleteList(ApL, ApL->current_pos));
	}
}

int SizeList(DoubleLinkedList *ApL) {
	NodeDoubleLinkedList *current = ApL->current;
	int count = 0;
	
	while(current != NULL) {
		count++;
		current = current->next;
	}
	
	current = ApL->current->prev;
	
	while(current != NULL) {
		count++;
		current = current->prev;
	}
	
	return count;
}

void PrintDoubleList(DoubleLinkedList *ApL) {	
	NodeDoubleLinkedList *current = ApL->current;
	
	while(current != NULL) {
		printf("%d", current->info);
		current = current->next;
	}
	
	current = ApL->current->prev;
	
	while(current != NULL) {
		printf("%d", current->info);
		current = current->prev;
	}
}
