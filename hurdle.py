import sys


n,k = raw_input().strip().split(' ')
n,k = [int(n),int(k)]
height = map(int, raw_input().strip().split(' '))

temp = max(height)
if temp < k:
    print 0
else:
    print temp-k

