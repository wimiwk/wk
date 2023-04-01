#单行注释
"""多行注释"""
print("hello")
print(type("hello"))#打印出   <class '数据类型(str/int/float)'>
a=str(11)
print(type(a),a)
b=int("11")
print(type(b),b)
c=float(13)#python中没有double类型
print(type(c),c)
print(9/7)#正常除法
print(9%7)#取余
print(9//2)#整除
print(9**2)#次方
#同时适用于  **= /= //= %=
d='le'
e="le"
f="""le"""
#三种都可以，""" """在有被变量吸收时不为注释
g="lele'le'lele\"le\""#引号内可以打印另一种引号，也可以用\消除引用
print(g)
print("le"+"le")#字符串拼接，+可以不要，也可以逗号。但用+时只能都是字符串
op=4
oy='om%s'%op  # %是占位，s是把占位者变为字符串型，%是拼接，后面是占位者
on='%s%s%s'%(a,b,c)#类似c
print(oy)
print(on)
print('%5.1f'%21) #m.n   m表示一共多少位，n表示小数位数，有效位不足m用空格补齐
print(f"9999{on}")#可以在字符串前加f表面字符串内有占位，占位可直接{内容}，但不可改变内容的类型
"""h=input()
print(type(int(h)))
print(type(h))
"""#input只能键入字符类型
print(type(3==4),3==4)#bool类型,输出False或True
nana=10
if nana>8:
    print(f"我要{nana}")#只有在if语句下缩进了4个空格才能属于if判断内
print(f'一定输出{nana}')
if nana>8:
    print('nana>8')
elif nana<8:
    print('nana<8')#elif相当于c中else if
else:
    print('nana=8')


