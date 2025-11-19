#!/usr/bin/env python3

from collections import namedtuple
from math import sqrt

Point = namedtuple('Point', 'x y')

class PiecewiseFunction:
    def __init__(self, x1, y1, x2, y2):
        self.first = Point(x1, y1)
        self.second = Point(x2, y2)
        self.m = (y2 - y1) / (x2 - x1)
        self.c = y1 - self.m * x1
        # print(f"y = {self.m}x + {self.c}")

    def contains(self, x):
        return self.first.x <= x and x <= self.second.x

    def area(self):
        return 0.5 * (self.second.x - self.first.x) * (self.first.y + self.second.y)

    def get_x_satisfy_area(self, area, x1):
        m = self.m
        c = self.c
        if m != 0:
            # Trapezoid strategy
            y1 = x1 * m + c

            b = c + y1 - x1 * m
            a = m
            c = - (x1 * c + x1 * y1 + area * 2)

            x2 = (-b + sqrt(b ** 2 - 4 * a * c)) / (2 * a)
            x2 = min(self.second.x, x2)
            ar = 0.5 * (x2 - x1) * (y1 + m * x2 + self.c)
        else:
            # Rectangle strategy
            if c == 0:
                # Area will be zero
                return (self.second.x, 0)
            x2 = area / c + x1
            x2 = min(self.second.x, x2)
            ar = (x2 - x1) * c
        return (x2, ar)
    

class Function:
    def __init__(self):
        self.functions = []
        self.area = 0

    def add_piecewise(self, x1, y1, x2, y2):
        p = PiecewiseFunction(x1, y1, x2, y2)
        self.functions.append(p)
        self.area += p.area()

    def get_satisfy_x(self, start, n):
        i = 0
        while not self.functions[i].contains(start):
            i += 1
        threshold = (1/n) * self.area
        while i < len(self.functions) and abs(threshold) >= 1e-08:
            p = self.functions[i]
            x, area = p.get_x_satisfy_area(threshold, start)
            # print(x, area)
            start = x
            threshold -= area
            i += 1

        if abs(threshold) >= 1e-08:
            return None
        else:
            return x


n, l = map(int, input().split(" "))
sponsors = []
for i in range(n):
    line = list(map(int, input().split()))
    m = line[0]
    f = Function()
    for j in range(1, len(line) - 2, 2):
        f.add_piecewise(line[j], line[j + 1], line[j + 2], line[j + 3])
    sponsors.append((i + 1, f))

solutions = []
start = 0
while sponsors:
    # Find sponsor who will be satisfies with the least amount of space
    min_x = l
    candidate = (1, min)
    candidate_index = 0
    for i, (num, function) in enumerate(sponsors):
        x = function.get_satisfy_x(start, n)
        if x:
            if x <= min_x:
                min_x = x
                candidate = (num, x)
                candidate_index = i
        else:
            print("impossible")
            exit(0)
    start = min_x
    # Check if last sponsor
    if len(sponsors) == 1:
        solutions.append((num, l))
        break
    else:
        solutions.append(candidate)
    sponsors.pop(candidate_index)

# print(solutions)
for num, x in solutions:
    print(f"{x:.10f}", num)
