#include "tree.h"

int EmptyTree(NodeTree* ApT) {
	
	if(ApT == NULL)
		return TRUE;
	else
		return FALSE;
}

NodeTree* SearchTree(NodeTree* ApT, key k) {

	if(ApT == NULL) {
		return NULL;
	}
	else if (ApT->info == k) {
		return ApT;
	}
	else if (ApT->info > k) {
		return SearchTree(ApT->left, k);
	}
	else {
		return SearchTree(ApT->right, k);
	}
}

boolean InsertNodeTree(NodeTree** ApT, NodeTree* new_node) {
	
	if(*ApT == NULL) {
		*ApT = new_node;
		(*ApT)->left = NULL;
		(*ApT)->right = NULL;
		
		return TRUE;
	}
	else if((*ApT)->info == new_node->info) {
		return FALSE;	//ALREADY EXISTS
	}
	else if((*ApT)->info > new_node->info) {
		
		return InsertNodeTree(&((*ApT)->left), new_node);	// LEFT - SMALLER ELEMENTS
	}
	else {
		return InsertNodeTree(&((*ApT)->right), new_node);	//RIGHT - BIGGER ELEMENTS
	}
}

NodeTree* DeleteNodeTree(NodeTree** ApT) {
	NodeTree *aux = NULL, *del = *ApT;
	
	if(*ApT != NULL) {

		if((*ApT)->right == NULL) {
			*ApT = (*ApT)->left;
		}
		else if((*ApT)->left == NULL) {
			*ApT = (*ApT)->right;
		}
		else {
			aux = (*ApT)->right;
		
			while(aux->left != NULL) {
				aux = aux->left;
			}
			
			aux->left = (*ApT)->left;
			
			aux = *ApT;
			
			*ApT = (*ApT)->right;
		}
	}
	
	return del;
}

NodeTree* DeleteKeyTree(NodeTree** ApT, key k) {
	
	if(*ApT == NULL) {
		return NULL;
	}
	else if ((*ApT)->info == k) {
		
		return DeleteNodeTree(ApT);
	}
	else if((*ApT)->info > k) {
		return DeleteKeyTree(&((*ApT)->left), k);	// LEFT - SMALLER ELEMENTS
	}
	else {
		return DeleteKeyTree(&((*ApT)->right), k);	//RIGHT - BIGGER ELEMENTS
	}
	
}

void ClearTree(NodeTree** ApT) {
	
	while(EmptyTree(*ApT) == FALSE) {
		free(DeleteKeyTree(ApT, (*ApT)->info));
	}
}



int TreeSize(NodeTree* ApT) {
	
	if(ApT == NULL) {
		return 0;
	}
	else {
		return 1 + TreeSize(ApT->left) + TreeSize(ApT->right);
	}
}

int LeavesNumber(NodeTree* ApT) {
	
	if(ApT == NULL) {
		return 0;
	}
	else if((ApT->left == NULL) && (ApT->right == NULL)) {
		return 1;
	}
	else {
		return LeavesNumber(ApT->left) + LeavesNumber(ApT->right);
	}
}

int TreeWeight(NodeTree* ApT) {
	int wL, wR;
	
	if(ApT == NULL) {
		return 0;
	}
	else {
		wL = TreeWeight(ApT->left);
		wR = TreeWeight(ApT->right);
		
		if(wL > wR) {
			return wL + 1;
		}
		else {
			return wR + 1;
		}
	}
}

int TreeWidth(NodeTree* ApT, level l) {
	if(ApT == NULL) {
		return 0;
	}
	else {
		if(l == 1) {
			return 1;
		}
		else {
			return TreeWidth(ApT->left, l-1) + TreeWidth(ApT->right, l-1);
		}
	}
}

int maxTreeWidth(NodeTree* ApT) {
	int i, width, max_width = -1;

	for(i = 1; i <= TreeWeight(ApT); i++) {
		width = TreeWidth(ApT, i);

		if(width > max_width) {
			max_width = width;
		}
	}

	return max_width;
}


void Visit(TYPE info) {
	printf("%d", info);
}


void VisitLeaves(NodeTree* ApT) {
	
	if(ApT != NULL) {
		
		if((ApT->left == NULL) && (ApT->right == NULL)) {
			Visit(ApT->info);
		}

		VisitLeaves(ApT->left);
		VisitLeaves(ApT->right);
	}
}



void PreOrder(NodeTree* ApT) {
	
	if(ApT != NULL) {
		Visit(ApT->info);
		PreOrder(ApT->left);
		PreOrder(ApT->right);
	}
}

void InOrder(NodeTree* ApT) {
	
	if(ApT != NULL) {
		InOrder(ApT->left);
		Visit(ApT->info);
		InOrder(ApT->right);
	}
}

void PostOrder(NodeTree* ApT) {

	if(ApT != NULL) {
		PostOrder(ApT->left);
		PostOrder(ApT->right);
		Visit(ApT->info);
	}
}


void BalancingLeft(NodeTree** ApT, NodeTree* aux) {
	NodeTree *a, *b, *c;
	
	a = *ApT;
	b = (*ApT)->left;
	
	if(aux->info < (*ApT)->left->info) {	/* LEFT-LEFT BALANCING */
		*ApT = b;
		a->left = b->right;
		b->right = a;
		a->factor = 0;
		b->factor = 0;
	}
	else {									/* LEFT-RIGHT BALANCING */	
		c = (*ApT)->left->right;
		*ApT = c;
		b->right = c->left;
		a->left = c->right;
		c->left = b;
		c->right = a;
		
		if(c->factor == -1) {
			b->factor = 0;
			a->factor = 1;
		}
		else {
			if(c->factor == 0) {
				a->factor = 0;
				b->factor = 0;
			}
			else {
				if(c->factor == 1) {
					a->factor = 0;
					b->factor = -1;				
				}
			}
		}
	}
}

void BalancingRight(NodeTree** ApT, NodeTree* aux) {
	NodeTree *a, *b, *c;
	
	a = *ApT;
	b = (*ApT)->right;
	
	if(aux->info > (*ApT)->right->info) {	/* RIGHT-RIGHT BALANCING */
		*ApT = b;
		a->right = b->left;	
		b->left = a;
		a->factor = 0;
		b->factor = 0;
	}
	else {									/* RIGHT-LEFT BALANCING */	
		c = (*ApT)->right->left;
		*ApT = c;
		b->left = c->right;	
		a->right = c->left;	
		c->left = a;
		c->right = b;
		
		if(c->factor == -1) {
			b->factor = 0;
			a->factor = 1;
		}
		else {
			if(c->factor == 0) {
				a->factor = 0;
				b->factor = 0;
			}
			else {
				if(c->factor == 1) {
					a->factor = 0;
					b->factor = -1;				
				}
			}
		}
	}
}

int InsertNodeTree_B(NodeTree** ApT, NodeTree* new_node) {
	int b;
	
	if(*ApT == NULL) {
		*ApT = new_node;
		return 1;
	}
	else {
		if((*ApT)->info == new_node->info) {
			return -1;
		}
		else {
			if((*ApT)->info > new_node->info) {
				b = InsertNodeTree_B(&((*ApT)->left), new_node);
				
				if(b < 1) {
					return b;
				}
				else {
					if((*ApT)->factor == 1) {
						(*ApT)->factor = 0;
						
						return 0;
					}
					else {
						if((*ApT)->factor == 0) {
							(*ApT)->factor = -1;
							
							return 1;
						}
						else {
							BalancingLeft(ApT, new_node);
						
							return 0;
						}
					}
				}
			}
			else {												
				b = InsertNodeTree_B(&((*ApT)->right), new_node);
				
				if(b < 1) {
					return b;
				}
				else {
					if((*ApT)->factor == -1) {
						(*ApT)->factor = 0;
						
						return 0;
					}
					else {
						if((*ApT)->factor == 0) {
							(*ApT)->factor = 1;
							
							return 1;
						}
						else {
							BalancingRight(ApT, new_node);
						
							return 0;
						}
					}
				}				
			}
		}
	}
}