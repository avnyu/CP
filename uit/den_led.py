n = int(input())

if x % 3 == 0:
    print(n // 3 * 7)
elif x % 3 == 1:
    print(n // 3 * 7 - 7 + 4)
else:
    print(n // 3 * 7 + 1)