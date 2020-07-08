from sys import stdin, stdout

n, t = map(int, stdin.readline().split())
a = [int(i) for i in stdin.readline().split()]

neg = list(filter(lambda x: x < 0, a)) + [0]
pos = list(filter(lambda x: x >= 0, a))

i, j = 0, 0
n, p = len(neg), len(pos)
res = 0
while i < n:
    if -neg[i] <= t:
        while j < p and -neg[i] + pos[j] + min(-neg[i], pos[j]) <= t:
            j += 1
        res = max(res, n - i - 1 + j)
    i += 1
print(res)