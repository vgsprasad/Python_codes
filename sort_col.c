void sortColors(int* nums, int numsSize) {
	int count[3] = {0};
	int i;
	int k;
	for(i = 0 ;i<numsSize; i++)
	{
		count[nums[i]]++;
	}
	k= 0;
	i =0;
	while(k<count[0]){
		k++;
		nums[i++] =0;
	}
	k=0;
	while(k<count[1]) {
		k++;
		nums[i++]=1;
	}
	k=0;
	while(k<count[2]) {
		k++;
		nums[i++]=2;
	}
}
