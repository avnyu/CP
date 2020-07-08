from functools import cmp_to_key

cnt = 0
a = [(2, 0), (4, 1), (3, 2), (0, 3), (1, 4), (5, 5)]
x = [0, 1, 2, 3, 4, 5]


def comp(i, j):
    global cnt
    if i[0] > j[1]: return 1
    elif i[0] == j[1]: return 0
    else: return -1


a = sorted(a, key=cmp_to_key(comp))

print(a)
print(cnt, x)