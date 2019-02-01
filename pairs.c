struct ListNode* swapPairs(struct ListNode* head) {
	struct ListNode* A;
	struct ListNode* B;
	struct ListNode* dummynode;

	if (head == NULL) {
		return NULL; 
	}
	if (head->next == NULL) {
		return head; 
	}
	dummynode = malloc(sizeof(struct ListNode));
	dummynode->next = NULL;
	while( temp && temp->next) {
		dummynode->next = temp->next;
		A = temp;
		B = temp->next; 
		A->next = B->next; 
		B->next = A;
		dummynode = dummynode->next; 
		temp = temp->next;
	}
}
