n, m = [int(i) for i in input().split()]
a = [int(i) for i in input().split()]
b = [int(i) for i in input().split()]
i, j, s = 0, 0, 1.0
while 1:
    if s < 1e9 and i < n:
        s = s * a[i]
        i += 1
    elif j < m:
        s = s / b[j]
        j += 1
    elif i < n:
        s = s * a[i]
        i += 1
    else:
        break
print(int(s))
