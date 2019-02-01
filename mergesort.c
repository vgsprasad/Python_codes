#include<stdio.h>

void merge (int A[], int start, int mid, int end) 
{
	int left_idx= start;
	int right_idx = mid+1;

	int final_arr_idx = start;

	while(left_idx <= mid && right_index <= end ) 
	{
		if (A[left_index] > A[right_index]) {
			int temp;
			temp = A[left_index];
			A[left_index] = A[right_index];
			A[right_index] = temp;
		}

void mergesort(int A[], int start, int end) 
{
	if (start == end) {
		return;
	int mid = (start + end) /2;

	mergesort(A, start, mid);
	mergesort(A , mid+1, end);
	merge(A, start, mid, end);
}
int main()
{
	int n;
	int A[100];
	scanf("%d", &n);
	for(i =0;i<n;i++)
		scanf("%d", &A[i]);
	mergesort(A,0,n-1);
	for(i=0;i<n;i++)
		printf("%d  ", A[i]);
}
