typedef struct {
	int *arr;
	int front;
	int back;
} MyQueue;

typedef struct {
	MyQueue *q1;
	MyQueue *q2;
} MyStack;

/** Initialize your data structure here. */
MyStack* myStackCreate(int maxSize) {
    MyStack *temp = malloc(sizeof(MyStack));
    temp->q1 = malloc(sizeof(MyQueue));
    temp->q2 = malloc(sizeof(MyQueue));
    temp->q1->back  = 0;
    temp->q2->front = 0;

    temp->arr = malloc(sizeof )* maxSize;

    return temp;
}

/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    obj->q1->arr[obj->q1->front] = x;
    obj->q1->front++;
}

/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    int temp;
    while(obj->q1->front != obj->q1->back + 1) {
	temp = obj->q1->arr[obj->q1->back];
	obj->q1->back++;
        obj->q2->arr[obj->q2->front] = temp;
	obj->q2->front++;
   }
   
   ret = obj->q1->arr[obj->q1->back];
   obj->q1->back++;
   
   while (obj->q2->front != obj->q2->back) {
	temp = obj->q2->arr[obj->q2->back];
	obj->q2->back++;
        obj->q1->arr[obj->q1->front] = temp;
	obj->q1->front++;
   }
   return ret;
}

/** Get the top element. */
int myStackTop(MyStack* obj) {
    int temp;
    int ret;
    while(obj->q1->front != obj->q1->back + 1) {
        temp = obj->q1->arr[obj->q1->back];
        obj->q1->back++;
        obj->q2->arr[obj->q2->front] = temp;
        obj->q2->front++;
   }

   ret = obj->q1->arr[obj->q1->back];

   while (obj->q2->front != obj->q2->back) {
        temp = obj->q2->arr[obj->q2->back];
        obj->q2->back++;
        obj->q1->arr[obj->q1->front] = temp;
        obj->q1->front++;
   }
   return ret;
}

/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
	if (obj->q1->front == obj->q1->back)
		return true;
	return false;
}

void myStackFree(MyStack* obj) {
	free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * struct MyStack* obj = myStackCreate(maxSize);
 * myStackPush(obj, x);
 * int param_2 = myStackPop(obj);
 * int param_3 = myStackTop(obj);
 * bool param_4 = myStackEmpty(obj);
 * myStackFree(obj);
 */
