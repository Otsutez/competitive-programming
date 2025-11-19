n = int(input())

def create(n):
    if n == 1:
        return ["0", "1"]

    prev = create(n - 1)
    new = []
    for i in prev:
        new.append("0" + i)
    for i in prev[::-1]:
        new.append("1" + i)
    return new


gray_code = create(n)
for i in gray_code:
    print(i)
