struct TreeNode* invertTree(struct TreeNode* root) {

	struct TreeNode * temp;
	if (root) {
		/* Swap the links */
		temp = root->left;
		root->left = root->right;
		root->right = temp;

		invertTree(root->left);
		invertTree(root->right);
	}
	return root;
}
