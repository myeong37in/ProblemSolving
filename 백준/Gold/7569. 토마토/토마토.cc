/*
7576번의 연장
높이가 추가되어 3차원 vector로 푼다.
*/

#include <iostream>
#include <vector>
#include <queue>

std::vector<std::vector<std::vector<int>>> vec;
std::vector<std::vector<std::vector<bool>>> visited;
std::vector<std::vector<std::vector<int>>> time;

std::vector<int> dr = {-1, 1, 0, 0, 0, 0};
std::vector<int> dc = {0, 0, -1, 1, 0, 0};
std::vector<int> dh = {0, 0, 0, 0, -1, 1};

void bfs(std::vector<std::pair<std::pair<int, int>, int>> starts) {
    std::queue<std::pair<std::pair<int, int>, int>> q;

    for (const auto& p : starts) {
        visited[p.first.first][p.first.second][p.second] = true;
        time[p.first.first][p.first.second][p.second] = 0;
        q.push(p);
    }

    while (!q.empty()) {
        int current_row = q.front().first.first;
        int current_col = q.front().first.second;
        int current_height = q.front().second;
        q.pop();

        for (int i = 0; i < 6; i++) {
            int next_row = current_row + dr[i];
            int next_col = current_col + dc[i];
            int next_height = current_height + dh[i];

            if (next_row >= 0 && next_row < vec.size() &&
                next_col >= 0 && next_col < vec[0].size() &&
                next_height >= 0 && next_height < vec[0][0].size() &&
                !visited[next_row][next_col][next_height] &&
                vec[next_row][next_col][next_height] != -1) {

                visited[next_row][next_col][next_height] = true;
                q.push({{next_row, next_col}, next_height});
                time[next_row][next_col][next_height] = time[current_row][current_col][current_height] + 1;
            }
        }
    }
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M, H;
    std::cin >> M >> N >> H;

    vec.assign(N, std::vector<std::vector<int>> (M, std::vector<int> (H)));
    time.assign(N, std::vector<std::vector<int>> (M, std::vector<int> (H)));
    visited.assign(N, std::vector<std::vector<bool>> (M, std::vector<bool> (H)));
    std::vector<std::pair<std::pair<int, int>, int>> starts;
    for (int k = 0; k < H; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                std::cin >> vec[i][j][k];

                if (vec[i][j][k] == 1) {
                    starts.emplace_back(std::pair<std::pair<int, int>, int> {{i, j}, k});
                }
            }
        }
    }

    bfs(starts);

    bool is_possible = true;
    int max_time = 0;
    for (int k = 0; k < H; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (vec[i][j][k] != -1 && !visited[i][j][k]) {
                    is_possible = false;
                    break;
                }
                if (time[i][j][k] > max_time) {
                    max_time = time[i][j][k];
                }
            }
            if (!is_possible) {
                break;
            }
        }
        if (!is_possible) {
            break;
        }
    }

    if (is_possible) {
        std::cout << max_time;
    }
    else {
        std::cout << -1;
    }

    return 0;
}