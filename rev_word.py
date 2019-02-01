def reverseWords(s):
	stack = list()
	ret = str()
	t = s.strip().split(" ")
	for x in t:
		stack.append(x)
	for i in range(0,len(stack)):
		ret = ret+str(stack.pop())+" "
	return ret

s = raw_input()
print reverseWords(s)
