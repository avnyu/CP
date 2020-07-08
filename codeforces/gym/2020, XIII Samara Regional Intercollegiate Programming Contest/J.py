def check(a, b):
    c = [a[0] + a[1], a[0] + a[2], a[1] + a[2]]
    d = [b[0] + b[1], b[0] + b[2], b[1] + b[2]]

    # k = 1
    x, y = 0, 0
    for i in a:
        for j in b:
            if i > j: x += 1
            elif i < j: y += 1
    if x <= y: return False

    # k = 2
    x, y = 0, 0
    for i in c:
        for j in d:
            if i > j: x += 1
            elif i < j: y += 1
    if x >= y: return False

    # k = 3
    return sum(a) > sum(b)

def test(a, b, i = 0):
    if i == 6:
        return check(a, b)
    elif i < 3:
        t = a[i - 1] if i else 1
        while t < 6:
            a[i] = t
            if test(a, b, i + 1): return True
            t += 1
    else:
        t = b[i - 4] if i > 3 else 1
        while t < 6:
            b[i - 3] = t
            if test(a, b, i + 1): return True
            t += 1
    return False

a = [0, 0, 0]
b = [0, 0, 0]
test(a, b)
print(len(a))
print(' '.join([str(i) for i in a]))
print(len(b))
print(' '.join([str(i) for i in b]))