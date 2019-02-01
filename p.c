bool isPalindrome(int x) {
	int rev_x = 0;
	if (x < 0 ) {
		return 0;
	}

	if (x%10 == 0 && x!=0) {
		return 0;
	}

	while (x > rev_x) {
		rev_x = x%10+ 10*rev_x;
		x = x/10;
	}
	if (x == rev_x || x == rev_x/10) {
		return 1;
	}
	return 0;
}


