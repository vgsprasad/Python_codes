#include<stdio.h>
struct Node
{
    int data;
    Node *next;
    Node *prev;
};
Node* SortedInsert(Node *head,int data) 
{
    if (!head) {
	Node *t = (struct Node *)malloc(sizeof(struct Node));
	t->data = data;
	t->next = NULL;
	t->prev = NULL;
	return t;
    }  else {
	Node *temp = head;
	while(temp) {
	    if (temp->data < data) {
		if (temp->next == NULL) {
		    Node *t = (struct Node *)malloc(sizeof(struct Node));
		    t->data = data;
		    t->next = NULL; 
		    t->prev = temp ; 
		    temp->next = t; 
		    return head; 
		}
		temp = temp->next; 
	    } else {
		if (temp->prev == NULL) {
		    Node *t = (struct Node *)malloc(sizeof(struct Node));
		    t->data = data;
		    t->next = temp;
		    temp->prev = t;
		    t->prev = NULL;
		    return t; 
		} else {
		    Node *t = (struct Node *)malloc(sizeof(struct Node));
		    t->data = data;
		    t->next = temp;
		    t->prev = temp->prev;
		    temp->prev = t;
		    return head; 
		}
	    }
	    
	}
    }
}



