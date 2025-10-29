import sys

def main():
    N = int(sys.stdin.readline().strip())
    li = list(map(int, sys.stdin.readline().split()))

    len = 0
    best = 0
    decreasing = False
    prev = -1
    for x in li:
        if x > prev:
            if decreasing: # 감소하다가 다시 증가하면 산이 새로 시작
                len = 1
                decreasing = False
            len += 1
        elif x < prev:
            decreasing = True
            len += 1
        else:
            len = 1
            decreasing = False

        best = max(best, len)
        prev = x

    print(best)

if __name__ == "__main__":
    main()