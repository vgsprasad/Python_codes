class staircase:
	def __init__ (self):
		self.l = list()
		self.l.append(1)
		self.l.append(1)
		self.l.append(2)
		print self.l
	
	def count_ways(self, n):
		for i in range(3, n+1):
			temp = self.l[i-1]+self.l[i-2]+self.l[i-3]
			self.l.append(temp)
		return self.l[n]

st = staircase()
print st.count_ways(13)
