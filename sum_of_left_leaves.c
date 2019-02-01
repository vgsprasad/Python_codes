int newfunc(struct TreeNode* root, int magic) 
{
	if (root == NULL ) {
		return 0;
	}
	if (root->left == NULL && root->right == NULL) {
		if (magic) {
			return root->val;
		} else {
			return 0;
		}
	}
	return newfunc(root->left, 1) + newfunc(root->right, 0);
}
int sumOfLeftLeaves(struct TreeNode* root) {
	int sum = 0; 
	if (root) {
		sum = sum + newfunc(root->left , 1) + newfunc(root->right, 0);
	}
	return sum;
}
