import sys
n,k = raw_input().strip().split(' ')
n,k = [int(n),int(k)]
c = map(int,raw_input().strip().split(' '))
energy  = 100
if n%k:
    print 0
else:
    i = 0;
    while i < n:
        index = (i + k) % n
        if c[index]:
            energy = energy - 3
        else:
            energy = energy - 1
	i =  i + k
    print energy

