def numones(num):
    count = 0
    while(num & (num-1)):
        count = count +1
        num = num & (num-1)
    return count

def countPrimeSetBits(self, L, R):
    count = 0
    primelist = [2,3,5,7,11,13,17,19]
    for X in range(L,R):
        if numones(X) in primelist:
            count = count+1
    return count 
            
