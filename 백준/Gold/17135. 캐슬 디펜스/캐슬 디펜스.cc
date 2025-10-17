/*
배치 C(15, 3) = 455
시뮬레이션 BFS 
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

struct State {
    int r, c, dist;
};

std::vector<std::vector<int>> orig_board, visited;

// 남쪽은 고려할 필요 없음
std::vector<int> dr = {-1, 0, 0};
std::vector<int> dc = {0, -1, 1};

int N, M, D;

int visit_cnt = 1;

static inline bool IsEmpty(std::vector<std::vector<int>>& board) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j]) {
                return false;
            }
        }
    }

    return true;
}

// 문제의 조건에 맞는 적의 좌표를 반환
std::pair<int, int> bfs(std::vector<std::vector<int>>& board, int archer_col) {
    
    if (board[N - 1][archer_col]) { // 바로 앞에 적이 있으면 해당 적으로 확정
        return {N - 1, archer_col};
    }

    std::queue<State> q;
    q.push({N - 1, archer_col, 1});
    visited[N - 1][archer_col] = visit_cnt;

    std::vector<State> candidates;
    while (!q.empty()) {
        auto [r, c, dist] = q.front();
        q.pop();

        if (dist >= D) {
            break;
        }

        for (int dir = 0; dir < 3; dir++) {
            int nr = r + dr[dir];
            int nc = c + dc[dir];

            if (nr < 0 || nr >= N || nc < 0 || nc >= M || visited[nr][nc] == visit_cnt) {
                continue;
            }

            if (board[nr][nc]) {
                candidates.emplace_back(State {nr, nc, dist + 1});
            }

            visited[nr][nc] = visit_cnt;
            q.push({nr, nc, dist + 1});
        }
    }

    if (candidates.empty()) {
        return {-1, -1};
    }

    std::sort(candidates.begin(), candidates.end(), [](const auto& a, const auto& b) {
        if (a.dist == b.dist) {
            return a.c < b.c;
        }
        return a.dist < b.dist;
    });

    return {candidates[0].r, candidates[0].c};
}

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::cin >> N >> M >> D;

    orig_board.assign(N, std::vector<int> (M));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cin >> orig_board[i][j];
        }
    }

    if (IsEmpty(orig_board)) {
        std::cout << 0;
        return 0;
    }

    std::vector<int> archers(M);
    for (int i = M - 1; i >= M - 3; i--) {
        archers[i] = 1;
    }

    visited.assign(N, std::vector<int> (M));
    int ans = 0;
    do {
        std::vector<std::vector<int>> board = orig_board;
        int res = 0;
        while (!IsEmpty(board)) {
            std::set<std::pair<int, int>> removes;
            for (int i = 0; i < M; i++) {
                if (archers[i]) {
                    auto [r, c] = bfs(board, i);
                    if (r != -1) {
                        removes.insert({r, c});
                    }
                    visit_cnt++;
                }
            }

            // 궁수의 적 제거
            for (const auto& p : removes) {
                board[p.first][p.second] = 0;
                res++;
            }

            // 한 칸씩 아래로 밀기
            for (int i = N - 1; i > 0; i--) {
                for (int j = 0; j < M; j++) {
                    board[i][j] = board[i - 1][j];
                }
            }
            for (int j = 0; j < M; j++) {
                board[0][j] = 0;
            }
        }

        ans = std::max(ans, res);
    } while (std::next_permutation(archers.begin(), archers.end()));

    std::cout << ans;

    return 0;
}