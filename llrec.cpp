#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************
void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot){
	
	if(head == NULL){
		smaller = NULL;
		larger = NULL;
		return;
	}
	Node* temp = head;
	llpivot(temp -> next, smaller, larger, pivot);

	if(temp->val > pivot){
		head -> next = larger;
		larger = head;
	}else{
		head -> next = smaller;
		smaller = head;
	}
	head = NULL;
		
}

