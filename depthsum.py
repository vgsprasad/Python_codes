def depthSum(nestedList):
	final_depth = 0;
	depth = 0
	for x in nestedList:
		if x == '[':
			depth = depth+1
		elif x == ']':
			depth = depth-1
		elif x.isdigit():
			final_depth = final_depth + depth*int(x)
	return final_depth
print depthSum(raw_input())
