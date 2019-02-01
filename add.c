int top1 =0;
int top2 =0;
int stack1[10000];
int stack2[10000];

void push1(int val) {
	stack1[top1] = val; 
	top1++;
}
void push2(int val) {
	stack2[top2] = val;
	top2++;
}
int is1empty(){
	if (top1 == 0) {
		return 1;
	}
	return 0;
}
int is2empty(){
	if (top2 == 0) {
		return 1;
	}
	return 0;
}
int pop1(){
	return stack1[--top1];
}
int pop2(){
	return stack2[--top2];
}
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode *tl1;
	struct ListNode *tl2;
	struct ListNode *temp;
	struct ListNode *newnode;
	int a,b, carry, val, sum;

	if (!l1) {
		return l2;
	}
	if (!l2) {
		return l1;
	} 
	tl1 = l1;
	tl2 = l2; 
	while(tl1) {
		push1(tl1->val);
		tl1 = tl1->next; 
	}
	while(tl2) {
		push2(tl2->val);
		tl2 = tl2->next;
	}

	carry =0;
	temp = NULL;
	while(!is1empty() && !is2empty()) {
		a = pop1();
		b = pop2();
		sum = a+b+carry;
		val = sum%10;
		carry = sum/10;
		newnode =
			((struct ListNode* ) malloc (sizeof(struct ListNode)));
		newnode->val = val;
		newnode->next = temp;
		temp = newnode;
	}
	if (is1empty() && !is2empty()) {
		b = pop2();
		sum = b+carry;
		val = sum%10;
		carry = sum/10;
		newnode =
			((struct ListNode* ) malloc (sizeof(struct ListNode)));
		newnode->val = val;
		newnode ->next = temp;
		temp = newnode;
	}
	if (!is1empty() && is2empty()) {
		a = pop1();
		sum = a+carry;
		val = sum%10;
		carry = sum/10;
		newnode =
			((struct ListNode* ) malloc (sizeof(struct ListNode)));
		newnode->val = val;
		newnode ->next = temp;
		temp = newnode;
	}
	if (!carry) {
		newnode =
			((struct ListNode* ) malloc (sizeof(struct ListNode)));
		newnode->val = carry;
		newnode ->next = temp;
		temp = newnode;
	}
	return temp; 
}
