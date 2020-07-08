import matplotlib.pyplot as plt


def f(a, x):
    n = len(a)
    res = 0
    for i in range(n):
        for j in range(i, n):
            sum = 0
            for k in range(i, j + 1):
                sum += a[k] - x
            res = max(res, abs(sum))
    return res


a = [142, 23, 30, 34, 129, 234]
save = []
mn = int(1e9)

fx = [f(a, x) for x in range(-1000, 1000)]
for i in range(len(fx)):
    if fx[i] < mn:
        mn = fx[i]
        save = [i - 1000]
    elif fx[i] == mn:
        save += [i - 1000]

print(mn)
print(save)
