from sys import stdin, stdout

for _ in range(int(stdin.readline())):
    n = int(stdin.readline())
    a = [int(i) for i in stdin.readline().split()]
    a.sort()
    cnt = 0
    k = 0
    for i in range(len(a)):
        if k == 0: k = a[i]
        elif i: k += a[i] - a[i - 1]
        k -= 1
        if k == 0: cnt += 1
    stdout.write(str(cnt) + '\n')