
from heapq import *
n = int(raw_input())
a = map(int,raw_input().split())
index = {}

#Keep track of the index
for i in range(n):
    index[a[i]] = i

a.sort()
table = [] #Heap table
for i in range(1,n):
    heappush(table,(a[i]-a[i-1],index[a[i-1]],index[a[i]]))
    
for i in range(n-1):
    element = heappop(table)
    if element[1]>element[2]:
        print element[0]
        break
