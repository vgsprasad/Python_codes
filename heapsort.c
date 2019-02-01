
void 
min_heapify(int A[], int size, int i)
{
	int l = 2*i+1;
	int r = 2*i+2;
	int smallest =i;
	if (l<size && A[l] < A[i])
		smallest = l;
	if (r<size && A[r]<A[smallest])
		smallest =r;
	if (smallest != i){
		int temp = A[smallest];
		A[smallest]= A[i];
		A[i]=temp;
		min_heapify(A,size,smallest);
	}
}
void heapsort(int A[], int size)
{
	int i=0;
	while(i<size){
		min_heapify(A,size,0);
		printf("%d ", A[0]);
		A[0] =A[size-1];
		size--;
	}
}
int main()
{
	int n,A[100];
	scanf("%d", &n);
	for(int i =0; i<n;i++)
	{
		scanf("%d", &A[i]);
	}
	heapsort(A, n);
}
