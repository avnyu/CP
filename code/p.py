import os
import random
from sys import stdin, stdout

random.seed()


def read(): return stdin.readline().strip()
def read_int(): return [int(i) for i in read().split()]
def write(s): stdout.write(s)
