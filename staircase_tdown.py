class staircase:
	def __init__(self):
		self.d = dict()
	def count_ways(self, n):
		if n < 0:
			return -1
		if n == 0:
			self.d[0] = 1
			return 1
		if n == 1:
			self.d[1] = 1
			return 1
		if n == 2:
			self.d[2] = 2
			return 2
		else:
			if n in self.d:
				return self.d[n]
			else:
				self.d[n] = self.count_ways(n-1) + self.count_ways(n-2) + self.count_ways(n-3)
				return self.d[n]
st = staircase()
print st.count_ways(3)
print st.count_ways(4)
print st.count_ways(5)
print st.count_ways(13)
print st.count_ways(14)
print st.count_ways(15)

