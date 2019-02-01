struct ListNode* reversesublist(struct ListNode * head,
				int m,
				int n)
{

	struct ListNode* prev = NULL;
	struct ListNode* curr = head;
	int count;

	if (!head) {
		return NULL;
	}

	count = 0;
	while(curr && count < m-1) {
		count++;
		curr = curr->next;
	}
	if(!curr) {
		return head;
	}
	prevmnode = curr; 
	prevnnode = curr->next;

	prev = curr;
	curr = curr->next; 
	while(curr && count <n-1) {
		count ++;
		temp = curr->next;
		curr->next = prev; 
		prev = curr; 
		curr = temp; 
	}
	prevmnode->next = curr;
	prevnnode->next = curr->next; 
	return head; 
}




}


