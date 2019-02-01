import urllib
import re
from BeautifulSoup import *

url = raw_input("Enter an URL -");
html = urllib.urlopen(url).read()
soup_obj = BeautifulSoup(html)
tags = soup_obj('span')
s = 0
for tag in tags :
    s+=int (tag.contents[0])
print s
