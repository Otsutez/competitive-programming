#!/usr/bin/env python3

n = int(input())

# sum = 1
# num_zero = 0

# def count_trailing_zero(n):
#     n = str(n)
#     count = 0
#     for c in n[-1:]:
#         if c == "0":
#             count += 1
#         else:
#             break
#     return count

# for i in range(1, n + 1):
#     sum = sum * i
#     if sum % 10 == 0:
#         n = count_trailing_zero(sum)
#         num_zero += n
#         sum = sum // 10
#     else:
#         sum = sum % 10;

z = 0

while n:
    n //= 5
    z += n

print(z)
