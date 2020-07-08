s = input()
n = len(s)

l, r = 0, n - 1
c0 = sum([i == '0' for i in s])
c1 = sum([i == '1' for i in s])

if c0 < 2 and c1 < 2 :
	print(-1)
	exit()

while s[l] != s[n - 1]:
	l += 1

while s[r] != s[0]:
	r -= 1

if n - l >= r + 1:
	print(l + 1, n - 1, l + 2, n)
else:
	print(1, r, 2, r + 1)