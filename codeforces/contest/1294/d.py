import atexit
import io
import sys

input = sys.stdin.readline
_OUTPUT_BUFFER = io.StringIO()
sys.stdout = _OUTPUT_BUFFER


@atexit.register
def write():
    sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())


q, x = map(int, input().split())
cnt = [0] * x
mex = 0
for _ in range(q):
    a = int(input())
    cnt[a % x] += 1
    while cnt[mex % x]:
        cnt[mex % x] -= 1
        mex += 1
    print(mex)