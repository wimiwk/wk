import requests
import re
if __name__ =="__main__":
    url='https://www.4399.com/'
    headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/109.0.0.0 Safari/537.36 Edg/109.0.1518.55'
    }
    response=requests.get(url=url,headers=headers)
    list_data=response.text
    fp = open('./4399.text', 'w', encoding='GB18030')
    fp.write(list_data)
    print('爬取数据结束！！！')