n, m = map(int, input().split())
s = input()
t = input()

def calc(s, n, t, m):
    res = 0
    i, j = 0, 0
    while i < n and j < m:
        k, l = i, j
        while k < n and s[k] == s[i]:
            k += 1
        while l < m and t[l] == t[j]:
            l += 1
        res += max(k - i, l - j) - 1
        i, j = k, l
    return res

a = calc(s, n, t, m)
b = calc(t, m, s, n)
if a < b:
    n, m = m, n
    s, t = t, s
    a, b = b, a

l, r = 0, n + m
while l < r:
    mid = (l + r + 1) // 2
    flag = False
    i, j = 0, 0
    while i < n and j < m:
        k, l = i, j
        while k < n and s[k] == s[i]:
            k += 1
        while l < m and t[l] == t[j]:
            l += 1
        length = max(k - i, l - j)
        if length >= mid:
            flag = True
            break
        if i < n and j < m and s[i] == t[j]:
            length = max(length, 2)
            if length >= mid:
                flag = True
                break
        i, j = k, l
    if flag:
        l = mid
    else:
        r = mid - 1

print(l)