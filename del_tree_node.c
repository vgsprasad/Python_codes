struct TreeNode* minvaluebst(struct TreeNode *root) { 
	if(root) {
		minvaluebst(root->left);
		return root;
		minvaluebst(root->right);
	}
}
struct TreeNode* deleteNode(struct TreeNode* root, int key) {
	if (root == NULL) {
		return NULL;
	}
	if (key < root->val) {
		root->left = deleteNode(root->left, key);
	}

	else if ( key > root->val) {
		root->right = deleteNode(root->right, key);
	}

	else { 
		if(root->left == NULL) {
			struct TreeNode *temp = root->right;
			free (root);
			return temp;
		}
		if (root->right == NULL) {
			struct TreeNode *temp = root->left;
			free(root);
			return temp;
		}
		// Find in order successor
		struct TreeNode *temp = minvaluebst(root->right);
		root->val = temp->val;
		root->right = deleteNode(root->right, root->val);
	}
	return root;
}

