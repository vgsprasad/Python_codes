q = int(raw_input().strip())
output = list()
for a0 in xrange(q):
    x,y,z = map(int , raw_input().strip().split(' '))
    if z > x and z >= y:
	if x > y:
	    output.append("Cat A")
	else:
	    output.append("Cat B")
    elif z <= x and z < y:
	if x > y:
	    output.append("Cat B")
	else:
	    output.append("Cat A")
    elif z > x and z < y:
	if abs(z-x) > abs(z-y):
	    output.append("Cat B")
	elif abs(z-x) < abs(z-y):
	    output.append("Cat A")
	else: 
	    output.append("Mouse C");
    elif z > y and z < x:
	if abs(z-x) > abs(z-y):
	    output.append("Cat A")
	elif abs(z-x) < abs(z-y):
	    output.append("Cat B")
	else: 
	    output.append("Mouse C");
for i in range(0, len(output)):
    print output[i]
