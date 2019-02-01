int findmin(struct TreeNode* root, int min) {
	int A; 
	int B;
	int C;

	A = root->val; 
	B = root->left  ? findmin(root->left):2147483648;
	C = root->right ? findmin(root->right):2147483648;

	if (A == min) {
		A = 2147483648;
	}
	if (B == min) {
		B = 2147483648;
	}
	if (C == min) {
		C = 2147483648;
	}
	return A<B?(A<C?A:C):(B<C?B:C);
}
int findSecondMinimumValue(struct TreeNode* root) {
	int min;
	int sec_min;
	int a = 2147483648;
	int b = 2147483648;
	if (!root) {
		return -1;
	}
	min = root->val;
	if (root->left) {
		a = findmin(root->left, min);
	}
	if (root->right) {
		b = findmin(root->right, min);
	}
	c = a<b?a:b;
	if (c > a) {
		return c ;
	}
	else {
		return -1;
	}
}

