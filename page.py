#!/bin/python

import sys
res = list()
def solve_f(n, p):
    if p == 1:
	return 0 
    else:
	return p/2
def solve_l(n,p):
    if ( n % 2 == 0):
	if (p == n):
	    return 0 
	else:
	    return (n-p+1)/2
    else:
	if ((p == n) or (p == n-1)):
	    return 0 
	else:
	    return (n-p)/2

def solve(n, p):
    res.append(solve_f(n,p))
    res.append(solve_l(n,p))
    return min(res)

n = int(raw_input().strip())
p = int(raw_input().strip())
result = solve(n, p)
print(result)
