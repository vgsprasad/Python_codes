int stack[20000];
int top =0;

void push(int val) {
	stack[top++] = val;
}
int pop(){
	return stack[top--];
}
int isempty(){
	if (top < 0) {
		return 1;
	}
	return 0;
}
bool isValidBST(struct TreeNode* root) {
	inorder(root);
	int flag = 0; 
	while(!isempty()) {
		if (!flag) {
			num = pop();
			flag = 1;
		}
		temp = pop()
		if (temp < num) {
			num  = temp;
			continue;
		}
		else {
			return 0;
		}
	}
	return 1;
}
void inorder(struct TreeNode *root) {
	if (root) {
		inorder(root->left);
		push(root->data);
		inorder(root->right);
	}
}

