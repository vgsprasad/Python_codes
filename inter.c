struct ListNode *getIntersectionNode(struct ListNode *headA, 
				     struct ListNode *headB) {
	struct ListNode *tA = headA;
	struct ListNode *tB = headB;
	struct ListNode *sA = NULL;
	struct ListNode *sB = NULL; 
	int A_len = 1000000;
	int B_len = 1000000;
	int countA = 1;
	int countB = 1;
	while (tA && tB) {
		if (tA->val == tB->val) {
			return tA; 
		}
		else {
			if (!tA->next || !tB->next) {
				if (tA->next == NULL) {
					A_len = countA; 
					sA = tA;
					tA->next =headB;
					if (tB->next) {
						countB++;
						tB =tB->next;
					}
				}
				if (tB->next == NULL) {
					B_len = countB;
					sB =tB;
					tB->next =headA;
					if (tA->next) {
						countA++;
						tA = tA->next;
					}

				}
			}
			else {
				countA++;
				countB++;
				tA= tA->next;
				tB= tB->next;
				if((countA > 2 * A_len -1 ) || (countB > 2* B_len-1)) {
					if (!sA) {
						sA->next = NULL;
					}
					if (!sB) {
						sB->next = NULL;
					}
					return NULL;
				}
			}
		}
	}
	if (!sA) {
		sA->next = NULL;
	}
	if (!sB) {
		sB->next = NULL;
	}
	return NULL;
}
