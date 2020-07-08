from sys import stdin, stdout
from math import tan, pi

for _ in range(int(input())):
    n = int(input())
    angle = 180. / n / 2.
    r = .5 / tan(angle * pi / 180.)

    print('{:.9f}'.format(r * 2.))
