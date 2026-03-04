/*
완성품을 봤을 때
사방이 막히지 않은 셀 + 가장자리의 셀에서 시작해야 함. flood fll
*/

#include <iostream>
#include <vector>
#include <string>
#include <queue>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<char>> board(n, std::vector<char> (m));
    std::string line;
    for (int r = 0; r < n; r++) {
        std::cin >> line;
        for (int c = 0; c < m; c++) {
            board[r][c] = line[c];
        }
    }

    std::vector<int> dr = {-1, 1, 0, 0};
    std::vector<int> dc = {0, 0, -1, 1};

    std::queue<std::pair<int, int>> q;
    std::vector<std::vector<bool>> visited(n, std::vector<bool> (m));
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            // 가장자리
            if ((r == 0 || r == n - 1 || c == 0 || c == m - 1) && board[r][c] == 'X') {
                q.push({r, c});
                visited[r][c] = true;
                continue;
            }

            // 사방이 완전히 막히지 않음
            bool valid = false;
            for (int dir = 0; dir < 4; dir++) {
                int nr = r + dr[dir];
                int nc = c + dc[dir];

                if (nr < 0 || nr >= n || nc < 0 || nc >= m) {
                    continue;
                }

                if (board[nr][nc] != 'X') {
                    valid = true;
                    break;
                }
            }

            if (valid) {
                q.push({r, c});
                visited[r][c] = true;
            }
        }
    }

    int ans = 1;
    while (true) {
        std::queue<std::pair<int, int>> nq;

        while (!q.empty()) {
            auto [cr, cc] = q.front();
            q.pop();

            for (int dir = 0; dir < 4; dir++) {
                int nr = cr + dr[dir];
                int nc = cc + dc[dir];

                if (nr < 0 || nr >= n || nc < 0 || nc >= m) {
                    continue;
                }

                if (visited[nr][nc] || board[nr][nc] != 'X') {
                    continue;
                }

                nq.push({nr, nc});
                visited[nr][nc] = true;
            }
        }

        // 다 퍼짐. 끝
        if (nq.empty()) {
            break;
        }

        std::swap(q, nq);
        ans++;
    }

    std::cout << ans;

    return 0;
}