from sys import stdin, stdout

n = int(stdin.readline())
a = [int(i) for i in stdin.readline().split()]

a = sorted(a)
print(sum([max(0, a[i] - n + i) for i in range(n)]))
