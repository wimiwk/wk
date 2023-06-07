import numpy as np
net_re=np.load('test_y.npy')
qianyi_re=np.load('result_.npy')
m=0
for i in range(5000):
    #print(qianyi_re[i],net_re[i])
    if net_re[i]==qianyi_re[i]:
        m+=1
print(m/5000*100,'%')


