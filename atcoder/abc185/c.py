n = int(input())

def fact(n):
    if n == 0: return 1
    return n * fact(n - 1)

print(fact(n - 1) // fact(11) // fact(n - 12))