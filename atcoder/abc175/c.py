x, k, d = map(int, input().split())
t = abs(x) // d
a = []
a.append(t - 3)
a.append(t - 2)
a.append(t - 1)
a.append(t)
a.append(t + 1)
a.append(t + 2)
a.append(t + 3)
b = []

for i in a:
    b.append(-i)
for i in b:
    a.append(i)

a.append(k)
a.append(k - 1)
a.append(-k)
a.append(-k + 1)

res = abs(x)
if k % 2:
    res += d
for i in a:
    if i % 2 == k % 2 and abs(i) <= k:
        res = min(res, abs(x - i * d))
print(res)