t = int(input())
for i in range(t):
    a, b = map(int, input().split(" "))
    temp = 2 * b - a
    if (temp >= 0 and temp % 3 == 0):
        x = b - 2 * temp / 3
        if x < 0:
            print("NO")
        else:
            print("YES")
    else:
        print("NO")
