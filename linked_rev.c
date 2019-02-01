Node* Reverse(Node *head)
{

    Node *temp, *ret;
    if (head->next == NULL) {
	return head;
    }
    else {
	temp = head->next; 
	ret = Reverse(temp);
	temp->next = head;
    }
    return ret;
}
	
