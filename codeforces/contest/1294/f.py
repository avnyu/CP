import atexit
import io
import sys
sys.setrecursionlimit(10**9)

input = sys.stdin.readline
_OUTPUT_BUFFER = io.StringIO()
sys.stdout = _OUTPUT_BUFFER


@atexit.register
def write():
    sys.__stdout__.write(_OUTPUT_BUFFER.getvalue())


def dfs(g, c, u=1):
    if c[u]: return [-1, -1, -1, -1]
    c[u] = True
    l = [1, 0, 0]
    for v in g[u]:
        x = dfs(v)


        

n = int(input())
g = [[] for _ in range(n + 1)]
c = [False] * (n + 1)
for _ in range(1, n):
    u, v = map(int, input().split())
    g[u].append(v)
    g[v].append(u)
res = dfs(g, c)