# Enter your code here. Read input from STDIN. Print output to STDOUT
n = input()
res = list()
num_array = list()
for i in range(0,n):
    cmd = map(int, raw_input().split())
    if cmd[0] == 1:
        num_array.append(cmd[1])
    elif cmd[0] == 2:
        num_array.pop()
    else:
        res.append(max(num_array))
for i in res:
    print i
