def convert_base(s, b1,b2):
	decimal = 0 
	power =0
	s = s[::-1]
	for i in range(0,len(s)):
		decimal = decimal + (b1**power)*int(s[i])
		print decimal 
		power = power +1
	
	output = ""
	print decimal 
	while decimal:
		m = decimal % b2
		output = str(s) + output
		decimal = decimal /b2
	return output

s= raw_input()
b1 = input()
b2 = input()

print convert_base(s,b1,b2)
