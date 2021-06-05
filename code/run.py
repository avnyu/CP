import subprocess as sp
import numpy as np
import os

idir = 'input'
odir = 'output'
sdir = 'sol'
MAX_N = int(1e7)
MAX_V = int(1e9)
ac = ['ac1', 'ac2', 'ac3']
wa = ['wa7', 'wa8', 'wa10', 'wa11', 'wa12', 'wa13', 'wa14', 'wa16',
      'wa21', 'wa26', 'wa29', 'wa30', 'wa32', 'wa33', 'wa34']


def testcase_write(path, n, s, l, a):
    out = str(n) + ' ' + str(s) + ' ' + str(l) + '\n'
    out = out + ' '.join(map(str, a)) + '\n'

    with open(path, 'w') as file:
        file.write(out)


def testcase_same_numbers(path, n, s, l, v, _max_n=False):
    global sdir, ac, wa, MAX_N, MAX_V

    _n = np.random.randint(low=n - n // 10, high=n) if not _max_n else n
    _s = s
    _l = l

    if v == 'random':
        v = np.random.randint(low=-MAX_V, high=MAX_V)

    a = [v for _ in range(_n)]

    testcase_write(path, _n, _s, _l, a)


def testcase_random_no_answer(path, n, s, l):
    global sdir, ac, wa, MAX_N, MAX_V

    _n = np.random.randint(low=n - n // 10, high=n)
    _s = s
    _l = l

    _low = np.random.randint(low=-MAX_V, high=MAX_V)
    _ran = _s + _s // 100 + 1

    if _low + _ran > MAX_V:
        _low -= _ran

    a = np.random.randint(low=_low, high=_low + _ran, size=_n)

    testcase_write(path, _n, _s, _l, a)


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
            low=_low + _s // 10 - 1, high=_low + _s // 10 + 1)

        if _low < -MAX_N:
            _low += _ran
        if _low + _ran > MAX_N:
            _low -= _ran

        _m = _l + (1 if i < _n % _l else 0)
        _a = np.random.randint(low=_low, high=_low + _ran, size=_m)
        a.extend(_a)

    testcase_write(path, _n, _s, _l, a)


def testcase_random_lr(path, n, s, l, _low, _hig, _max_n=False):
    global sdir, ac, wa, MAX_N, MAX_V

    _n = np.random.randint(low=n - n // 10, high=n) if not _max_n else n
    _s = s
    _l = l

    a = np.random.randint(low=_low, high=_hig, size=_n)

    testcase_write(path, _n, _s, _l, a)


def testcase_increasing(path, n, s, l):
    global sdir, ac, wa, MAX_N, MAX_V

    _n = np.random.randint(low=n - n // 10, high=n)
    _s = s
    _l = l

    _low = np.random.randint(low=-MAX_V, high=MAX_V)
    if _low + _n > MAX_N:
        _low -= _n

    a = [_low + i for i in range(_n)]

    testcase_write(path, _n, _s, _l, a)


def testcase_same_n_l(path, n, s, l, _max_n=False):
    global sdir, ac, wa, MAX_N, MAX_V

    _n = np.random.randint(low=n - n // 10, high=n) if not _max_n else n
    _s = s
    _l = l

    _v = np.random.randint(low=-MAX_V, high=MAX_V)
    _m = (_n // _s // 2) * _s - 1
    a = [_v for _ in range(_m)]
    _v = np.random.randint(low=-MAX_V, high=MAX_V)
    a.extend([_v + i for i in range(_n - _m)])

    testcase_write(path, _n, _s, _l, a)


def testing(l, r):
    global idir, odir, sdir, ac, wa
    def ip(x): return os.path.join(idir, str(x) + '.txt')
    def op(x): return os.path.join(odir, str(x) + '.txt')

    acr = [1 for _ in range(len(ac))]
    war = [1 for _ in range(len(wa))]

    for t in range(l, r + 1):

        ans = []

        for sol in ac:
            _args = [os.path.join(sdir, sol)]
            _in = os.path.join(idir, str(t) + '.txt')
            _out = os.path.join(odir, str(t) + '.txt')
            p = sp.run(args=_args, stdin=open(_in),
                       stdout=sp.PIPE, stderr=sp.STDOUT)
            ans.append(p.stdout.decode().strip())

        for i in range(len(ac)):
            if ans[i] != ans[0]:
                acr[i] = 0

        for sol in wa:
            _args = [os.path.join(sdir, sol)]
            _in = ip(t)
            _out = op(t)
            p = sp.run(args=_args, stdin=open(_in),
                       stdout=sp.PIPE, stderr=sp.STDOUT, timeout=2)
            ans.append(p.stdout.decode().strip())

        for i in range(len(wa)):
            if ans[len(ac) + i] != ans[0]:
                war[i] = 0

    print(ac)
    print(acr)
    print(wa)
    print(war)


def subtest_1():
    global idir, odir, sdir, ac, wa
    def ip(x): return os.path.join(idir, str(x) + '.txt')

    testcase_same_numbers(ip(12), 5000, 0, 1, 'random')
    testcase_same_numbers(ip(13), 5000, 0, 900, 'random', True)
    testcase_same_numbers(ip(14), 5000, 948765365, 1, 'random', True)
    testcase_same_numbers(ip(15), 5000, 486759468, 5000, 'random')
    testcase_random_lr(ip(16), 5000, 0, 50, 0, 10)
    testcase_random_lr(ip(17), 5000, 387, 50, 0, 10, True)
    testcase_random_no_answer(ip(18), 5000, 94865326, 20)
    testcase_random_no_answer(ip(19), 5000, 94768545, 100)
    testcase_random_no_answer(ip(20), 5000, 94685326, 400)
    testcase_random(ip(21), 5000, 94865326, 20)
    testcase_random(ip(22), 5000, 98623154, 100)
    testcase_random(ip(23), 5000, 91877625, 400)
    testcase_increasing(ip(24), 5000, 1100, 1000)
    testcase_increasing(ip(25), 5000, 1010, 1000)
    testcase_increasing(ip(26), 5000, 4000, 3000)
    testcase_same_n_l(ip(27), 5000, 50, 50)
    testcase_same_n_l(ip(28), 5000, 200, 200)
    testcase_same_n_l(ip(29), 5000, 1000, 1000)
    testcase_same_n_l(ip(30), 5000, 2501, 2501, True)


def testcase_copy(l1, r1, l2):
    global idir

    for i in range(r1 - l1 + 1):
        p1 = os.path.join(idir, str(l1 + i) + '.txt')
        p2 = os.path.join(idir, str(l2 + i) + '.txt')
        _args = ['cp', p1, p2]
        sp.run(args=_args)


def subtest_2():
    global idir, odir, sdir, ac, wa
    def ip(x): return os.path.join(idir, str(x) + '.txt')

    testcase_copy(1, 11, 31)

    testcase_same_numbers(ip(42), 100000, 0, 1, 'random')
    testcase_same_numbers(ip(43), 100000, 0, 900, 'random', True)
    testcase_same_numbers(ip(44), 100000, 948765365, 1, 'random', True)
    testcase_same_numbers(ip(45), 100000, 486759468, 100000, 'random')
    testcase_random_lr(ip(46), 100000, 0, 50, 0, 10)
    testcase_random_lr(ip(47), 100000, 0, 50, 0, 10, True)
    testcase_random_lr(ip(48), 100000, MAX_V, 50, -MAX_V, MAX_V)
    testcase_random_lr(ip(49), 100000, MAX_V, 50, -MAX_V, MAX_V, True)
    testcase_random_no_answer(ip(50), 100000, 99865326, 20)
    testcase_random_no_answer(ip(51), 100000, 94768545, 100)
    testcase_random_no_answer(ip(52), 100000, 95685326, 400)
    testcase_random_no_answer(ip(53), 100000, 96485326, 5000)
    testcase_random_no_answer(ip(54), 100000, 98465235, 20000)
    testcase_random(ip(55), 100000, 94865326, 20)
    testcase_random(ip(56), 100000, 98623154, 100)
    testcase_random(ip(57), 100000, 91877625, 400)
    testcase_random(ip(58), 100000, 93986523, 5000)
    testcase_random(ip(59), 100000, 97648536, 20000)
    testcase_increasing(ip(60), 100000, 200, 100)
    testcase_increasing(ip(61), 100000, 801, 800)
    testcase_increasing(ip(62), 100000, 5005, 5004)
    testcase_increasing(ip(63), 100000, 22000, 20002)
    testcase_increasing(ip(64), 100000, 70007, 50005)
    testcase_same_n_l(ip(65), 100000, 50, 50)
    testcase_same_n_l(ip(66), 100000, 200, 200)
    testcase_same_n_l(ip(67), 100000, 800, 800)
    testcase_same_n_l(ip(68), 100000, 2501, 2501, True)
    testcase_same_n_l(ip(69), 100000, 10001, 10001)
    testcase_same_n_l(ip(70), 100000, 50005, 50005, True)


def subtest_3():
    global idir, odir, sdir, ac, wa
    def ip(x): return os.path.join(idir, str(x) + '.txt')

    testcase_copy(1, 11, 71)

    testcase_same_numbers(ip(82), 10000000, 0, 1, 'random')
    testcase_same_numbers(ip(83), 10000000, 0, 900, 'random', True)
    testcase_same_numbers(ip(84), 10000000, 948765365, 1, 'random', True)
    testcase_same_numbers(ip(85), 10000000, 486759468, 10000000, 'random')
    testcase_random_lr(ip(86), 10000000, 0, 50, 0, 1000)
    testcase_random_lr(ip(87), 10000000, 5675321, 50, 0, 1000, True)
    testcase_random_no_answer(ip(88), 10000000, 94865326, 400)
    testcase_random_no_answer(ip(89), 10000000, 94768545, 20000)
    testcase_random_no_answer(ip(90), 10000000, 94685326, 800000)
    testcase_random(ip(91), 10000000, 94865326, 400)
    testcase_random(ip(92), 10000000, 98623154, 20000)
    testcase_random(ip(93), 10000000, 91877625, 800000)
    testcase_increasing(ip(94), 10000000, 50005, 50004)
    testcase_increasing(ip(95), 10000000, 2200000, 2000002)
    testcase_increasing(ip(96), 10000000, 4000000, 3000000)
    testcase_same_n_l(ip(97), 10000000, 500, 500)
    testcase_same_n_l(ip(98), 10000000, 2000, 2000, True)
    testcase_same_n_l(ip(99), 10000000, 50000, 50000)
    testcase_same_n_l(ip(100), 10000000, 800008, 800008, True)


def create_test():
    subtest_1()
    subtest_2()
    subtest_3()


def do_testing():
    testing(1, 30)
    testing(31, 70)
    testing(71, 100)


def write_output():
    global idir, odir, sdir, ac
    def ip(x): return os.path.join(idir, str(x) + '.txt')
    def op(x): return os.path.join(odir, str(x) + '.txt')

    for i in range(1, 101):
        _args = [os.path.join(sdir, ac[0])]
        _in = ip(i)
        _out = op(i)
        p = sp.run(args=_args, stdin=open(_in), stdout=sp.PIPE,
                   stderr=sp.STDOUT, timeout=2)

        with open(_out, 'w') as file:
            file.write(p.stdout.decode())

create_test()
do_testing()
write_output()
