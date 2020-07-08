from functools import reduce

for _ in range(int(input())):
    n = int(input())
    s = [int(i) for i in input().split()]
    s.sort()

    for j in range(1, 1025):
        if j == 1024:
            print(-1)
            break

        t = [j ^ x for x in s]
        t.sort()

        if all([t[i] == s[i] for i in range(n)]):
            print(j)
            break