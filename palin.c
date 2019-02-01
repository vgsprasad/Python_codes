#include<stdio.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

int stack[1000];
int top=0;
void push(int temp)
{
	stack[top++] = temp;
}

int pop(void)
{
	top--;
	return stack[top+1];
}
bool ispalin(struct ListNode * n)
{
	struct ListNode *temp = n;
	int pop_val;
	/* push all nodes to stack */
	while(temp)
	{
		push(temp->val);
		temp = temp->next;
	}
	temp = n;
	while(temp)
	{
		pop_val = pop();
		if (pop_val == temp->val) {
			continue;
		}
		else {
			return 0;
		}
		temp = temp->next;
	}
	return 1;
}
