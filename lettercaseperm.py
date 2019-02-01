output = list()
def lettercaseperm(s, i, n):
	global output
	if i < n:
		while i<n and not s[i].isalpha():
			i =i+1
		if i<n:
			lettercaseperm(s[:i]+s[i].lower()+s[i+1:],i+1,n)
			lettercaseperm(s[:i]+s[i].upper()+s[i+1:],i+1,n)
		else:
			output.append(s)
	else:
		output.append(s)

s = raw_input()
lettercaseperm(s,0,len(s))
print output


