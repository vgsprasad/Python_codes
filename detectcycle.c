struct ListNode *detectCycle(struct ListNode *head) {
	struct ListNode * hare = head;
	struct ListNode * tort = head;

	int loop_exists;
	while(hare && tort) {
		tort = tort->next;
		if (hare->next == NULL) {
			return NULL;
		}
		hare = hare->next->next;
		if (hare == tort) {
			loop_exists = 1; 
			break;
		}
	}
	if(!loop_exists) {
		return NULL; 
	}

	hare = head;
	while(hare !=tort ) { 
		hare = hare->next;
		tort = tort->next;
	}
	return hare; 
}
