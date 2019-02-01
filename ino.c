int* inorderTraversal(struct TreeNode* root, int* returnSize) {
	struct TreeNode *current = root; 
	struct TreeNode *temp;
	int count = 0; 
	int res[1000];
	if (!current) {
		return res; 
	}
	push(current);
back:
	while(current->left) {
		push(current->left);
		current = current->left;
	}
	if (!isempty()) {
		current = pop();
		res[count++] = current->val;
		goto back;
	}
	return res; 
}

