int main()
{
	int n;
	scanf("%d", &n);
	n = n>>1;
	while(n &(n-1))
	{
		n = n &(n-1);
	}
	printf("%d\n",n);
}
