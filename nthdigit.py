def findNthDigit(n):
    base = 0
    count = 1
    while n > (9*pow(10,count-1) * count):
        n = n - (9*pow(10,count-1) * count)
        base = base + 9*pow(10,count-1)
        count = count + 1
    if n<count:
        ret = base + n/count +1
    else:
        ret = base+n/count
    print ret
    return int(str(ret)[(n%count)-1])

print findNthDigit(input())
		
        
