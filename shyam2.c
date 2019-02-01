union utest {
	struct {
		char a;
		char b;
		short c;
	}test;
	int i;
};

int main()
{
	union utest u;
	u.i = 0x30020;
	printf("%x %x %x\n", u.test.a, u.test.b, u.test.c);
}
