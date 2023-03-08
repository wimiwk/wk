num=input()
step=input()
a=len(num)/len(step)
b=len(num)//len(step)
e=int(num)
f=int(step)
if a==b:
    c=a
else:
    c=a+1
d=0
i=0
while i<c:
    d+=e%(10**f)
    e//=(10**f)
    i+=1
print(d)

