# Different ways to generate permutations
# Method 1, using recursion
def search():
    if len(permutation) == n:
        print(permutation)
    else:
        for i in range(n):
            if chosen[i]: continue
            chosen[i] = True
            permutation.append(i)
            search()
            chosen[i] = False
            permutation.pop()

print("Generating permutations with method 1")
n = 3
permutation = []
chosen = [False] * n
search()

# Method 2, using permutations() function in itertools
from itertools import permutations
a = []
for i in range(n): a.append(i)
print("Generating permutations with method 2")
for perm in permutations(a):
    print(perm)
