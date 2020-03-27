import urllib.request
import urllib.parse
import json

import time

while True:
    content = input('请输入需要翻译的内容(输入"q!"退出程序):')
    if content =='q!':
        break
    url= 'http://fanyi.youdao.com/translate?smartresult=dict&smartresult=rule'

    '''
    head= {}
    head['User-Agent'] = 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/71.0.3578.98 Safari/537.36'
    '''
    data = {}

    data['i']=content
    data['type']=' AUTO'
    data['doctype']= 'json'
    data['version']= '2.1'
    data['keyfrom']= 'fanyi.web'
    data['smartresult']= 'dict'
    data['client']= 'fanyideskweb'
    data['salt']= '15843310877703'
    data['ts']= '1584331087770'
    data['action']= 'FY_BY_CLICKBUTTION'

    data=urllib.parse.urlencode(data).encode('utf-8')
    req =urllib.request.Request(url,data)
    req.add_header('User-Agent','Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/71.0.3578.98 Safari/537.36')
    response = urllib.request.urlopen(req)
    html = response.read().decode('utf-8')
    target = json.loads(html)
    ## print("翻译结果: %s" %(target['translateResult'][0][0]['tgt']))
    target = target['translateResult'][0][0]['tgt']
    print(target)
    time.sleep(5)
