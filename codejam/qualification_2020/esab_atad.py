T, n = map(int, input().split())


def get(t):
    print(t)
    t = input()
    if t == 'N':
        exit(0)
    return int(t)


for t in range(T):
    N = 101
    a, p, x = [0] * N, [0] * N, [0] * N

    step = 0
    diff, same = [], []
    for i in range(n // 2):
        if step % 10 == 0:
            diff_i, same_i = -1, -1

        u, v = i + 1, n - i

        t1 = get(u)
        t2 = get(v)
        step += 2

        if t1 != t2:
            p[v] = u
            x[v] = 1

            if diff_i == -1:
                diff_i = u

                a[diff_i] = t1
                diff.append(diff_i)
            else:
                p[u] = diff_i
                x[u] = 0 if a[diff_i] == t1 else 1
        else:
            p[v] = u
            x[v] = 0

            if same_i == -1:
                same_i = u

                a[same_i] = t1
                same.append(same_i)
            else:
                p[u] = same_i
                x[u] = 0 if a[same_i] == t1 else 1

    diff_l, same_l = len(diff), len(same)

    if diff_l:
        for i in range(1, diff_l):
            a[diff[0]] = get(diff[0])
            a_di = get(diff[i])

            p[diff[i]] = diff[0]
            x[diff[i]] = 0 if a[diff[0]] == a_di else 1

    if same_l:
        for i in range(1, same_l):
            a[same[0]] = get(same[0])
            a_si = get(same[i])

            p[same[i]] = same[0]
            x[same[i]] = 0 if a[same[0]] == a_si else 1

    if diff_l:
        a[diff[0]] = get(diff[0])
    if same_l:
        a[same[0]] = get(same[0])

    for i in range(1, n + 1):
        if p[i]:
            a[i] = a[p[i]] ^ x[i]

    print(''.join([str(i) for i in a[1:n + 1]]))
    t = input()
    if t == 'N':
        exit(0)
