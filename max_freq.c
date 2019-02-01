int findMaxConsecutiveOnes(int* nums, int numsSize) {
	int max_f =0,f = 0;
	for (int i=0;i<numsSize; i++)
	{
		if (nums[i] == 1) {
			f++;
			if (f > max_f) {
				max_f = f;
			}
		} else { 
			f = 0;
		}
	}
	return max_f;
}
