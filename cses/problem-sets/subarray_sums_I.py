n, x = map(int, input().split())
arr = list(map(int, input().split()))

prefixSum = 0
s = set()
count = 0
for a in arr:
    prefixSum += a
    if prefixSum == x:
        count += 1
    elif prefixSum - x in s:
        count += 1
    s.add(prefixSum)
print(count)
