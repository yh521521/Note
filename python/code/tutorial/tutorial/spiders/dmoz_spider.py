import scrapy


class DmozSpider(scrapy.Spider):
    
    '''
    name = 'cdmoz'
    allowed_domains= ['cdmoz.com']
    start_urls =[
        #'http://www.chinadmoz.org/subindustry/74/',
       # 'http://www.chinadmoz.org/subindustry/75/'
        'http://www.cdmoz.com/subindustry/ruanjianbiancheng/',
        'http://www.cdmoz.com/subindustry/diannaoyingjian/'
        ]
    def parse(self,response):
        filename = response.url.split("/")[-2]
        with open (filename,'wb') as f:
            f.write(response,body)
        
    '''
    name = 'YH'
    allowed_domains=['itcast.cn']
    start_urls =(
         'http://www.itcast.cn/channel/teacher.shtml',
            
        )

    def parse(self,response):
         filename = "teacher.html"
         open(filename, 'w').write(response.body)

    
