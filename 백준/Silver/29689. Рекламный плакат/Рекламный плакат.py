'''
인접한 2개 중 긴 문자열을 세로로, 짧은 것은 가로로
'''

import sys

def main():
    N = int(sys.stdin.readline().strip())
    prev_len = len(sys.stdin.readline().strip())
    best = 0

    if N == 1:
        print(1) # 아 1이어야지
        sys.exit()

    for _ in range(1, N):
        s = sys.stdin.readline().strip()
        cur = min(len(s), prev_len)

        best = max(best, cur)
        prev_len = len(s)

    print(best)

if __name__ == "__main__":
    main()