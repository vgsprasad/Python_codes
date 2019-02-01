#include<stdio.h>

int i=1;
struct node 
{
	char val;
	struct node *next;
	struct node *child;
	int i;
	int mi;
};

struct node * insert(char val, 
		     struct node *next,
		     struct node *child)
{
	struct node *temp = malloc(sizeof(struct node));
	temp->val = val;
	temp->next = next;
	temp->child= child;
	temp->i=0;
	temp->mi =0;
	return temp;
}

void update_imi(struct node *root)
{
	if (!root)
		return;

	root->i = i;
	root->mi =i;
	i++;
	if (root->child != NULL){
		update_imi(root->child);
		root->mi = i;
	}
	update_imi(root->next);
	printf("%c %d %d\n", root->val, root->i,root->mi);
}


int main()
{
	struct node *temp;
	struct node *temp1;
	temp = insert('h', NULL, NULL);
	temp = insert('g', temp, NULL);
	temp1 = insert('f', NULL, NULL);
	temp = insert('e', temp1, temp);
	temp= insert('d', temp, NULL);
	temp1 = insert('c', NULL, NULL);
	temp = insert('b', temp1, temp);
	temp = insert('a', temp, NULL);

	update_imi(temp);

}

