D = {}
	    
def majorityElement(self, nums):
	for n in nums:
		if n in D.keys():
			D[n] = D[n]+1
			if D[n] > len(nums)/2:
				return n
		else:
			D[n] = 1
			if D[n] > len(nums)/2:
				return n

