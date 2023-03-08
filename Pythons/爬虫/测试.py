import requests
if __name__ =="__main__":
    headers={
        'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/109.0.0.0 Safari/537.36 Edg/109.0.1518.61'
    }
    url = 'https://github.com/topics/python'
    page=1
    param = {
        'l': 'python',
        'page':str(page),
    }
    response=requests.get(url=url,params=param,headers=headers,verify=False)
    page_text=response.text
    with open('./github.html','w',encoding='utf-8')as fp:
        fp.write(page_text)

    print('爬取数据结束！！！')