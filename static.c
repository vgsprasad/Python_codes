void fun(){
	static int a;
	printf("%d\n", a);
	a++;
}
	
int main()
{
	for(int i =0;i<10;i++)
		fun();
}
