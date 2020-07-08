from sys import stdin, stdout
import heapq

for tc in range(int(stdin.readline())):
    C, D = map(int, stdin.readline().split())
    X = [0, 0] + [int(i) for i in stdin.readline().split()]
    g = [[] for _ in range(C + 1)]

    edges = []
    for i in range(D):
        u, v = map(int, stdin.readline().split())
        edges.append((u, v, 0))
        g[u].append((v, i))
        g[v].append((u, i))

    visited = [0] * (C + 1)
    visited[0] = visited[1] = 1

    dis = [0] * (C + 1)

    cur, prv, time = [], [], []

    heapq.heappush(cur, (0, 1))

    max_dis = 0
    cnt = 0

    while 1:
        if len(cur) == 0: break
        
        du, u = heapq.heappop(cur)
        max_dis = max(max_dis, du)
        cnt += 1
        if cnt == C: break

        for v, i in g[u]:
            if visited[v]: continue
            visited[v] = 1
            
            if X[v] > 0: heapq.heappush(time, (X[v], u, v, i))
            elif X[v] < 0: heapq.heappush(prv, (-X[v], u, v, i))
        
        while len(prv) and prv[0][0] == cnt:
            _, u, v, i = heapq.heappop(prv)
            edges[i] = (edges[0], edges[1], max_dis + 1 - dis[u])
            dis[v] = max_dis + 1
            heapq.heappush(cur, (max_dis + 1, v))
        
        # if len(cur) == 0 and len(time):
        #     dv, u, v, i = heapq.heappop(time)
        #     edges[i] = (edges[0], edges[1], dv - dis[u])
        #     dis[v] = dv
        #     heapq.heappush(cur, (dv, v))
    
    print('Case #{}: {}'.format(tc + 1, ' '.join([str(i[2] if i[2] else int(1e6)) for i in edges])))