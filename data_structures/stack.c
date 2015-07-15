#include "stack.h"

Stack* NewStack() {
	Stack *ApS = malloc(sizeof(Stack));
	
	ApS->top = NULL;
	
	return ApS;
}

void FreeStack(Stack** ApS) {
	ClearStack(*ApS);
			
	free(*ApS);
	
	*ApS = NULL;
}

boolean EmptyStack(Stack* ApS) {	
	if(ApS->top == NULL)
		return TRUE;
	else
		return FALSE;
}

void PushStack(Stack* ApS, NodeStack* new_node) {
	
	new_node->next = ApS->top;
	ApS->top = new_node;
}

NodeStack* PopStack(Stack* ApS) {
	NodeStack *aux = ApS->top;
	
	if(EmptyStack(ApS) == FALSE)
		ApS->top = aux->next;
	
	return aux;
}

void ClearStack(Stack* ApS) {
		
	while(EmptyStack(ApS) == FALSE) {
		free(PopStack(ApS));
	}
}

int SizeStack(Stack* ApS) {
	NodeStack *aux = ApS->top;
	int count = 0;
	
	while(aux != NULL) {
		count++;
		aux = aux->next;
	}
	
	return count;
}

NodeStack* TopStack(Stack* ApS) {
	return ApS->top;
}

void PrintStack(Stack* ApS) {
	NodeStack *aux = ApS->top;
	
	while(aux != NULL) {
		printf("%d", aux->info);
		aux = aux->next;
	}
}
