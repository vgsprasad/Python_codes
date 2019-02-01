def deleteleaves(root, l):
	if not root:
		return root
	elif root.left == None and root.right== None:
		l.append(root.val)
		return NULL
	else:
		root.left = deleteleaves(root.left, l)
		root.right = deleteleaves(root.right, l)
		return root

class Solution(object):
	def findLeaves(self, root):
		result= list()
		while(root):
			l = list()
			root = deleteleaves(root, l)
			result.append(l)
		return result

