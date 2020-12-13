n, m = map(int, input().split())

a = [int(i) for i in input().split()] + [n + 1]
a = sorted(a)

prv = 0
mn = int(1e9)
for p in a:
    if p - prv - 1 > 0: mn = min(mn, p - prv - 1)
    prv = p

prv = 0
res = 0
for p in a:
    if p - prv - 1 > 0: res += (p - prv - 2) // mn + 1
    prv = p

print(res)