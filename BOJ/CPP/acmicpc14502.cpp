// https://www.acmicpc.net/problem/14502
// 연구소
// 골드 4

/*
DFS: O(V+E). V: N*M, E: 4*N*M -> 전체 5*N*M번
N*M개의 칸 중 3개 칸에 벽을 배치하는 경우 -> C(N*M, 3)
N = M = 8일 떄 연산 13,332,480번. 완전 탐색으로 가능
*/

#include <iostream>
#include <vector>

std::vector<int> dr = {-1, 1, 0, 0};
std::vector<int> dc = {0, 0, -1, 1};

void dfs(std::vector<std::vector<int>>& graph, std::vector<std::vector<bool>>& visited, const int& cur_row, const int& cur_col, const int& N, const int& M) {
    visited[cur_row][cur_col] = true;
    graph[cur_row][cur_col] = 2;

    for (int i = 0; i < 4; i++) {
        int next_row = cur_row + dr[i];
        int next_col = cur_col + dc[i];

        if (next_row < 0 || next_row >= N || next_col < 0 || next_col >= M || visited[next_row][next_col] || graph[next_row][next_col] != 0) {
            continue;
        }

        dfs(graph, visited, next_row, next_col, N, M);
    }
}

// 백트래킹으로 C(NM, 3)의 조합을 구해 combo에 저장하는 함수
void GetCombination(const std::vector<std::pair<int, int>>& empty, std::vector<std::vector<std::pair<int, int>>>& combo, std::vector<std::pair<int, int>>& cur, const int& idx, const int& max_idx) {
    if (cur.size() == 3) {
        combo.emplace_back(cur);
        return;
    }

    for (int i = idx; i <= max_idx; i++) {
        cur.emplace_back(empty[i]);
        GetCombination(empty, combo, cur, i + 1, max_idx);
        cur.pop_back();
    }
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<int>> board(N, std::vector<int> (M));
    std::vector<std::pair<int, int>> empty;
    int wall_count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cin >> board[i][j];

            if (board[i][j] == 0) {
                empty.emplace_back(i, j);
            }
            if (board[i][j] == 1) {
                wall_count++;
            }
        }
    }

    std::vector<std::vector<std::pair<int, int>>> combo;
    std::vector<std::pair<int, int>> cur;
    int max_idx = empty.size() - 1;
    GetCombination(empty, combo, cur, 0, max_idx);

    int answer = 0;
    std::vector<std::vector<bool>> visited;
    for (const auto& vec : combo) {
        std::vector<std::vector<int>> temp_board = board;
        for (const auto& p : vec) {
            temp_board[p.first][p.second] = 1;
        }

        visited.assign(N, std::vector<bool> (M, false));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (temp_board[i][j] == 2 && !visited[i][j]) {
                    dfs(temp_board, visited, i, j, N, M);
                }
            }
        }

        int safe = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (temp_board[i][j] == 0) {
                    safe++;
                }
            }
        }
        
        answer = std::max(answer, safe);

    }

    std::cout << answer;

    return 0;
}