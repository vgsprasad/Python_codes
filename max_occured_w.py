class Solution(object):
	def mostCommonWord(self, paragraph, banned):
		local_dict = dict()
		for x in paragraph:
			if x in local_dict.keys():
				local_dict[x] = local_dict[x]+1
			else:
				local_dict[x] = 1
		while 1:
			max_item = max(sorted(local_dict.values))
			for i in local_dict.keys():
				if local_dict[i] == max_item:
					max_key = i
					break
			if max_key not in banned:
				break
			else:
				local_dict[max_key] = 0
		return max_key

