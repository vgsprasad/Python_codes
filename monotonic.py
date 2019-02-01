class Solution(object):
    def isMonotonic(self, A):
		mon_inc = False
		mon_dec = False
		if len(A) <= 2:
			return True
		index = 0
		for i in range(1, len(A)):
			if (A[i] <  A[index]):
				mon_inc = True
				index = i
			elif (A[i] > A[index]):
				mon_dec = True
				index =i
			else:
				continue
			if mon_inc ^ mon_dec:
				continue
			else:
				return False
		return True
 
        
