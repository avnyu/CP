from math import gcd
k = int(input())
print(sum([gcd(a, gcd(b, c)) for a in range(1, k + 1) for b in range(1, k + 1) for c in range(1, k + 1)]))