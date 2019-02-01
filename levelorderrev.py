from collections import deque
class Solution(object):
	    def levelOrder(self, root):
			ret_list = list()
			queue = deque()
			if not root: 
				return ret_list

			queue.append(root)
			while len(queue) > 0:
				temp = list()
				for i in range(0, len(queue)):
					k = queue.popleft()
					temp.append(k.val)
					if (k.left):
						queue.append(k.left)
					if k.right:
						queue.append(k.right)
				ret_list.append(temp)
			return ret_list[:len(ret_list)-1].reverse()

