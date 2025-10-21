/*
BFS로 찾고 중력을 적용해
*/

#include <iostream>
#include <vector>
#include <string>
#include <queue>

std::vector<std::vector<char>> board(12, std::vector<char> (6));
std::vector<std::vector<int>> visited(12, std::vector<int> (6));

std::vector<int> dr = {-1, 1, 0, 0};
std::vector<int> dc = {0, 0, -1, 1};

int visit_cnt = 1;

static void ImplementGravity() {
    for (int c = 0; c < 6; c++) {
        int bottom = 11;
        for (int r = 11; r >= 0; r--) {
            if (board[r][c] != '.') {
                if (bottom != r) {
                    board[bottom][c] = board[r][c];
                    board[r][c] = '.';
                }
                bottom--;
            }
        }

        for (int r = bottom; r >= 0; r--) {
            board[r][c] = '.';
        }
    }
}

bool boom = false;
static void bfs(int sr, int sc) {
    std::queue<std::pair<int, int>> q;
    std::vector<std::pair<int, int>> components = {{sr, sc}};
    char cur = board[sr][sc];
    q.push({sr, sc});
    visited[sr][sc] = visit_cnt;

    while (!q.empty()) {
        auto [cr, cc] = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nr = cr + dr[dir];
            int nc = cc + dc[dir];

            if (nr < 0 || nr >= 12 || nc < 0 || nc >= 6 || visited[nr][nc] == visit_cnt) {
                continue;
            }

            if (board[nr][nc] == cur) {
                components.emplace_back(nr, nc);
                q.push({nr, nc});
                visited[nr][nc] = visit_cnt;
            }
        }
    }

    if (components.size() >= 4) {
        boom = true;
        for (const auto& [r, c] : components) {
            board[r][c] = '.';
        }
    }
}

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string line;
    for (int r = 0; r < 12; r++) {
        std::cin >> line;
        for (int c = 0; c < 6; c++) {
            board[r][c] = line[c];
        }
    }

    int combo = 0;
    while (true) {
        boom = false;
        for (int r = 0; r < 12; r++) {
            for (int c = 0; c < 6; c++) {
                if (board[r][c] != '.') {
                    bfs(r, c);
                    visit_cnt++;
                }
            }
        }

        if (!boom) {
            break;
        }

        ImplementGravity();
        
        combo++;
    }

    std::cout << combo;

    return 0;
}