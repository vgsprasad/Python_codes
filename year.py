cal_leap = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30 ,31]
cal_nonleap = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 ,31]
conv_leap = [31, 16, 31, 30, 31, 30, 31, 31, 30, 31, 30 ,31]
conv_nonleap = [31, 15, 31, 30, 31, 30, 31, 31, 30, 31, 30 ,31]

def leap_year(year):
    if year % 4:
	return 0
    else:
	if year%100:
	    return 1
	else:
	    if year%400:
		return 1
	    else:
		return 0

def two_fifty_sixth_day(arr, year):
    month = 1
    date  = 0
    const = 256 
    for i in range(0, 11):
	if arr[i] < const:
	    const = const - arr[i]
	    month = month + 1
	else:
	    date = const+1
    return (str(date) + "." + str(month) + "." + str(year))
def greg_day(year):
    if leap_year(year):
	return two_fifty_sixth_day(cal_leap, year)
    else:
	return two_fifty_sixth_day(cal_nonleap, year)
def change_day(year):
    if leap_year(year):
	return two_fifty_sixth_day(conv_leap, year)
    else:
	return two_fifty_sixth_day(conv_nonleap, year)
def julian_day(year):
    if not year % 4:
	return two_fifty_sixth_day(cal_leap, year)
    else:
	return two_fifty_sixth_day(cal_nonleap, year)

year = input()
if (year > 1918):
    print greg_day(year)
elif year == 1918:
    print change_day(year)
else:
    print julian_day(year)
