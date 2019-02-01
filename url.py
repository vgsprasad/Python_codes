import urllib

fh = urllib.urlopen("http://www.pythonlearn.com/code/BeautifulSoup.py")
fh1 = open("BeautifulSoup.py","w")
for line in fh:
    fh1.write(line)

