import sys
def getMoneySpent(keyboards, drives, s):
    while (max(keyboards) + max(drives) > s):
	k = max(keyboards)
	l = max(drives)
	if (k < l):
	    keyboards.remove(k)
	else:
	    drives.remove(l)
	if not len(keyboards):
	    return -1
	if not len(drives):
	    return -1
    
    return max(keyboards) + max(drives)
		 

s,n,m = raw_input().strip().split(' ')
s,n,m = [int(s),int(n),int(m)]
keyboards = map(int, raw_input().strip().split(' '))
drives = map(int, raw_input().strip().split(' '))
moneySpent = getMoneySpent(keyboards, drives, s)
print(moneySpent)
