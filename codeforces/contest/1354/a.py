from sys import stdin, stdout

for _ in range(int(input())):
    a, b, c, d = map(int, input().split())
    if b >= a:
        print(b)
    else:
        a -= b
        if d >= c:
            print(-1)
        else:
            print(b + ((a - 1) // (c - d) + 1) * c)