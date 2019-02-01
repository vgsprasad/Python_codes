def dig_reverse(x):
	result =0
	while x:
		temp = x%10
		result = result*10+temp
		x = x/10
	return result
print dig_reverse(input())

