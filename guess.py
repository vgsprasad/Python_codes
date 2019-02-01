# def guess(num):
class Solution(object):
	def guessNumber(self, n):
		start = 1
		end = n
		while start<=end:
			mid  = (start+end)/2
			ret = guess(mid)
			if not ret:
				return mid
			elif ret > 0:
				start = mid+1
			else:
				end = mid -1
					


