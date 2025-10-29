'''
앞에서부터 비용 누적 합, 뒤에서부터 누적 합을 구하면
특정 지점에서 그 지점의 비용을 x라고 하면 x + k를 이분 탐색으로 찾아 최대 거리를 구하면 될 듯

O(N logN)
'''

import sys
from bisect import bisect_right

def main():
    n, k = map(int, sys.stdin.readline().split())
    seq = [0] * n
    
    for i in range(n):
        seq[i] = int(sys.stdin.readline().strip())
    
    # 앞에서부터 정방향 누적 합으로 최적값 구하기
    prev = seq[0]
    fwd_psum = [0] * n
    for i in range(1, n):
        fwd_psum[i] = fwd_psum[i - 1]
        if seq[i] > prev:
            fwd_psum[i] += seq[i] - prev
        
        prev = seq[i]

    best = 1
    for i in range(n):
        cur = fwd_psum[i]
        idx = bisect_right(fwd_psum, cur + k) - 1
        best = max(best, idx - i + 1)

    # 뒤에서부터(뒤집어서) 역방향 누적 합으로 최적값 구하기
    seq_rev = list(reversed(seq))
    nxt = seq_rev[0]
    rev_psum = [0] * n
    for i in range(1, n):
        rev_psum[i] = rev_psum[i - 1]
        if seq_rev[i] > nxt:
            rev_psum[i] += seq_rev[i] - nxt
        
        nxt = seq_rev[i]

    for i in range(n):
        cur = rev_psum[i]
        idx = bisect_right(rev_psum, cur + k) - 1
        best = max(best, idx - i + 1)

    print(best)

if __name__ == "__main__":
    main()