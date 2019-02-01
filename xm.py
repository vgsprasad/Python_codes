import urllib as U
from xml.etree import ElementTree as ET

url = raw_input("Enter an URL -:")
url_data = U.urlopen(url).read()
xml_obj = ET.fromstring(url_data)
comment = xml_obj.findall('comments/comment')
s = 0;
for i in comment :
        s += int (i.find('count').text)
print s
