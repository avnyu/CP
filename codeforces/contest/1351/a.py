for _ in range(int(input())):
    n = input()
    rs = []

    for i in reversed(range(len(n))):
        if n[i] != '0':
            rs.append(int(n[i]) * 10**(len(n) - i - 1))

    print(len(rs))
    print(' '.join(str(i) for i in rs))
