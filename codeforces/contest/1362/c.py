for _ in range(int(input())):
    n = int(input())
    res = 0
    for j in range(64):
        res += n // (1 << j)
    print(res)    