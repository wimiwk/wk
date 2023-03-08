import requests
import json
if __name__ =="__main__":
    url='http://zhjw.scu.edu.cn/student/courseSelect/thisSemesterCurriculum/callback'
    headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/109.0.0.0 Safari/537.36 Edg/109.0.1518.55'
    }
    response=requests.get(url=url,headers=headers)
    list_data=response.text
    fp=open('./教务系统.json','w',encoding='utf-8')
    #json.dump(list_data,fp=fp,ensure_ascii=False) #ensure_ascii为True，则输出ASCII码，为False则可以输出中文
    print(list_data)
    print('爬取数据结束！！！')