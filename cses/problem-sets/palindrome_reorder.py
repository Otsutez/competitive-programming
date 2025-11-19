"""
# Algorithm Sketch

Count the occurrence of each character in the string
If n is even, then no count can be odd
If n is odd, one count can be odd

Loop forward through character set
print count / 2 number of characters
print odd number of characters if n is odd
Loop backward through character set
print count / 2 number of characters
"""

s = input()
n = len(s)
counter = [0] * 26

for c in s:
    i = ord(c) - ord("A")
    counter[i] += 1

# Check if have one odd count
oneOdd = None
for i, count in enumerate(counter):
    if count % 2 == 1:
        if oneOdd:
            print("NO SOLUTION")
            exit()
        else:
            oneOdd = i

if n % 2 == 0 and oneOdd:
    print("NO SOLUTION")
    exit()

# Create palindrome
for i in range(26):
    if i == oneOdd:
        continue
    for j in range(counter[i] // 2):
        print(chr(ord("A") + i), end="")
if n % 2 == 1:
    for j in range(counter[oneOdd]):
        print(chr(ord("A") + oneOdd), end="")
for i in range(25, -1, - 1):
    if i == oneOdd:
        continue
    for j in range(counter[i] // 2):
        print(chr(ord("A") + i), end="")
print()
