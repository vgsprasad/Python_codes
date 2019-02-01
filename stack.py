s = " "
string_stack = list()
cmd_stack = list()
string_stack.append(s)
cmd_stack.append(0)
for x in range(input()): 
    inp = raw_input().split(" ")
    cmd = int(inp[0])
    if cmd == 1:
        s= s + inp[1]
    elif cmd == 2:
        s = s[:len(s)-int(inp[1])]
    elif cmd == 3:
        print s[int(inp[1]):(int(inp[1])+1)]
    elif cmd == 4:
        temp_cmd = cmd_stack.pop()
        while(temp_cmd == 3):
            temp_cmd = cmd_stack.pop()
            k = string_stack.pop()
            print "k = ", k
                   
        string_stack.pop()
        s=string_stack.pop()
    print x, s
    string_stack.append(s)
    cmd_stack.append(cmd)

