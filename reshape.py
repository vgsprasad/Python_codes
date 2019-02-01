class Solution(object):
    def matrixReshape(self, nums, r, c):
        row = len(nums)
        col = len(nums[0])
        if row*col != r*c:
            return nums
        ret_arr = list()
        one_row = list()
        m =0
        n =0
        for i in range(0,r):
            for j in range(0,c):
                one_row.append(nums[m][n])
                n = n+1
                if n==col:
                    m = m+1
                    n =0
            ret_arr.append(one_row)
            one_row=list()
        return ret_arr
