struct TreeNode* mergeTrees(struct TreeNode* t1, struct TreeNode* t2) {
	if (t1 && t2 ) {
		struct TreeNode *t3 = malloc(sizeof(struct TreeNode));
		t3->val = t1->val + t2->val; 
		t3->left = mergeTrees(t1->left, t2->left); 
		t3->right = mergeTrees(t1->right, t2->right);
		return t3;
	}
	if(t1 && !t2) {
		return t1;
	}
	if(!t1 && t2) {
		return t2;
	}
	if (!t1 && !t2) {
		return NULL;
	}
}
