#Grab all input
str_input = raw_input();
n = input()
count_arr = list()
input_arr = list()
for i in range(0,n):
    input_arr.append(input())

alpha_string = "abcdefghijklmnopqrstuvwxyz"
orig_dict = { 'a':1, 'b':2, 'c':3,
	    'd':4, 'e':5, 'f':6,
	    'g':7, 'h':8, 'i':9,
	    'j':10, 'k':11, 'l':12,
	    'm':13, 'n':14, 'o':15,
	    'p':16, 'q':17, 'r':18,
	    's':19, 't':20, 'u':21,
	    'v':22, 'w':23, 'x':24,
	    'y':25, 'z':26 }

own_dict = {'a':0, 'b':0, 'c':0,
	    'd':0, 'e':0, 'f':0,
	    'g':0, 'h':0, 'i':0,
	    'j':0, 'k':0, 'l':0,
	    'm':0, 'n':0, 'o':0,
	    'p':0, 'q':0, 'r':0,
	    's':0, 't':0, 'u':0,
	    'v':0, 'w':0, 'x':0,
	    'y':0, 'z':0 }
num_list = list()
for i in range(0, len(str_input)):
    own_dict[str_input[i]] = own_dict[str_input[i]] +1

for x in alpha_string:
    count_num = orig_dict[x]
    loop_count = own_dict[x]
    count = 1;
    new_num =0
    while(loop_count):
	new_num = new_num + count_num
	num_list.append(new_num)
	loop_count = loop_count -1;
	count = count +1;
print num_list 
for i in range(0 ,n):
    if input_arr[i] in num_list:
	print "YES"
    else:
	print "NO"
