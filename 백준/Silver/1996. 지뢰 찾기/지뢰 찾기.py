import sys

def main():
    N = int(sys.stdin.readline())
    board = [list(sys.stdin.readline().strip()) for _ in range(N)]
    res = [[0] * N for _ in range(N)]

    dr = [-1, -1, 0, 1, 1, 1, 0, -1]
    dc = [0, 1, 1, 1, 0, -1, -1, -1]
    for r in range(N):
        for c in range(N):
            if board[r][c] != '.':
                res[r][c] = '*'
                continue

            mine_sum = 0
            for dir in range(8):
                nr = r + dr[dir]
                nc = c + dc[dir]

                if nr < 0 or nr >= N or nc < 0 or nc >= N:
                    continue
                    
                if board[nr][nc] == '.':
                    continue
                
                mine_sum += int(board[nr][nc])
            
            if mine_sum >= 10:
                res[r][c] = 'M'
            else:
                res[r][c] = mine_sum

    for r in range(N):
        for c in range(N):
            print(res[r][c], end = '')
        print()

if __name__ == "__main__":
    main()