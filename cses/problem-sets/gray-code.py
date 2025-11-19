n = int(input())

for i in range(2 ** n):
    gray = i ^ (i >> 1)
    s = ""
    for j in range(n - 1, -1, -1):
        s += str((gray & (1 << j)) >> j)
    print(s)
