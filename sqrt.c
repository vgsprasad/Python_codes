bool isPerfectSquare(int num) {
	int A;
	if (num <= 0) {
		return false;
	}
	if (num == 1) {
		return true;
	}
	A = num/2;
	while (A > 0 ) 
	{
		if (A*A == num) {
			return true;
		}
		A--;
	}
	return false;
}
