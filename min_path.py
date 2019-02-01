class Solution(object):
	def minimumTotal(self, triangle):
		mat_len = len(triangle)

		for i in range(matlen-1, -1):
			target_list = triangle[i]
			if i == mat_len -1:
				for j in range(0, target_list):
					min_count[i][j] = triangle[i][j]
			else:
				for j in range(0, len(target_list)):
					min_count[i][j] = min(min_count[i+1][j], min_count[i+1][j+1]) + triangle[i][j]


