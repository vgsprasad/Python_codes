import urllib
import re
from BeautifulSoup import *

count = 0;
url = raw_input("Enter URL:")
allowed_count = int (raw_input("Enter count:"))
allowed_position = int(raw_input("Enter position:"))
for x in range(0, allowed_count): 
    html = urllib.urlopen(url).read()
    soup = BeautifulSoup(html)
    tags = soup('a')
    pos = 0
    for tag in tags:
        url = tag.get('href', None)
	pos = pos + 1
	if pos >= allowed_position:
	    break;
name = re.findall("known_by_(.+).html", url)
print name[0]
