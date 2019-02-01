import re
fh = open("regex_sum_291017.txt")
total = 0
for line in fh:
    l = re.findall('[0-9]+', line)
    n = map(int, l)
    total += sum(n)
print total
