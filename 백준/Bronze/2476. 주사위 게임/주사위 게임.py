import sys

def main():
    N = int(sys.stdin.readline().strip())

    best = 0
    for _ in range(N):
        a, b, c = map(int, sys.stdin.readline().split())
        cur = 0
        if a == b == c:
            cur = 10000 + 1000 * a
        elif a == b or a == c:
            cur = 1000 + a * 100
        elif b == c:
            cur = 1000 + b * 100
        else:
            cur = max(a, b, c) * 100
        
        best = max(best, cur)

    print(best)

if __name__ == "__main__":
    main()