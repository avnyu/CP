n = int(input())
k = int(input())
p = int(input())
q = int(input())
x = (p - 1) * 2 + q - 1
x1 = x - k
x2 = x + k
u1, v1 = x1 // 2 + 1, x1 % 2 + 1
u2, v2 = x2 // 2 + 1, x2 % 2 + 1
if p - u1 <= u2 - p and x1 >= 0:
    print(u1, v1)
    exit()
else:
    print(u2, v2)
    exit()