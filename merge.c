struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode *ret_head;
	struct ListNode *temp;
	struct ListNode *temp_ret_head;

	ret_head = (struct ListNode * )malloc(sizeof(struct ListNode ));
	ret_head->next = NULL; 
	if (!l1 && !l2) { 
		return NULL;
	}
	else if (!l1 && l2) {
		return l2;
	}
	else if (l1 && !l2) {
		return l1;
	}
	temp_ret_head = ret_head;
	while (l1 && l2) {  
		if (l1->val < l2->val) {
			temp = l1->next;
			temp_ret_head->next = l1;
			l1 = temp; 
			temp_ret_head = temp_ret_head->next;
		} 
		else {
			temp = l2->next;
			temp_ret_head->next = l2; 
			l2 = temp;
			temp_ret_head = temp_ret_head->next;
		}
	}
	if (l1 ) {
		temp_ret_head->next = l1;
	}
	else if (l2) {
		temp_ret_head->next = l2; 
	}

	return ret_head->next;
}
