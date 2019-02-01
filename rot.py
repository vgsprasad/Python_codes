class Solution(object):
    def search(self, nums, target):
		if len(nums) == 1:
			if target == nums[0] :
				return True
			else:
				return False
		middle_element = nums[len(nums)/2]
        if target == middle_element:
            return True
		elif target > middle_element:
			if nums[0] > nums[len(nums)-1]:

