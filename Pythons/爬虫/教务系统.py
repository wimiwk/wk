import requests
if __name__ =="__main__":
    url='http://zhjw.scu.edu.cn/j_spring_security_check'
    headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/109.0.0.0 Safari/537.36 Edg/109.0.1518.55'
    }
    param = {
        'tokenValue': '131781777d9bb1ec0a62d6ef1eb56a14',
        'j_username': '2022141460123',
        'j_password': 'b7c92ba53ccd5e0aa836e688eedd3efc',
        'j_captcha': 'd32c',
    }
    response=requests.get(url=url,headers=headers,params=param)
    list_data=response.text
    fp=open('./教务系统.text','w',encoding='utf-8')
    fp.write(list_data)
    #json.dump(list_data,fp=fp,ensure_ascii=False) #ensure_ascii为True，则输出ASCII码，为False则可以输出中文
    print('爬取数据结束！！！')