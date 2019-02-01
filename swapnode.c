struct ListNode* swapPairs(struct ListNode* head) {
	if (!head || !(head->next)) {
		return head;
	}
	struct ListNode *dummynode = malloc(sizeof(struct ListNode));
	struct ListNode	*temp1;
	struct ListNode	*temp2;
	struct ListNode *prev; 
	dummynode->next = NULL;
	prev = dummynode; 

	while(head && head->next) {
		temp1 = head;
		temp2 = head->next;
		head = head->next->next;
		temp2->next = temp1;
		prev->next = temp2;
		prev = prev->next->next; 
		}
	prev->next = head;

	return dummynode->next;
}
