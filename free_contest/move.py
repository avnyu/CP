n, m = [int(i) for i in input().split()]
x1, y1 = [int(i) for i in input().split()]
x2, y2 = [int(i) for i in input().split()]

if (abs(x1 - x2) & 1) or (abs(y2 - y1) & 1):
    print(-1)
    exit()
print(abs(x1 - x2) // 2 + abs(y1 - y2) // 2)
