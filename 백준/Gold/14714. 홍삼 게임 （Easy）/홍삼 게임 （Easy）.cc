/*
두 개를 관리해야 하는 BFS?
*/

#include <iostream>
#include <vector>
#include <queue>

struct State {
    int A, B, dist;
};

int bfs(int N, int A, int B, int DA, int DB) {
    std::queue<State> q;
    q.push({A, B, 0});
    // visited[i][j][k]: A가 i, B가 j, 현재 k가 이동할 차례(k = 0일 때 A, 1일 때 B)인 상태를 방문
    std::vector<std::vector<std::vector<bool>>> visited(N, std::vector<std::vector<bool>> (N, std::vector<bool> (2)));
    visited[A][B][0] = true;
    
    while (!q.empty()) {
        auto [a, b, dist] = q.front();
        q.pop();

        if (a == b) {
            return dist;
        }

        // a만 이동한 뒤 dist는 홀수, 둘 다 이동한 뒤(혹은 최초에) 0 포함 짝수
        if ((dist & 1) == 0) {
            int nxt_a = (N + a - DA) % N;
            if (!visited[nxt_a][b][1]) {
                visited[nxt_a][b][1] = true;
                q.push({nxt_a, b, dist + 1});
            }
            nxt_a = (a + DA) % N;
            if (!visited[nxt_a][b][1]) {
                visited[nxt_a][b][1] = true;
                q.push({nxt_a, b, dist + 1});
            }
        }
        else {
            int nxt_b = (N + b - DB) % N;
            if (!visited[a][nxt_b][0]) {
                visited[a][nxt_b][0] = true;
                q.push({a, nxt_b, dist + 1});
            }
            nxt_b = (b + DB) % N;
            if (!visited[a][nxt_b][0]) {
                visited[a][nxt_b][0] = true;
                q.push({a, nxt_b, dist + 1});
            }
        }
    }

    return -1;
}

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, A, B, DA, DB;
    std::cin >> N >> A >> B >> DA >> DB;

    int ans = bfs(N, A - 1, B - 1, DA, DB); // 0-based로
    if (ans == -1) {
        std::cout << "Evil Galazy";
    }
    else {
        std::cout << ans;
    }

    return 0;
}