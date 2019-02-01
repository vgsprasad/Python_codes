struct ListNode* removeElements(struct ListNode* head, int val) 
{
	struct ListNode * temp;
	if (!head ) {
		return NULL;
	}

	while  (head && head->val == val) {
		head = head->next; 
	}

	temp = head; 
	while(temp && temp->next) {
		if (temp->next->val == val) {
			temp->next = temp->next->next;
		} else {
			temp = temp->next;
		}
	}
	return head; 
}


