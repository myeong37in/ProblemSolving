'''
있는 문제잖아아우아으아아!!

정렬도 해서 주잖아으아아으아어아야아애ㅐㅏ아
'''

import sys

def main():
    N = int(sys.stdin.readline().strip())
    li = []
    for _ in range(N):
        x, y = map(int, sys.stdin.readline().split())
        li.append((x, y))

    start = li[0][0]
    end = li[0][1]
    ans = 0
    for i in range(1, N):
        nx, ny = li[i]
        if nx > end:
            ans += end - start # 이전 선분 길이 더하기
            # 새 선분 시작
            start = nx
            end = ny
        else:
            end = max(end, ny)

    ans += end - start # 마지막 선분 길이 더하기
    print(ans)

if __name__ == "__main__":
    main()