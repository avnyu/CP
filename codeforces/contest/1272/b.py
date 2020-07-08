from sys import stdin, stdout

for tc in range(int(stdin.readline())):
    s = stdin.readline()
    U, D, L, R = s.count('U'), s.count('D'), s.count('L'), s.count('R')
    U = D = min(U, D)
    L = R = min(L, R)
    if U == 0:
        L = R = min(L, 1)
    if L == 0:
        U = D = min(U, 1)
    stdout.write(str(U + D + L + R) + '\n')
    stdout.write(''.join(['L'] * L + ['U'] * U + ['R'] * R + ['D'] * D) + '\n')
