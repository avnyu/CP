from sys import stdin, stdout
import math


def read(): return stdin.readline().strip()
def read_int(): return map(int, read().split())
def read_arr(): return [int(i) for i in read().split()]
def write(s): stdout.write(s)


def collapse_info(b: list, s: list, cur: int, t: int):
    s.append('collapse')

    for i in range(cur):
        s.append('_' + str(b[i]))

    if t == 0:
        s.append(': start\n')
    elif t == 1:
        s.append(': end\n')
    else:
        s.append(':')


def push_collapse(b: list, s: list, cur: int):
    b[cur] += 1
    b[cur + 1] = 0

    collapse_info(b, s, cur + 1, 0)

    return cur + 1


def pop_collapse(b: list, s: list, cur: int):
    collapse_info(b, s, cur, 1)

    return cur - 1


def add_item(b: list, s: list, cur: int, t: int, txt: str):
    if cur > 0:
        collapse_info(b, s, cur, 2)

    if t == 0:
        s.append('text: ')
    elif t == 1:
        s.append('link: ')
    elif t == 2:
        s.append('image: ')
    else:
        s.append('media: ')

    s.append(txt + '\n')


a = stdin.read().replace('\n', '')
b = [0 for _ in range(int(1e6))]
s = []
cur = 0
n = len(a)


l, r = 0, 0
while l < len(a):
    if a.find('[[[', l, n) == l:
        cur = push_collapse(b, s, cur)
        l = l + 12
    elif a.find(']]]', l, n) == l:
        cur = pop_collapse(b, s, cur)
        l = l + 3
    elif a.find('[[', l, n) == l:
        r = a.find(']]', l, n)
        t = 0

        if a[l + 2] == 'l':
            t = 1
            l += 7
        elif a[l + 2] == 'i':
            t = 2
            l += 8
        elif a[l + 2] == 'm':
            t = 3
            l += 8

        add_item(b, s, cur, t, a[l: r].strip())

        if l >= r + 2: l = len(a)
        else: l = r + 2
    else:
        r1 = a.find('[[', l, n)
        r2 = a.find(']]]', l, n)
        
        if r1 < l: r = r2
        elif r2 < l: r = r1
        else: r = min(r1, r2)

        if r < l: r = len(a)

        txt = a[l: r].strip()
        if len(txt) > 0: add_item(b, s, cur, 0, txt)

        if l >= r: l = len(a)
        else: l = r

write(''.join(s))
