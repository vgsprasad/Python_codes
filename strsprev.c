char* reverseOnlyLetters(char* S) {
	int start = 0; 
	int end = strlen(S) -1;
	char temp_char;

	while(start < end) {
		while (!isalpha(S[start]) && (start < end)) {
			start++;
		}
		while(!isalpha(S[end]) && (start < end)) {
			end --;
		}
		if (start < end) {
			temp_char = S[start];
			S[start] = S[end];
			S[end] = temp_char;
			start++;
			end--;
		}
	}
	return S;
}
