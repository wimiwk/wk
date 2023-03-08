import matplotlib.pyplot as plt
plt.title("title")#括号当中输入标题的名称
x= {1,
    2,
    3,
    4,
    5}  # 确定柱状图数量,可以认为是x方向刻度
x=list(x)
y=[5,7,4,3,1]  # y方向刻度
color=['red','black','peru','orchid']
x_label=['pop','classic','pure','blue','electronic']
#plt.xticks(x, x_label)  # 绘制x刻度标签
plt.bar(x_label, y,color=color)  # 绘制y刻度标签
plt.show()