for T in range(int(input())):
    n, d = map(int, input().split())
    a = [int(i) for i in input().split()]
    a = sorted(a)
    if all([i <= d for i in a]):
        print("Yes")
    elif a[0] + a[1] <= d:
        print("Yes")
    else:
        print("No")