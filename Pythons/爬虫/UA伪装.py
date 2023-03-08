#UA:User-Agent(请求载体的身份标识)
#UA检测：网站服务器会检测请求载体的身份标识，如果检测为某一浏览器，则认为是正常请求。否则可能拒绝（爬虫）。
#UA伪装：伪装爬虫成浏览器
import requests
if __name__ =="__main__":
    #UA伪装：将对应的User-Agent封装到一个字典中
    headers={
        'User-Agent':'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/109.0.0.0 Safari/537.36 Edg/109.0.1518.55'
    }
    url = 'https://www.sogou.com/web'
    kw=input('enter a word:')
    param={
        'query':kw
    }
    response=requests.get(url=url,params=param,headers=headers) #头信息被指定为了headers字典，该字典封装了浏览器的身份标识
    page_text=response.text
    filename=kw+'.html'
    with open(filename,'w',encoding='utf-8')as fp:
        fp.write(page_text)
    print(filename,'爬取数据结束！！！')