class Solution(object):
	def inorderTraversal(self, root):
		done = 0
		stack = list()
		res = list()
		current = root
		while not done:
			if current:
				stack.append(current)
				current = current.left
			else:
				if len(stack):
					temp = stack.pop()
					res.append(temp.val)
					current=temp.right 
				else: 
					done =1
		return res


