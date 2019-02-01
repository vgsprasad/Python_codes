int singleNonDuplicate(int* nums, int numsSize) {
	int i ;
	int res =0;
	for (i=0;i<numsSize;i++) {
		res = res ^ nums[i];
	}
	return res; 
}
