import sys
input = sys.stdin.readline

t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))

    if n <= 2:
        print(-1)
        continue

    a.sort()
    total = sum(a)

    k = n // 2
    x = 2 * n * a[k] - total + 1

    print(max(0, x))
