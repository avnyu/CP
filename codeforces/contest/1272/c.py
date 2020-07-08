n, k = [int(i) for i in input().split()]
s = input()
k = [c for c in input().split()]
s = ''.join([i if i in k else '-' for i in s]).split('-')
print(sum([len(sub) * (len(sub) + 1) // 2 for sub in s]))