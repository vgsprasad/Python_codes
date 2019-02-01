import sys
import math

output = list()
s = raw_input().strip().replace(' ', '')
length = len(s)

square_root = int(math.sqrt(length))
row = square_root
if square_root ** 2 < length :
    col = row + 1
else:
    col = row

i =0
while (i < length):
    output.append(s[i:(i+col)])
    i = i+ col

for i in range(0,row):
    for j in range(0, col):
	print output[i][j],
    print ""

