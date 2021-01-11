import math

t = int(input())

for i in range(1, t + 1):
    # print("Case", str(i), ":", end='')
    print("Case ", end='')
    print(i, end=': ')

    n = int(input())
    s = input()

    a = [int(x) for x in s.split(' ')]
    lcm = 1

    for x in a:
        lcm = (lcm * x) // math.gcd(lcm, x)

    print(lcm)