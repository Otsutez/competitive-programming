#!/usr/bin/env python3
n = int(input())

x = []
y = []
x_sum = 0
y_sum = 0

for i in range(n, 0, -1):
    if y_sum < x_sum:
        y.append(i)
        y_sum += i
    else:
        x.append(i)
        x_sum += i

if x_sum == y_sum:
    print("YES")
    print(len(x))
    print(" ".join(map(str, x)))
    print(len(y))
    print(" ".join(map(str, y)))
else:
    print("NO")
    
    
    
