class Domino:
    def __init__(self, num):
        self.num = num
        self.neighbours = []

    def add_neighbour(self, n):
        self.neighbours.append(n)

d, r = map(int, input().split())
dominoes = []
for i in range(d):
    dominoes.append(Domino(i))
for i in range(r):
    a, b = map(int, input().split())
    a, b = a-1, b-1
    dominoes[a].add_neighbour(dominoes[b])

counts = [0] * d
for i in range(d):
    # BFS to count number of dominoes toppled
    count = 0
    s = [dominoes[i]]
    visited = [False] * d
    while s:
        curr = s.pop()
        visited[curr.num] = True
        count += 1
        for n in curr.neighbours:
            if not visited[n.num]:
                s.append(n)
    counts[i] = count
    
print(" ".join(map(str, counts)))
