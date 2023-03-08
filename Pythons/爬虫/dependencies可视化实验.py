import networkx as nx
import matplotlib.pyplot as plt
G=nx.Graph()
name='str'
G.add_node(name)
G.add_node('STR')
G.add_edge(name,'STR')
nx.draw(G, with_labels = True)
plt.savefig("path.png")
