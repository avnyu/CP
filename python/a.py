import numpy as np
import time
import os

fitness_count = 0
MSSV = 17520584
start = time.time()


def random_population(P, seed):
    n, l = P.shape
    np.random.seed(seed)
    for i in range(n):
        for j in range(l):
            P[i][j] = np.random.randint(2)


def One_point_hybrid(P, O):
    n, l = P.shape
    per = np.random.permutation(n)
    for i in range(n // 2):
        p = np.random.randint(l)
        for j in range(l):
            if j < p:
                O[i + i][j] = P[per[i + i + 1]][j]
                O[i + i + 1][j] = P[per[i + i]][j]
            else:
                O[i + i][j] = P[per[i + i]][j]
                O[i + i + 1][j] = P[per[i + i + 1]][j]


def Universal_hybrid(P, O):
    n, l = P.shape
    for i in range(n):
        for j in range(l):
            O[i][j] = P[i][j] if np.random.randint(2) == 0 else 1 - P[i][j]


def create_pool(P, O, PL):
    n, l = P.shape
    for i in range(n):
        for j in range(l):
            PL[i][j] = P[i][j]
            PL[i + n][j] = O[i][j]


def OneMax(Pi):
    global fitness_count
    fitness_count += 1

    res = 0
    for i in Pi:
        res += i
    return res


def Trap(Pi, k=5):
    global fitness_count
    fitness_count += 1

    l = Pi.shape[0]
    res = 0
    for i in range(l // k):
        t = 0
        for j in range(k):
            t += Pi[i][j]
        res += t if t == k else k - 1 - t
    return res


def tournament_selection(PL, P, fitness_func, s=4):
    PL_n, l = PL.shape
    n = PL_n // 2

    per = np.random.permutation(n * s)

    for i in range(n):
        bpos, bval = -1, -1
        for j in range(s):
            pos = per[i * s + j] % PL_n
            val = fitness_func(PL[pos])
            if val > bval:
                bpos = pos
                bval = val
        for j in range(l):
            P[i][j] = PL[bpos][j]


def stop_requirement(P):
    n, l = P.shape
    for j in range(l):
        for i in range(1, n):
            if P[i][j] != P[i - 1][j]:
                return False
    return True


def criteria(P):
    n, l = P.shape
    cnt1s = 0
    for i in range(n):
        for j in range(l):
            cnt1s += P[i][j]
    return cnt1s == n * l


def converge(P, O, PL, seed, fitness_func, offspring_func):
    random_population(P, seed)
    count = 0

    while not stop_requirement(P):
        count += 1
        offspring_func(P, O)
        create_pool(P, O, PL)
        tournament_selection(PL, P, fitness_func)

    print('Converge', count)


def test_converge(n, l, seeds, fitness_func, offspring_func):
    population = np.zeros((n, l), np.int8)
    offspring = np.zeros((n, l), np.int8)
    pool = np.zeros((n + n, l), np.int8)

    seed_num = seeds.shape[0]
    success = 0
    for i in range(seed_num):
        converge(population, offspring, pool, seeds[i], fitness_func,
                 offspring_func)
        success += 1 if criteria(population) else 0
    return success == seed_num


def phase_1(l, seeds, fitness_func, offspring_func):
    global start

    n_upper = 4
    success = False
    while not success:
        print("Phase 1 n_upper =", n_upper, 'Time', time.time() - start)
        n_upper += n_upper
        success = test_converge(n_upper, l, seeds, fitness_func,
                                offspring_func)
    return n_upper


def phase_2(l, n_upper, seeds, fitness_func, offspring_func):
    global fitness_count, start

    n_lower = n_upper // 2
    avg_num_of_eval = 0

    while n_upper > n_lower:
        print("Phase 2 n_upper n_lower", n_upper, n_lower, 'Time',
              time.time() - start)
        n = (n_upper + n_lower) // 2

        fitness_count = 0
        success = test_converge(n, l, seeds, fitness_func, offspring_func)

        if success:
            n_upper = n
            avg_num_of_eval = fitness_count // seeds.shape[0]
        else:
            n_lower = n

        if (n_upper - n_lower) <= 1:
            break

    return n_upper, avg_num_of_eval


def bisection(l, seeds, fitness_func, offspring_func):
    n_upper = phase_1(l, seeds, fitness_func, offspring_func)
    mrps, avg_num_of_eval = phase_2(l, n_upper, seeds, fitness_func,
                                    offspring_func)
    return mrps, avg_num_of_eval


def run(l, fitness_func, offspring_func):
    global MSSV

    seeds = np.zeros((10, ), np.int32)
    mrps = np.zeros((10, ), np.int32)
    avg_num_of_eval = np.zeros(10, np.int64)

    for i in range(10):
        for j in range(10):
            seeds[j] = MSSV + 10 * i + j
        print(seeds)

        print('Bisection', i, 'th')
        mrps[i], avg_num_of_eval[i] = bisection(l, seeds, fitness_func,
                                                offspring_func)

    return mrps, avg_num_of_eval


def main():
    mrps, avg_num_of_eval = run(160, OneMax, Universal_hybrid)
    print(mrps)
    print(avg_num_of_eval)

    print('Time:', time.time() - start)


main()