import subprocess as sp
import numpy as np
import os

idir = 'in'
odir = 'out'
sdir = 'sol'
MAX_N = int(1e7)
MAX_V = int(1e9)
ac = ['ac1', 'ac2', 'ac3']
wa = ['wa7', 'wa8', 'wa10', 'wa11', 'wa12', 'wa13', 'wa14', 'wa16',
      'wa21', 'wa26', 'wa29', 'wa30', 'wa32', 'wa33']


def ip(x): return os.path.join(idir, 'input' + str(x) + '.txt')
def op(x): return os.path.join(odir, 'output' + str(x) + '.txt')


def testcase_write(ind, n, s, l, a):
    global idir

    out = str(n) + ' ' + str(s) + ' ' + str(l) + '\n'
    out = out + ' '.join(map(str, a)) + '\n'

    with open(ip(ind), 'w') as file:
        file.write(out)


def testcase_same_numbers(ind, n, s, l, v, _max_n=False):
    global sdir, ac, wa, MAX_N, MAX_V

    _n = np.random.randint(low=n - n // 10, high=n) if not _max_n else n
    _s = s
    _l = l

    if v == 'random':
        v = np.random.randint(low=-MAX_V, high=MAX_V)

    a = [v for _ in range(_n)]

    testcase_write(ind, _n, _s, _l, a)


def testcase_random_no_answer(ind, n, s, l):
    global sdir, ac, wa, MAX_N, MAX_V

    _n = np.random.randint(low=n - n // 10, high=n)
    _s = s
    _l = l

    _low = np.random.randint(low=-MAX_V, high=MAX_V)
    _ran = _s + _s // 100 + 1

    if _low + _ran > MAX_V:
        _low -= _ran

    a = np.random.randint(low=_low, high=_low + _ran, size=_n)

    testcase_write(ind, _n, _s, _l, a)


def testcase_random(ind, n, s, l):
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

    testcase_write(ind, _n, _s, _l, a)


def testcase_random_lr(ind, n, s, l, _low, _hig, _max_n=False):
    global sdir, ac, wa, MAX_N, MAX_V

    _n = np.random.randint(low=n - n // 10, high=n) if not _max_n else n
    _s = s
    _l = l

    a = np.random.randint(low=_low, high=_hig, size=_n)

    testcase_write(ind, _n, _s, _l, a)


def testcase_increasing(ind, n, s, l):
    global sdir, ac, wa, MAX_N, MAX_V

    _n = np.random.randint(low=n - n // 10, high=n)
    _s = s
    _l = l

    _low = np.random.randint(low=-MAX_V, high=MAX_V)
    if _low + _n > MAX_N:
        _low -= _n

    a = [_low + i for i in range(_n)]

    testcase_write(ind, _n, _s, _l, a)


def testcase_same_n_l(ind, n, s, l, _max_n=False):
    global sdir, ac, wa, MAX_N, MAX_V

    _n = np.random.randint(low=n - n // 10, high=n) if not _max_n else n
    _s = s
    _l = l

    _v = np.random.randint(low=-MAX_V, high=MAX_V)
    _m = (_n // _s // 2) * _s - 1
    a = [_v for _ in range(_m)]
    _v = np.random.randint(low=-MAX_V, high=MAX_V)
    a.extend([_v + i for i in range(_n - _m)])

    testcase_write(ind, _n, _s, _l, a)


def testing(l, r):
    global idir, odir, sdir, ac, wa

    acr = [1 for _ in range(len(ac))]
    war = [1 for _ in range(len(wa))]

    for t in range(l, r + 1):

        ans = []

        for sol in ac:
            _args = [os.path.join(sdir, sol)]
            _in = ip(t)
            _out = op(t)
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
            try:
                p = sp.run(args=_args, stdin=open(_in),
                           stdout=sp.PIPE, stderr=sp.STDOUT, timeout=0.5)
                ans.append(p.stdout.decode().strip())
            except:
                ans.append('Timeout')

        for i in range(len(wa)):
            if ans[len(ac) + i] != ans[0]:
                war[i] = 0

    print(ac)
    print(acr)
    print(wa)
    print(war)


def testcase_copy(l1, r1, l2):
    global idir

    for i in range(r1 - l1 + 1):
        p1 = ip(l1 + i)
        p2 = ip(l2 + i)
        _args = ['cp', p1, p2]
        sp.run(args=_args)


def subtest_1():
    global idir, odir, sdir, ac, wa

    testcase_same_numbers(12, 5000, 0, 1, 'random')
    testcase_same_numbers(13, 5000, 0, 900, 'random', True)
    testcase_same_numbers(14, 5000, 948765365, 1, 'random', True)
    testcase_same_numbers(15, 5000, 486759468, 5000, 'random')
    testcase_random_lr(16, 5000, 0, 50, 0, 10)
    testcase_random_lr(17, 5000, 387, 50, 0, 10, True)
    testcase_random_no_answer(18, 5000, 94865326, 20)
    testcase_random_no_answer(19, 5000, 94768545, 100)
    testcase_random_no_answer(20, 5000, 94685326, 400)
    testcase_random(21, 5000, 94865326, 20)
    testcase_random(22, 5000, 98623154, 100)
    testcase_random(23, 5000, 91877625, 400)
    testcase_increasing(24, 5000, 1100, 1000)
    testcase_increasing(25, 5000, 1010, 1000)
    testcase_increasing(26, 5000, 4000, 3000)
    testcase_same_n_l(27, 5000, 50, 50)
    testcase_same_n_l(28, 5000, 200, 200)
    testcase_same_n_l(29, 5000, 1000, 1000)
    testcase_same_n_l(30, 5000, 2501, 2501, True)


def subtest_2():
    global idir, odir, sdir, ac, wa

    testcase_copy(1, 11, 31)

    testcase_same_numbers(42, 100000, 0, 1, 'random')
    testcase_same_numbers(43, 100000, 0, 900, 'random', True)
    testcase_same_numbers(44, 100000, 948765365, 1, 'random', True)
    testcase_same_numbers(45, 100000, 486759468, 100000, 'random')
    testcase_random_lr(46, 100000, 0, 50, 0, 10)
    testcase_random_lr(47, 100000, 0, 50, 0, 10, True)
    testcase_random_lr(48, 100000, MAX_V, 50, -MAX_V, MAX_V)
    testcase_random_lr(49, 100000, MAX_V, 50, -MAX_V, MAX_V, True)
    testcase_random_no_answer(50, 100000, 99865326, 20)
    testcase_random_no_answer(51, 100000, 94768545, 100)
    testcase_random_no_answer(52, 100000, 95685326, 400)
    testcase_random_no_answer(53, 100000, 96485326, 5000)
    testcase_random_no_answer(54, 100000, 98465235, 20000)
    testcase_random(55, 100000, 94865326, 20)
    testcase_random(56, 100000, 98623154, 100)
    testcase_random(57, 100000, 91877625, 400)
    testcase_random(58, 100000, 93986523, 5000)
    testcase_random(59, 100000, 97648536, 20000)
    testcase_increasing(60, 100000, 200, 100)
    testcase_increasing(61, 100000, 801, 800)
    testcase_increasing(62, 100000, 5005, 5004)
    testcase_increasing(63, 100000, 22000, 20002)
    testcase_increasing(64, 100000, 70007, 50005)
    testcase_same_n_l(65, 100000, 50, 50)
    testcase_same_n_l(66, 100000, 200, 200)
    testcase_same_n_l(67, 100000, 800, 800)
    testcase_same_n_l(68, 100000, 2501, 2501, True)
    testcase_same_n_l(69, 100000, 10001, 10001)
    testcase_same_n_l(70, 100000, 50005, 50005, True)


def subtest_3():
    global idir, odir, sdir, ac, wa

    testcase_copy(1, 11, 71)

    testcase_same_numbers(82, 4000000, 0, 1, 'random')
    testcase_same_numbers(83, 4000000, 0, 900, 'random', True)
    testcase_same_numbers(84, 4000000, 948765365, 1, 'random', True)
    testcase_same_numbers(85, 4000000, 486759468, 4000000, 'random')
    testcase_random_lr(86, 4000000, 0, 50, 0, 1000)
    testcase_random_lr(87, 4000000, 5675321, 50, 0, 1000, True)
    testcase_random_no_answer(88, 4000000, 94865326, 400)
    testcase_random_no_answer(89, 4000000, 94768545, 40000)
    testcase_random_no_answer(90, 4000000, 94685326, 400000)
    testcase_random(91, 4000000, 94865326, 400)
    testcase_random(92, 4000000, 98623154, 40000)
    testcase_random(93, 4000000, 91877625, 400000)
    testcase_increasing(94, 4000000, 50005, 50004)
    testcase_increasing(95, 4000000, 400002, 400001)
    testcase_increasing(96, 4000000, 900000, 800000)
    testcase_same_n_l(97, 4000000, 500, 500)
    testcase_same_n_l(98, 4000000, 2000, 2000, True)
    testcase_same_n_l(99, 4000000, 40000, 40000)
    testcase_same_n_l(100, 4000000, 200008, 200008, True)


def create_test():
    subtest_1()
    print('Done subtest 1')
    subtest_2()
    print('Done subtest 2')
    subtest_3()
    print('Done subtest 3')


def do_testing():
    testing(1, 30)
    print('Done testing 1')
    testing(31, 70)
    print('Done testing 2')
    testing(71, 100)
    print('Done testing 3')


def write_output():
    global idir, odir, sdir, ac

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
