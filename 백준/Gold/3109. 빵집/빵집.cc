/*
안 겹치게 하려면 0행에서 R - 1행까지 탐색한다고 했을 때 위로 가는 방향부터 그리디로 연결해 보면 되지 않을까?

갔던 칸은 다시 재방문할 일이 절대 없음.
1) 경로를 만들었다면 문제의 조건에 따라 재방문 x
2) 경로를 만들지 못했다면 해당 경로를 다시 사용할 이유가 없으므로 재방문 x

O(RC)
*/

#include <iostream>
#include <vector>
#include <string>

std::vector<std::vector<char>> board;
std::vector<std::vector<bool>> visited;
std::vector<int> dr = {-1, 0, 1};

int R, C;

static bool dfs(int cr, int cc) {
    visited[cr][cc] = true;

    if (cc == C - 1) {
        return true;
    }

    for (int dir = 0; dir < 3; dir++) {
        int nr = cr + dr[dir];
        int nc = cc + 1;
        if (nr < 0 || nr >= R) {
            continue;
        }

        if (visited[nr][nc] || board[nr][nc] == 'x') {
            continue;
        }

        if (dfs(nr, nc)) {
            return true;
        }
    }

    return false;
}

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> R >> C;

    std::string line;
    
    board.assign(R, std::vector<char> (C));
    for (int r = 0; r < R; r++) {
        std::cin >> line;
        for (int c = 0; c < C; c++) {
            board[r][c] = line[c];
        }
    }

    visited.assign(R, std::vector<bool> (C));
    int ans = 0;
    for (int r = 0; r < R; r++) {
        if (dfs(r, 0)) {
            ans++;
        }
    }

    std::cout << ans;

    return 0;
}