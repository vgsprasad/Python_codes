def containsDuplicate(nums):
	D = {}
	for n in nums:
		if n in D.keys():
			return True
		else:
			D[n] = 1
	return False
