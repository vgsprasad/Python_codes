struct TreeNode* convertBST(struct TreeNode* root) {
	static int count; 
	if (root) { 
		convertBST(root->right); 
		root->val = count + root->val; 
		count = root->val; 
		convertBST(root->left);
	}
	return root;
}
