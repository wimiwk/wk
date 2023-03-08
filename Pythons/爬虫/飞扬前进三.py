import requests
import re
import urllib3
urllib3.disable_warnings()
if __name__ =="__main__":
    url='https://github.com/topics/python'
    headers = {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/109.0.0.0 Safari/537.36 Edg/109.0.1518.55'
    }
    page_n=1
    fp = open('./for github.text', 'w', encoding='utf-8')
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
            fp.write(str(x+tt*20)+'.')
            name = re.findall('/.*/(.*)', xx)
            fp.write('name:')
            fp.writelines(name)
            fp.write('\n')
            url2='https://github.com'+xx
            fp.write('url:')
            fp.writelines(url2)
            fp.write('\n')
            response2 = requests.get(url=url2, headers=headers,verify=False)
            page_text = response2.text
            stars = re.findall('<strong>(.*k)</strong>\n    stars', page_text)
            fp.write('stars num:')
            fp.writelines(stars)
            fp.write('\n')
            fork = re.findall('<strong>(.*k)</strong>\n    forks', page_text)
            fp.write('forks num:')
            fp.writelines(fork)
            fp.write('\n')
            About = re.findall('<p class="f4 mb-3 ">\n        (.*)', page_text)
            fp.write('About:')
            fp.writelines(About)
            fp.write('\n')
            Readme=url2+'/blob/master/README.md'
            fp.write('Readme:')
            fp.write(Readme)
            fp.write('\n')
            topic=re.findall('="topic:(.*)" href', page_text)
            fp.write('topic:')
            for hh in topic:
                fp.writelines(hh)
                fp.write(',')
            fp.write('\n')
            contributors= re.findall('Contributors <span title="(.*)" data', page_text)
            fp.write('contributors num:')
            fp.writelines(contributors)
            fp.write('\n')
            language= re.findall(';" itemprop="keywords" aria-label="(\w*)', page_text)
            fp.write('language:')
            for jj in language:
                fp.writelines(jj)
                fp.write(',')
            fp.write('\n')
            url3=url2+'/branches'
            response3=requests.get(url=url3, headers=headers,verify=False)
            page_text3 = response3.text
            branch= re.findall('branch="(.*)"', page_text3)
            branch_count=0
            for yy in branch:
                branch_count+=1
            fp.write('branches num:')
            fp.write(str(branch_count))
            fp.write('\n')
            release= re.findall('<strong>(.*)</strong>\n        <span class="color-fg-muted">', page_text)
            fp.write('release num:')
            fp.writelines(release)
            fp.write('\n')
            url4=url2+'/issues'
            response4 = requests.get(url=url4, headers=headers, verify=False)
            page_text4 = response4.text
            issues_c= re.findall('</svg>\n      (.*) Closed\n    </a>\n</div>', page_text4)
            issues_o= re.findall('</svg>\n      (.*) Open\n    </a>', page_text4)
            fp.write('issues open:')
            fp.writelines(issues_o)
            fp.write('\n')
            fp.write('issues closed:')
            fp.writelines(issues_c)
            fp.write('\n')
            url5 = url2 + '/pulls'
            response5 = requests.get(url=url5, headers=headers, verify=False)
            page_text5 = response5.text
            pull_c = re.findall('</svg>\n      (.*) Closed\n    </a>\n</div>', page_text5)
            pull_o = re.findall('</svg>\n      (.*) Open\n    </a>', page_text5)
            fp.write('pull requests open:')
            fp.writelines(pull_o)
            fp.write('\n')
            fp.write('pull requests closed:')
            fp.writelines(pull_c)
            fp.write('\n')
            url6 = url2 + '/network/dependencies'
            response6 = requests.get(url=url6, headers=headers, verify=False)
            page_text6 = response6.text
            dependency = re.findall('"repository" data-hovercard-url="(.*)/hovercard" href=', page_text6)
            fp.write('dependencies:')
            if dependency:
                for kk in dependency:
                    fp.writelines(kk)
                    fp.write(',')
                fp.write('\n')
            else:
                fp.write('No dependency')
            fp.write('\n\n\n')
            x+=1
            if x==21:
                break
        page_n+=1
    fp.close()
    print('relax my cpu')
