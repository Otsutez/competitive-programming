"""
Backtracking recursively goes through all the ways a solution can be construct
and try to find all the solutions. 

Take the problem of finding the number of ways n queens can be placed on a nxn
chessboard such that no queen attacks each other. This can be solved by placing
1 queen at a time on each row and recursively exploring where the next queen
can be placed on the next row such that they do not attack each other.
"""

def search(k):
    global n, count, column, diag1, diag2
    if k == n:
        count += 1
        return
    else:
        for i in range(n):
            if column[i] or diag1[i + k] or diag2[i - k + n - 1]: continue
            column[i] = diag1[i + k] = diag2[i - k + n - 1] = True
            search(k + 1)
            column[i] = diag1[i + k] = diag2[i - k + n - 1] = False

n = int(input())
count = 0
column = [False] * n
diag1 = [False] * ((n - 1) * 2 + 1)
diag2 = [False] * ((n - 1) * 2 + 1)

search(0)
print(count)

