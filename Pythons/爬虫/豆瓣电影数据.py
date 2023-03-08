#页面发生变动时，如果url未变化，则为局部刷新，发出的是Ajax（阿贾克斯）请求
#是get请求
import requests
import json
if __name__ =="__main__":
    url='https://movie.douban.com/j/chart/top_list' #抓包时滚动会有新请求出现，该请求的url？后面的是参数，删去并将参数封装到字典中
    param={
        'type':'24',
        'interval_id':'100:90',
        'action':'',
        'start':'40', #从第几个电影开始
        'limit':'20', #取多少个
    } #参数在负载中;字典参数之间用，隔开
    headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/109.0.0.0 Safari/537.36 Edg/109.0.1518.55'
    }
    #请求发送
    response=requests.get(url=url,params=param,headers=headers)
    list_data=response.json()
    fp=open('./豆瓣.json','w',encoding='utf-8')
    json.dump(list_data,fp=fp,ensure_ascii=False) #ensure_ascii为True，则输出ASCII码，为False则可以输出中文
    print('爬取数据结束！！！')