#include <iostream>
#include <vector>
#include <queue>

std::vector<std::vector<int>> vec; // 상자의 상태를 입력받는 vector
std::vector<std::vector<bool>> visited; // BFS 방문 여부를 표시하는 vector
std::vector<std::vector<int>> time; // 해당 좌표에 도달하는 최소 시간을 저장하는 vector

std::vector<int> x_dir = {-1, 1, 0, 0};
std::vector<int> y_dir = {0, 0, -1, 1};

// 익은 토마토들이 있는 위치를 저장한 vector 'starts'를 받아 시작점으로 설정하여 BFS
void bfs(std::vector<std::pair<int, int>> starts) { 
    std::queue<std::pair<int, int>> q;
    
    for (const auto& p : starts) {
        visited[p.first][p.second] = true;
        time[p.first][p.second] = 0;
        q.push(p);
    }

    while (!q.empty()) {
        int current_x = q.front().first;
        int current_y = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++) {
            int new_x = current_x + x_dir[i];
            int new_y = current_y + y_dir[i];

            if (new_x >= 0 && new_x < vec.size() && new_y >= 0 && new_y < vec[0].size() && !visited[new_x][new_y] && vec[new_x][new_y] != -1) {
                visited[new_x][new_y] = true;
                q.push({new_x, new_y});
                time[new_x][new_y] = time[current_x][current_y] + 1;
            }
        }
    }
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int M, N;
    std::cin >> M >> N;

    vec.assign(N, std::vector<int> (M));
    visited.assign(N, std::vector<bool> (M));
    time.assign(N, std::vector<int> (M));

    std::vector<std::pair<int, int>> starts;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            std::cin >> vec[i][j]; // (x좌표, y좌표) 형식으로 저장

            if (vec[i][j] == 1) {
                starts.emplace_back(std::pair<int, int> {i, j});
            }
        }
    }

    bfs(starts);

    bool is_possible = true; // 토마토가 전부 익었음을 나타내는 변수
    int max_time = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (vec[i][j] != -1 && !visited[i][j]) { // 빈 상자가 아니면서 방문하지 않은 상자에는 익지 않은 토마토가 있다.
                is_possible = false;
                break;
            }
            if (time[i][j] > max_time) {
                max_time = time[i][j];
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