from sys import stdin, stdout

a = stdin.read()
a = ''.join([i.strip() for i in a.split('\n')])

print(a)

obs = []