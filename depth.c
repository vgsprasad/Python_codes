int maxDepth(struct TreeNode* root) {
	if ( !root) {
		return 0;
	}
	else {
		int l = maxDepth(root->left);
		int r = maxDepth(root->right);
		return 1+ (l>r?l:r);
	}
}
