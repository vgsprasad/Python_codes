n = input()
for i in range(0,n):
    arr_len = input()
    arr = map(int, raw_input().strip(" "))
    sum_left = 0
    sum_right = sum(arr)
    found = 0
    for i in range(0, arr_len):
	sum_right = sum_right - arr[i]
	if sum_left == sum_right:
	    print "YES"
	    found = 1
	    break;
	else:
	    sum_left = sum_left + arr[i]
    if not found:
	print "NO"


