struct TreeNode * st[1000];
int top =-1; 

void push(struct TreeNode *node) 
{
	++top;
	st[top] = node;
}
struct TreeNode * pop()
{
	struct TreeNode *node;
	node = st[top];
	top--;
	return node;
}
int isempty()
{
	if(top == -1) {
		return 1;
	}
	return 0;
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
	int ret[1000];
	int index =0;

	if (!root) {
		*returnSize = index;
		return ret;
	}
	struct TreeNode* temp = root;
	while(temp) {
		ret[index++] = temp->val;
		if (temp->left) {
			push(temp->left);
		}
		if (temp->right) {
			push(temp->right);
		}
		if(isempty()) {
			break;
		}
		else 
		{
			temp = pop();
		}
	}
	*returnSize = index -1;
	return ret;
}
