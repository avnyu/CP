for _ in range(int(input())):
    n = int(input())
    a = [int(i) for i in input().split()]
    b = [int(i) for i in input().split()]

    if a == sorted(a):
        print('Yes')
    elif any([b[i] != b[i - 1] for i in range(1, n)]):
        print('Yes')
    else:
        print('No')