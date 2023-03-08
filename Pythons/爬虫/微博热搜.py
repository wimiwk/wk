import requests
import re
import xlsxwriter
if __name__ =="__main__":
    url='https://weibo.com/ajax/statuses/hot_band'
    headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/109.0.0.0 Safari/537.36 Edg/109.0.1518.55'
    }
    response=requests.get(url=url,headers=headers)
    list_data=response.text
    page=re.findall('"word":"(\w*)"', list_data)
    page2 = re.findall('"realpos":(\d*)', list_data)
    workbook = xlsxwriter.Workbook('./微博.xlsx')
    worksheet = workbook.add_worksheet()
    x=1
    y=0
    worksheet.write(0, 0, '排名')
    worksheet.write(0, 1, '名称')
    for xx in page2:
        worksheet.write(x,y,xx)
        x+=1
        if x==11:
            break
    y+=1
    x=1
    for xx in page:
        worksheet.write(x,y,xx)
        x+=1
        if x==11:
            break
    workbook.close()
    print('爬取数据结束！！！')