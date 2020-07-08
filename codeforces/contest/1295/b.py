import atexit
import io
import sys

input = sys.stdin.readline
_OUTPUT_BUFFER = io.StringIO()
sys.stdout = _OUTPUT_BUFFER


@atexit.register
def write():
    sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())


for _ in range(int(input())):
    n, x = map(int, input().split())
    t = input()
    prf = [0] * (n + 1)
    for i in range(n):
        prf[i + 1] = prf[i] + (1 if t[i] == '0' else -1)

    if prf[n] == 0:
        if x in prf:
            print(-1)
        else:
            print(0)
    else:
        res = 0
        for i in prf[:-1]:
            if abs(x - i) % abs(prf[n]) == 0 and (x - i) // prf[n] >= 0:
                res += 1
        print(res)
