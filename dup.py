class Solution(object):
    def findErrorNums(self, nums):
        m = len(nums)
        s = m *(m+1)/2
        for i in nums:
            x = x ^ i
        for i in range(1,m+1):
            x = x^i
        dup_number = x
        mis_number = s-sum(nums)
        return (dup_number, mis_number)
