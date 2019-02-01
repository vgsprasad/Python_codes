int front=0;
int back =0;

struct TreeNode * Queue[1000];

void insert(struct TreeNode *temp) 
{
	Queue[front++] = temp;
}

struct TreeNode * delete() {
	struct TreeNode *temp;
	if (front == back) {
		return NULL;
	}
	temp = Queue[back];
	back++; 
	return temp;
}

int getqueuesize() 
{
	return front-back;
}

double* averageOfLevels(struct TreeNode* root, int* returnSize) {
	double ret_val[1000] = {0};
	struct TreeNode* temp;
	double count;
	int i;
	int size;
	int index = 0;
	if (!root) {
		return ret_val;
	}
	insert(root);
back:	size  = getqueuesize();
        count = 0;
	for(i =0; i< size; i++) {
		temp  = delete();
		count += temp->val;
		if(temp->left) {
			insert(temp->left);
		}
		if(temp->right) {
			insert(temp->right);
		}
	}

	ret_val[index++] = double(count) / double(size); 
	if (getqueuesize() != 0) {

		goto back;
	}
	*returnSize = index;
	return ret_val;
}

