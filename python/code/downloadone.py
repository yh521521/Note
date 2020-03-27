import urllib.request
import re

def open_url(url):
    req = urllib.request.Request(url)
    req.add_header('User-Agent','Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/71.0.3578.98 Safari/537.36')
    page = urllib.request.urlopen(req)
    html = page.read().decode('utf-8')

    return html

def get_img(html):
    p = r'<img class="BDE_Image"  src="([^"]+\.jpg)"'
    imglist = re.findall(p,html)
    for each in imglist:
        print(each)
if __name__ == '__main__':
    url = 'http://tieba.baidu.com/p/6552162167'
    get_img(open_url(url))
