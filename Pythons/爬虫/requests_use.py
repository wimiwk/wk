'''requests模块:Python中原生的基于网络请求的模块
作用：-模拟浏览器发请求'''
#爬取搜狗首页
import requests
if __name__ =="__main__": #下面的代码只有在文件作为脚本直接执行时才会被执行，而import到其他脚本不会执行
    #指定url(网址)
    url = 'https://www.soguo.com/'
    #发起请求
    response=requests.get(url=url) #get会返回一个相应对象
    #获取响应数据    .text返回的是字符串形式的响应数据
    page_text=response.text
    print(page_text)
    #持久化存储:page_text
    with open('./sogou.html','w',encoding='utf-8')as fp:   #‘w'是write的缩写
        fp.write(page_text)
    print('爬取数据结束！！！')