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
    n = int(input())
    lef, rig, res = 0, 100000, 0
    while lef <= rig:
        mid = (lef + rig) >> 1
        if n // 2 >= mid:
            res = mid
            lef = mid + 1
        else:
            rig = mid - 1
    ans = ''
    for i in range(res):
        if n - 6 >= (res - i - 1) * 2:
            ans += '9'
            n -= 6
        elif n - 3 >= (res - i - 1) * 2:
            ans += '7'
            n -= 3
        else:
            ans += '1'
            n -= 2
    print(ans)