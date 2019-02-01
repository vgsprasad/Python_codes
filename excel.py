
def getd(m):
    d = dict()
    for i in range(0,26):
        d[i] = (chr(i+ord('A')))
    if not m:
        return d[25]
    else:
        return d[m-1]

def get_col(num):
    s=str()
    while num:
        m = num%26
        s = getd(m)+s
        num = num/26
    return s

num = input()
print get_col(num)
