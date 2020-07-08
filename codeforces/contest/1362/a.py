for _ in range(int(input())):
    a, b = map(int, input().split())
    res = 0
    
    while a < b:
        a <<= 1
        res += 1
    
    if a == b:
        print((res + 2) // 3)
        continue
    
    while a > b and a & 1 == 0:
        a >>= 1
        res += 1
    
    if a == b:
        print((res + 2) // 3)
        continue
    
    print(-1)
