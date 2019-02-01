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
				prev = NULL;
				for i in range(0, len(queue)):
					k = queue.popleft()
					if prev == NULL:
						prev= k; 
					else:
						prev.next = k
						prev = k
					if (k.left):
						queue.append(k.left)
					if k.right:
						queue.append(k.right)
			return ret_list

