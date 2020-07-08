n = int(input())
a = sorted([int(i) for i in input().split()])

i, j = n // 2 - 1, n // 2

if n & 1:
	print(a[j], end = ' ')
	j += 1

while j != n:
	print(a[i], a[j], end = ' ')
	i -= 1
	j += 1