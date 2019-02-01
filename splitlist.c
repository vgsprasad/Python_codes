struct ListNode* oddEvenList(struct ListNode* head) {
	struct ListNode* evenhead;
	struct ListNode* odd_ptr;
	struct ListNode* even_ptr;

	odd_ptr = head;
	even_ptr = head->nex;
	evenhead = even_ptr; 

	while(even_ptr && even_ptr->next) {
		odd_ptr->next = even_ptr->next;
		odd_ptr = odd_ptr->next;
		even_ptr->next = odd_ptr->next;
		even_ptr = even_ptr->next;
	}
	odd_ptr->next = evenhead;
	return head;
}
