import requests
import json
if __name__ =="__main__":
    url='http://scxk.nmpa.gov.cn:81/xk/'
    headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/109.0.0.0 Safari/537.36 Edg/109.0.1518.55'
    }
    response=requests.get(url=url,headers=headers)
    list_data=response.json()
    fp=open('./药监局.json','w',encoding='utf-8')
    json.dump(list_data,fp=fp,ensure_ascii=False)
    print('爬取数据结束！！！')