import math

a, b = map(int, input().split())

x = 1
add = 1 << 60

while add > 0:
    if 1.0 * x + add <= 1.0 * b * math.log(x + add, a): x += add;
    add >>= 1;

for i in range(-2, 3):
    if a ** (x + i) == (x + i) ** b and x + i >= 1 and x + i <= int(1e18):
        print(x + i)
        exit()
        
print(0)
