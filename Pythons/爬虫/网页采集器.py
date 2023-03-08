import requests
if __name__ =="__main__":
    url = 'https://www.sogou.com/web'
    #处理url携带的参数：封装到字典中
    kw=input('enter a word:') #input()中’‘内的会打印出来，变量吸收的是引号外的
    param={
        'query':kw
    }
    #对指定的url发起的请求对应的url是携带参数的，并且请求过程中处理了参数
    response=requests.get(url=url,params=param)
    page_text=response.text
    filename=kw+'.html'
    with open(filename,'w',encoding='utf-8')as fp:
        fp.write(page_text)
    print(filename,'爬取数据结束！！！')