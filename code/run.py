import subprocess as sp
import numpy as np
import sys
import os

from numpy.random import random

idir = 'input'
odir = 'output'
sdir = 'sol'
MAX_N = int(1e7)
MAX_V = int(1e9)
ac = ['ac1', 'ac2', 'ac3']
wa = ['wa7', 'wa8', 'wa10', 'wa11', 'wa12', 'wa13', 'wa14', 'wa16',
      'wa21', 'wa21', 'wa26', 'wa29', 'wa30', 'wa32', 'wa33', 'wa34']


def testcase_write(path, n, s, l, a):
    out = str(n) + ' ' + str(s) + ' ' + str(l) + '\n'
    out = out + ' '.join(map(str, a)) + '\n'

    with open(path, 'w') as file:
        file.write(out)


def testcase_same_numbers(path, n, s, l, v):
    global sdir, ac, wa, MAX_N, MAX_V

    _n = np.random.randint(low=n - n // 10, high=n)
    _s = s
    _l = l
    a = [v for _ in range(_n)]

    testcase_write(path, _n, _s, _l, a)


def testcase_no_answer(path, n, s, l):
    global sdir, ac, wa, MAX_N, MAX_V

    _n = np.random.randint(low=n - n // 10, high=n)
    _s = s
    _l = l

    _low = np.random.randint(low=-MAX_V, high=MAX_V)
    _ran = _s + _s // 1000 + 1

    ok = False
    while not ok:
        _low = np.random.randint(low=-MAX_V, high=MAX_V)
        _ran = _ran + _ran // 1000 + 1

        if _low + _ran > MAX_V:
            _low -= _ran

        a = np.random.randint(low=_low, high=_low + _ran, size=_n)

        testcase_write(path, _n, _s, _l, a)

        cnt = 0
        for sol in ac:
            _args = [os.path.join(sdir, sol)]
            p = sp.run(args=_args, stdin=open(path),
                       stdout=sp.PIPE, stderr=sp.STDOUT)

            if p.stdout.decode().strip() == '-1':
                cnt += 1

        ok = cnt == len(ac)


def testcase_random(path, n, s, l):
    global sdir, ac, wa, MAX_N, MAX_V

    _n = np.random.randint(low=n - n // 10, high=n)
    _s = s
    _l = l

    _low = np.random.randint(low=-MAX_V, high=MAX_V)
    _ran = _s

    if _low + _ran > MAX_V:
        _low -= _ran

    a = []
    for i in range(_n // _l):
        _low = np.random.randint(
            low=_low + _s // 100 - 1, high=_low + _s // 100 + 1)

        if _low < -MAX_N:
            _low += _ran
        if _low + _ran > MAX_N:
            _low -= _ran

        _m = _l + (1 if i < _n % _l else 0)
        _a = np.random.randint(low=_low, high=_low + _ran, size=_m)
        a.extend(_a)

    testcase_write(path, _n, _s, _l, a)

    # ans = []

    # for sol in ac:
    #     _args = [os.path.join(sdir, sol)]
    #     p = sp.run(args=_args, stdin=open(path),
    #                stdout=sp.PIPE, stderr=sp.STDOUT)
    #     ans.append(p.stdout.decode().strip())

    # print(ans)


path = os.path.join(idir, '12.txt')
testcase_random(path, 1000, 1000000, 10)
