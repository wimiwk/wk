#对该url进行一个post请求（携带参数）
#发现相应数据是一组json数据
import requests
import json
if __name__ =="__main__":
    post_url='https://fanyi.baidu.com/sug'
    headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/109.0.0.0 Safari/537.36 Edg/109.0.1518.55'
    }
    #用字典对post请求进行参数处理（同get一致）
    kw=input('enter a word:')
    data={
        'kw':kw
    }
    #请求发送
    response=requests.post(url=post_url,data=data,headers=headers)
    #获取响应数据：json（）返回的是obj（对象）   （如果确认响应数据是json类型的，才能使用json（） ）
    #辨别响应数据类型：网页按f12，得到抓包，在网络（Network）栏中进入标头（Headers）栏，其中response headers里的content-type便是数据类型
    dic_obj=response.json()
    filename=kw+'.json'
    fp=open(filename,'w',encoding='utf-8')
    json.dump(dic_obj,fp=fp,ensure_ascii=False) #ensure_ascii为True，则输出ASCII码，为False则可以输出中文
    print(filename,'爬取数据结束！！！')