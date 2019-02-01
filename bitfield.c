#pragma pack(1) 
struct b_field 
{
	int a:1;
	int  b:5;
	int  c:3;
	int d;
}A;

int main()
{
	printf("%d", sizeof(A));

}

