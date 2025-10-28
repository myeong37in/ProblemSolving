'''
손님이 아닌 초밥 기준으로 보면 초밥은 앞의 손님부터 순서대로 매칭됨 -> queue
'''

import sys
from collections import deque

def main():
    N, M = map(int, sys.stdin.readline().split())

    MAX = 200000
    deq_li = [deque() for _ in range(MAX + 1)]
    ans = [0] * (N + 1)

    # 최대 20만
    for i in range(1, N + 1):
        kind = list(map(int, sys.stdin.readline().split()))
        for sushi in kind[1:]:
            deq_li[sushi].append(i)
    
    given = list(map(int, sys.stdin.readline().split()))
    for sushi in given:
        if not deq_li[sushi]:
            continue
        ans[deq_li[sushi].popleft()] += 1
        
    for i in range(1, N + 1):
        print(ans[i], end = ' ')

if __name__ == "__main__":
    main()