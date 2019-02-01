n = int(raw_input())
string = raw_input()
gnd_level = 0
valley_cnt = 0
for i in range(0,n):
    prev_gnd_level = gnd_level; 
    if string[i] == 'U':
	gnd_level = gnd_level + 1
    else:
	gnd_level = gnd_level - 1;

    if (prev_gnd_level < 0 and gnd_level == 0 ):
	valley_cnt = valley_cnt + 1
print valley_cnt

