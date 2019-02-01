import urllib as u 
import json as j 

total =0
url = raw_input("Enter URL : ")
s = u.urlopen(url).read()
print "Retrieving", url
print "Retrieved",len(s),"charachters"
info = j.loads(s)
print "Count:", len(info["comments"])
for x in info["comments"]:
    total += x["count"]
print "Sum:", total
