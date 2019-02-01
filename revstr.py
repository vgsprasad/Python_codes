def reverseWords(s):
	stack = list()
	ret = ""
	t = s.strip().split(" ")
	for x in t:
		stack.append(x)
	for i in range(0,len(stack)):
		ret = ret+str(stack.pop())+" "
	return ret[:-1]
print reverseWords("Hi How are you guys"),"Hello"
print "Hello world","Hello"
