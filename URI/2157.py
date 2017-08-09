from functools import reduce

c = int(input())

for i in range(c):
    E, B = map(int, input().split())
    mirror = str(reduce(lambda x, y: str(x) + str(y), range(E, B+1)))
    print(mirror + mirror[::-1])

