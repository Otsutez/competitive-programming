"""
Calculate the number of paths in an nxn grid from the upper left corner to the
lower right corner such that the paths visit each square exactly once. 
"""

# Note that x and y is (0,0) at upperleft corner and (n,n) at lower right corner
def searchGrid(x, y):
    global n, count, dx, dy, visited, moves
    if x == (n - 1) and y == (n - 1):
        if moves == n * n:
            count += 1
        return
    else:
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx >= 0 and nx < n and ny >= 0 and ny < n and not visited[nx][ny]:
                visited[x][y] = True
                moves += 1
                searchGrid(nx, ny)
                moves -= 1
                visited[x][y] = False
                

n = int(input())
count = 0
dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]
visited = [[False] * n for _ in range(n)]
moves = 2

if n == 1:
    print(1)
else:
    visited[0][0] = True
    searchGrid(1, 0)
    print(count * 2)
