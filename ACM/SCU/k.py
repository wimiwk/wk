import math

def count_ABC_strings(A, B, C, K):
    # 计算 x 的取值
    x = A + B - C
    # 计算满足条件的字符串个数
    count = math.comb(A + B - C, C)
    # 将结果对 998244353 取模
    count %= 998244353
    return count

# 读取输入
A, B, C, K = map(int, input().split())
# 计算并输出答案
print(count_ABC_strings(A, B, C, K))
