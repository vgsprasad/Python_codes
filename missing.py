class Solution(object):
        def findDisappearedNumbers(self, nums):
            ret =list()
            for i in range(0,len(nums)):
                index = abs(nums[i])-1
                if nums[index] > 0:
                    nums[index] = -nums[index]
            for i in range(0,len(nums)):
                if nums[i]>=0:
                    ret.append(i+1)
            return ret
