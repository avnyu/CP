from sys import stdin, stdout

fin = lambda: stdin.readline()

fout = lambda *args: stdout.write(' '.join(str(i) for i in args) + '\n')

for _ in range(int(input())):
    n = int(fin())
    l = [[int(x) for x in fin().split()] for _ in range(n)]
    x = [0, 0]
    l.sort(key=sum)
    res = ''
    for i in l:
        if i[0] < x[0] or i[1] < x[1]:
            res += 'x'
        res += ''.join('R' for _ in range(i[0] - x[0]))
        res += ''.join('U' for _ in range(i[1] - x[1]))
        x = i

    fout('NO' if 'x' in res else 'YES\n' + res)
