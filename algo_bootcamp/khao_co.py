from sys import stdin, stdout

n, t = map(int, stdin.readline().split())
h = list(map(int, stdin.readline().split()))

l, r = int(-1e18), int(1e9)
ans = 1e9

while l <= r:
	m = (l + r) >> 1

	il, ir = 0, 0
	s = 0
	chk = False

	for i in range(n):
		c = m + ir - i
		
		while ir < n and h[ir] > c:
			s += h[ir] - c
			ir += 1
			c += 1
		c = m + i - il
		
		while il <= i and h[il] < c:
			s -= c - h[il]
			il += 1
			c -= 1

		if s <= t:
			chk = True
			break

	if chk:
		ans = m
		r = m - 1
	else:
		l = m + 1

stdout.write(str(ans) + '\n')
