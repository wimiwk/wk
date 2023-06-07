def min_operations(n, permutation):
    inversions = 0  # 逆序对数量
    for i in range(n):
        for j in range(i + 1, n):
            if permutation[i] > permutation[j]:
                inversions += 1
    
    reverse_inversions = n - inversions  # 反转排列的逆序对数量
    
    return min(inversions, reverse_inversions)

# 读取输入
n = int(input())
permutation = list(map(int, input().split()))

# 调用函数并输出结果
result = min_operations(n, permutation)
print(result)
