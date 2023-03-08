import requests
import re
import urllib3
import matplotlib.pyplot as plt
urllib3.disable_warnings()
if __name__ =="__main__":
    plt.title("The ranking list of stars(top 10)")
    url='https://github.com/topics/python'
    headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/109.0.0.0 Safari/537.36 Edg/109.0.1518.55'
    }
    page_n=1
    for tt in range(1):
        param = {
            'l': 'python',
            'page':str(page_n)
        }
        response=requests.get(url=url,params=param,headers=headers,verify=False)
        list_data=response.text
        page=re.findall('data-turbo="false" href="(.*)" data-view-component="true" class', list_data)
        x=1
        color = ['red', 'black', 'peru', 'orchid']
        name_x=[]
        stars_y=[]
        for xx in page:
            name = re.findall('/.*/(.*)', xx)
            name_x.append(str(name))
            url2='https://github.com'+xx
            response2 = requests.get(url=url2, headers=headers,verify=False)
            page_text = response2.text
            stars = re.findall('<strong>(.*)k</strong>\n    stars', page_text)
            for xxxxx in stars:
                stars=float(xxxxx)
            stars_y.append(stars)
            x+=1
            if x==11:
                break
        page_n+=1
        plt.ylabel('stars num(k)')
        p2=plt.bar(name_x, stars_y, bottom=38, color=color)
        plt.bar_label(p2, label_type='edge')
        plt.show()
    print('relax my cpu')
