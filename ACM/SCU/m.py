from collections import defaultdict

def dfs(graph, start, end, visited):
    visited.add(start)
    if start == end:
        return True
    for neighbor in graph[start]:
        if neighbor not in visited:
            if dfs(graph, neighbor, end, visited):
                return True
    return False

n = int(input())
graph = defaultdict(list)
for _ in range(n):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)

q = int(input())
for _ in range(q):
    x, y = map(int, input().split())
    visited = set()
    if dfs(graph, x, y, visited):
        if len(visited) == 2:
            print("Yes")
        else:
            print("No")
    else:
        print("No")
