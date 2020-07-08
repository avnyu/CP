n = int(input())
a = [int(i) - 1 for i in input().split()]
b = [int(i) - 1 for i in input().split()]

c = list(range(n))

for i in range(n):
    c[a[i]] = i

for i in range(n):
    b[i] = c[b[i]]

c = [0] * n
for i in range(n):
    c[(b[i] - i + n) % n] += 1

print(max(c))