class Fibonacci:
	def __init__(self):
		self.d = dict()
	def get_fib(self, n):
		if n<2:
			return n
		if n in self.d:
			return self.d[n]
		self.d[n] = self.get_fib(n-1) + self.get_fib(n-2)
		return self.d[n]
f = Fibonacci()
print f.get_fib(800)
