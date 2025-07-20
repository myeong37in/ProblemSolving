// https://www.acmicpc.net/problem/14500
// 테트로미노
// 골드 4

/*
DFS로 풀면서 'ㅗ'를 회전시킨 4개의 모양은 따로 처리
*/

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> graph;
std::vector<std::vector<bool>> visited;

std::vector<int> dr = {-1, 1, 0, 0};
std::vector<int> dc = {0, 0, -1, 1};

int max_sum = 0;

void dfs(int current_row, int current_col, int count, int sum) {
    if (count == 4) {
        max_sum = std::max(max_sum, sum);
        return;
    }

    for (int i = 0; i < 4; i++) {
        int next_row = current_row + dr[i];
        int next_col = current_col + dc[i];

        if (next_row >= 0 && next_row < visited.size() && next_col >= 0 && next_col < visited[0].size() && !visited[next_row][next_col]) {
            visited[next_row][next_col] = true;
            dfs(next_row, next_col, count + 1, sum + graph[next_row][next_col]);
            visited[next_row][next_col] = false; // 분기마다 방문 해제 처리
        }
    }
}

void CheckExceptedShapes(int current_row, int current_col) { // graph[current_row][current_col]이 'ㅗ', 'ㅏ', 'ㅜ', 'ㅓ' 모양의 중심이 되어 네 개의 도형을 검사
    int center = graph[current_row][current_col];

    std::vector<int> other_cells;
    for (int i = 0; i < 4; i++) {
        int next_row = current_row + dr[i];
        int next_col = current_col + dc[i];

        if (next_row >= 0 && next_row < visited.size() && next_col >= 0 && next_col < visited[0].size()) {
            other_cells.emplace_back(graph[next_row][next_col]);
        }
    }

    if (other_cells.size() == 3) {
        int sum = center + other_cells[0] + other_cells[1] + other_cells[2];
        max_sum = std::max(max_sum, sum);
    }
    else if (other_cells.size() == 4) {
        int sum = center + other_cells[0] + other_cells[1] + other_cells[2] + other_cells[3];
        int min_cell = 1000;
        for (int num : other_cells) {
            if (min_cell > num) {
                min_cell = num;
            }
        }
        max_sum = std::max(max_sum, sum - min_cell);
    }
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;

    graph.assign(N, std::vector<int> (M));
    visited.assign(N, std::vector<bool> (M, false));
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cin >> graph[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            visited[i][j] = true;
            dfs(i, j, 1, graph[i][j]);
            visited[i][j] = false;
            CheckExceptedShapes(i, j);
        }
    }

    std::cout << max_sum;

    return 0;
}