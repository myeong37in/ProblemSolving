import sys

def main():
    N = int(sys.stdin.readline().strip())
    li = list(map(int, sys.stdin.readline().split()))

    # 비감소 수열 길이 찾기
    prev = 0
    best = 0
    cur = 0
    for n in li:
        if n >= prev:
            cur += 1
        else:
            cur = 1
        
        prev = n
        best = max(best, cur)

    # 비증가 수열 길이 찾기
    prev = 1e5
    cur = 0
    for n in li:
        if n <= prev:
            cur += 1
        else:
            cur = 1
        
        prev = n
        best = max(best, cur)

    print(best)


if __name__ == "__main__":
    main()