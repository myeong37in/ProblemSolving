'''
Python 공부 더 열심히 해야겠지..?
'''

import sys

def main():
    N = int(sys.stdin.readline().strip())
    target = int(sys.stdin.readline().strip())

    board = [[0 for _ in range(N)] for _ in range(N)]
    dr = [-1, 0, 1, 0]
    dc = [0, 1, 0, -1]
    d = 0
    moves = 1 # 이동 거리
    cc = N // 2
    cr = N // 2
    board[cr][cc] = 1 
    val = 2 # 보드에 기록될 수
    target_r = cr # target의 좌표 저장
    target_c = cc
    while val <= N * N:
        for _ in range(2): # 같은 거리를 두 번 가면 거리 증가
            for _ in range(moves):
                if (val > N * N):
                    break

                cr += dr[d]
                cc += dc[d]
                board[cr][cc] = val
                
                if val == target:
                    target_r, target_c = cr, cc
                val += 1
            d = (d + 1) % 4
        moves += 1

    for i in range(N):
        for j in range(N):
            print(board[i][j], end = ' ')
        print("")

    print(target_r + 1, target_c + 1)
    

if __name__ == "__main__":
    main()