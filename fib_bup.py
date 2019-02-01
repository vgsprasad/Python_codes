class fibonacci:
	def __init__(self):
		self.l = list()
		self.l.append(0)
		self.l.append(1)
	
	def get_fib(self, n):
		if n < 2:
			return n
		else:
			for i in range(2,n+1):
				self.l.append(self.l[i-1] +self.l[i-2])
			return self.l[n]
f = fibonacci()
print f.get_fib(100)
