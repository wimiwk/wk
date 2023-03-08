import networkx as nx
import matplotlib.pyplot as plt
import requests
import re
import urllib3
import scipy
urllib3.disable_warnings()
if __name__ =="__main__":
    url='https://github.com/topics/python'
    headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/109.0.0.0 Safari/537.36 Edg/109.0.1518.55'
    }
    page_n=1
    G = nx.Graph()
    for tt in range(500):
        param = {
            'l': 'python',
            'page':str(page_n)
        }
        response=requests.get(url=url,params=param,headers=headers,verify=False)
        list_data=response.text
        page=re.findall('data-turbo="false" href="(.*)" data-view-component="true" class', list_data)
        x=1
        for xx in page:
            name = re.findall('/.*/(.*)', xx)
            G.add_node(str(name))
            url2='https://github.com'+xx
            url6 = url2 + '/network/dependencies'
            response6 = requests.get(url=url6, headers=headers, verify=False)
            page_text6 = response6.text
            dependency = re.findall('"repository" data-hovercard-url="/.*/(.*)/hovercard" href=', page_text6)
            if dependency:
                for kk in dependency:
                    G.add_node(kk)
                    G.add_edge(kk,str(name))
            x+=1
            if x==21:
                break
        page_n+=1
    nx.draw(G, with_labels=True)
    plt.savefig("dependencies.png")
    print('relax my cpu')