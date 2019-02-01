#include<stdio.h>
#include<stdlib.h>
struct node 
{
    int data;
    struct node *left;
    struct node *right;
    int sum;
};

struct node *temp;
struct node * insert (int n, struct node *head)
{
    if(head)
    {
	if(n < head->data)
	{
	    head->left = insert(n,head->left);
	}
	else
	    head->right = insert(n,head->right);
    return head;
    }
    else 
    {
	temp = malloc(sizeof(struct node *));
	temp->data = n;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
    }
}
preorder(struct node *head)
{
    if(head)
    {
	printf("%d  \n", head->data);
	preorder(head->left);
	preorder(head->right);
    }
}
postorder(struct node *head)
{
    if(head)
    {
	postorder(head->left);
	postorder(head->right);
	printf("%d  \n", head->data);
    }
}

inorder(struct node *head)
{
    if(head)
    {
	inorder(head->left);
	printf("%d  \n", head->data);
	inorder(head->right);
    }
}

struct node *head =NULL;
int main()
{
    int n,ch,num;
    printf("Enter n\n");
    scanf("%d",&n);
    do
    {
	printf("Enter \n 1: insert \n 2: delete \n 3: preorder\n 4: postorder \n 5: inorder\n 6 :Sum tree level wise \n");
	scanf("%d", &ch);
	switch (ch)
	{
	    case 1:printf("Enter the number \n");
		   scanf("%d",&num);
		   head = insert(num,head);
		   break;
	    case 2:printf("Enter the number to delete \n");
		   scanf("%d",&num);
		   //delete(num,head);
		   break;
	    case 3:preorder(head);
		   printf("\n");
		   break;
	    case 4:postorder(head);
		   printf("\n");
		   break;
	    case 5:inorder(head);
		   printf("\n");
		   break;
	    case 6://sum_tree();
		   break;
	    case 7:
	    default:
		   exit(1);
	}
    }while(1);
}




