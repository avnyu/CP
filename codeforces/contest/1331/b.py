a = [i for i in range(10000)]

for i in range(2, 10000):
    if i == a[i]:
        j = i + i
        while j < 10000:
            a[j] = i
            j += i

p = []
for i in range(2, 10000):
    if i == a[i]:
        p.append(i)

print(35 * 2 // 3)
print(p[35 * 2 // 3])