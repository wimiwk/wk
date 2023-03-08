import networkx as nx
import matplotlib.pyplot as plt
'''Graph：无多重边无向图
DiGraph：无多重边有向图
MultiGraph：有多重边无向图
MultiDiGraph：有多重边有向图'''
#空图对象的创建方式
G=nx.Graph()
G=nx.DiGraph()
G=nx.MultiGraph()
G=nx.MultiDiGraph()
G.clear() #清空图


G.add_node(1) #添加单个节点
G.add_node("x",name='tome') #添加单个节点及属性
G.add_nodes_from([2,3]) #从一个可迭代容器中添加多个节点
G.add_nodes_from([(4, {"color": "red"}), (5, {"color": "green"})])# 添加节点和属性

H = nx.path_graph(10) #创建一个新图
G.clear() # 清空图
G.add_nodes_from(H) #从另一张图中添加节点
print(list(H.nodes))
print(list(G.nodes))

G.add_edge(1,3)#添加一条边
G.add_edges_from([(2,3),(3,4)])# 添加多条边

list(G.nodes) #查看节点
for k, v in G.nodes.items():  print(k,v)  #查看节点及属性
G.number_of_nodes() #查看几个节点
G.adj[1] #查看邻居节点
G[1] #查看邻居节点
list(G.neighbors(1)) #查看邻居节点

G.number_of_edges() #查看几条边
G.add_edge(1,3) #查看特定边
G.edges() #查看边
G.add_edge(2,3)
G.edges([1]) #查看1连接的所有边
G.edges([3]) #查看1连接的所有边

G.degree[1] #查看度

for node,neighbors in g.adjacency():
    print(node, neighbors) # 查看邻接矩阵内容

#删除节点和边
G.remove_node(4)
G.remove_edge(1,3)
#用已有的图构建新图
# 构建有向图
g = nx.DiGraph(G)
nx.draw(g)

#获取节点和边
G = nx.Graph([(1,2,{'color':'red'})])
G[1] #获取1的邻居节点
G[1][2] #获取边属性
G.edges[1,2] #获取边属性

# 图级别属性
g = nx.Graph(day = 'none')
g.graph #输出图级别的属性信息
g.graph['day']= 'tom' #修改图级别属性信息
g.graph['date']= 'now' #添加图级别属性信息
# 节点属性
g.add_node(1, time='now')
g.add_nodes_from([2,3,4,5,6], time='yes')
g.nodes.data()
g.nodes[2]
# 边属性
g.add_edge(1,2,time='now')
g.add_edges_from([(1,2,{'time':'now'}),(1,3,{'time':'naw'})])
G[1][2]['color'] = 'blue'
G.edges[1,2]['color'] ='Y'
g.edges.data()
# 分析图：连通分量
g.clear()
g.add_edges_from([(1,2),(3,2)])
g.add_nodes_from("spam")
list(nx.connected_components(g)) #有5个连通分量
nx.draw(g) #可视化
#分析图：按度排序
sorted(((node,degree) for node,degree in g.degree), key= lambda d:d[1],reverse = True)
# 图可视化
g = nx.petersen_graph()
nx.draw(g, with_labels = True) #标明label
# 从edgelist读取图
g = nx.read_edgelist('edglist.txt')
nx.draw(g, with_labels= True)
#保存图
plt.savefig("path.png")







'''绘制网络图基本流程:
导入networkx，matplotlib包
建立网络
绘制网络 nx.draw()
建立布局 pos = nx.spring_layout美化作用
最基本画图程序'''
import networkx as nx                               #导入networkx包
import matplotlib.pyplot as plt
G = nx.random_graphs.barabasi_albert_graph(100,1)   #生成一个BA无标度网络G
nx.draw(G)                                          #绘制网络G
plt.savefig("ba.png")                               #输出方式1: 将图像存为一个png格式的图片文件
plt.show()                                          #输出方式2: 在窗口中显示这幅图像

'''networkx 提供画图的函数:
draw（G，[pos,ax,hold]）
draw_networkx(G，[pos,with_labels])
draw_networkx_nodes(G,pos,[nodelist])绘制网络G的节点图
draw_networkx_edges(G,pos[edgelist])绘制网络G的边图
draw_networkx_edge_labels(G, pos[, …]) 绘制网络G的边图，边有label
—有layout 布局画图函数的分界线—
draw_circular(G, **kwargs) Draw the graph G with a circular layout.
draw_random(G, **kwargs) Draw the graph G with a random layout.
draw_spectral(G, **kwargs)Draw the graph G with a spectral layout.
draw_spring(G, **kwargs)Draw the graph G with a spring layout.
draw_shell(G, **kwargs) Draw networkx graph with shell layout.
draw_graphviz(G[, prog])Draw networkx graph with graphviz layout.

networkx 画图函数里的一些参数
pos(dictionary, optional): 图像的布局，可选择参数；如果是字典元素，则节点是关键字，位置是对应的值。如果没有指明，则会是spring的布局；也可以使用其他类型的布局，具体可以查阅networkx.layout
arrows :布尔值，默认True; 对于有向图，如果是True则会画出箭头
with_labels: 节点是否带标签（默认为True）
ax：坐标设置，可选择参数；依照设置好的Matplotlib坐标画图
nodelist：一个列表，默认G.nodes(); 给定节点
edgelist：一个列表，默认G.edges();给定边
node_size: 指定节点的尺寸大小(默认是300，单位未知，就是上图中那么大的点)
node_color: 指定节点的颜色 (默认是红色，可以用字符串简单标识颜色，例如’r’为红色，'b’为绿色等，具体可查看手册)，用“数据字典”赋值的时候必须对字典取值（.values()）后再赋值
node_shape: 节点的形状（默认是圆形，用字符串’o’标识，具体可查看手册）
alpha: 透明度 (默认是1.0，不透明，0为完全透明)
cmap：Matplotlib的颜色映射，默认None; 用来表示节点对应的强度
vmin,vmax：浮点数，默认None;节点颜色映射尺度的最大和最小值
linewidths：[None|标量|一列值];图像边界的线宽
width: 边的宽度 (默认为1.0)
edge_color: 边的颜色(默认为黑色)
edge_cmap：Matplotlib的颜色映射，默认None; 用来表示边对应的强度
edge_vmin,edge_vmax：浮点数，默认None;边的颜色映射尺度的最大和最小值
style: 边的样式(默认为实现，可选：solid|dashed|dotted,dashdot)
labels：字典元素，默认None;文本形式的节点标签
font_size: 节点标签字体大小 (默认为12)
font_color: 节点标签字体颜色（默认为黑色）
node_size：节点大小
font_weight：字符串，默认’normal’
font_family：字符串，默认’sans-serif’
'''
