import urllib.request
response = urllib.request.urlopen('http://placekitten.com/1000/550')
cat_img = response.read()
with open('cat_1000_550.jpg','wb') as f:
    f.write(cat_img)
