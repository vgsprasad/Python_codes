def myversion(s, index):
    global d
    if index in d.keys():
        return d[index]
    else:
		if s[index] > 2:
			return myversion(s, index+1)
		elif s[index] ==2:
			
	
class Solution(object):
    def numDecodings(self, s):
	global d
        d = dict()
        d[0] = myversion(s, 0)
		return d[0]
        
        
