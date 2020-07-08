t = int(input())
for tc in range(t):
    s = input()
    n = len(s)

    i = 1
    ans = ['('] * int(s[0]) + [s[0]]
    while i < n:
        while i < n and s[i] >= s[i - 1]:
            ans += ['('] * (int(s[i]) - int(s[i - 1])) + [s[i]]
            i += 1
        while i < n and s[i] <= s[i - 1]:
            ans += [')'] * (int(s[i - 1]) - int(s[i])) + [s[i]]
            i += 1
    ans += [')'] * int(s[n - 1])

    print('Case #{}: {}'.format(tc + 1, ''.join(ans)))
