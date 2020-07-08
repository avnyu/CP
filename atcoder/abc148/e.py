n = int(input())

res = 0
for i in range(1, 18):
    for j in range(1, 26):
        x = 10**i * 5**j
        res += n // x

print(res)