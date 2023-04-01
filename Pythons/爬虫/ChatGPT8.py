import requests
if __name__ =="__main__":
    url='https://chat8.io/go/api/user/login'
    headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/109.0.0.0 Safari/537.36 Edg/109.0.1518.55'
    }
    param = {
        "language": "zh",
        "os": "h5",
        "pars": {"tel": "15722571019", "login_passwd": "39e63ae51436e480bcac0c41abdc97a1"},
        "login_passwd": "39e63ae51436e480bcac0c41abdc97a1",
        "tel": "15722571019",
        "version": "1.0.0",
    }
    response=requests.get(url=url,headers=headers,params=param)
    list_data=response.text
    fp=open('./chatgpt.text','w',encoding='utf-8')
    fp.write(list_data)
    #json.dump(list_data,fp=fp,ensure_ascii=False) #ensure_ascii为True，则输出ASCII码，为False则可以输出中文
    print('爬取数据结束！！！')