from sys import stdin, stdout

for _ in range(int(input())):
    s = input()
    n = len(s)

    i, j = 0, 0
    cnt = [1, 0, 0, 0]
    l = int(1e6)

    while 1:
        while j < n and not all(cnt):
            cnt[int(s[j])] += 1
            j += 1
        
        while i < j and all(cnt):
            l = min(l, j - i)
            cnt[int(s[i])] -= 1
            i += 1

        if j == n: break
    
    print(l if l != int(1e6) else 0)
