from sys import stdin, stdout

for _ in range(int(input())):
    n, k = map(int, input().split())
    k -= 1
    while k:
        i = int(max(str(n)))
        j = int(min(str(n)))
        if j == 0:
            break
        n += i * j
        k -= 1
    print(n)
