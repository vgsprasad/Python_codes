n = input()
arr = map(int, raw_input().split(" "))
arr.sort()
count_arr = list()
for x in range(0,5):
    count_arr[x] = 0
for x in range(0, len(arr)):
    count_arr[arr[x]] = count_arr[arr[x]] + 1
minimal = -1
for x in range(0,5):
    if count_arr[x] > minimal:
	output = x
	minimal = count_arr[x]
print output 


