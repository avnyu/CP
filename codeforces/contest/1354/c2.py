from sys import stdin, stdout
from math import pi, sin, cos

def cal(n, angle, r):
    ang = 180. / n
    res = 0
    for i in range(n):
        res = max(res, abs(sin(angle * pi / 180.)) * r)
        res = max(res, abs(cos(angle * pi / 180.)) * r)

        angle += ang
    return res

for _ in range(int(input())):
    n = int(input())
    angle = 180. / n
    rd = .5 / sin(angle / 2. * pi / 180.)

    l, r = 0, angle
    cnt = 100
    while cnt:
        cnt -= 1

        m1, m2 = (l + l + r) / 3., (l + r + r) / 3.
        t1, t2 = cal(n, m1, rd), cal(n, m2, rd)
        if t1 < t2:
            r = m2
        else:
            l = m1

    ans = cal(n, l, rd)

    print('{:.9f}'.format(ans * 2.))
