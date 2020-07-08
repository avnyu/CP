for _ in range(int(input())):
    n = int(input())

    if n < 4:
        print('-1')
        continue

    k = 5
    t = '2 4 1 3'
    x = []
    y = []

    while k <= n:
        if k & 1:
            x += [k]
            k += 1
        else:
            y += [k]
            k += 1

    print(''.join([str(i) + ' ' for i in reversed(y)]) + t +
          ''.join([' ' + str(i) for i in (x)]))
