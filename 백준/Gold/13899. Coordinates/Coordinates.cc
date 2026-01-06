/*
평행 이동으로만 절대 좌표가 바뀔 수 있고 상대 위치는 확정되므로 a_i, b_i의 입력에서 1에서 N까지 모든 수가 나타날 것

대충 BFS 쓰면 될 듯
*/

#include <iostream>
#include <vector>
#include <queue>

struct Edge {
    int to, dx, dy;
};

struct Coord {
    int x, y;
};

std::vector<Coord> coords;
std::vector<std::vector<Edge>> graph;

constexpr int INF = 2e9;

void bfs(int start) {
    std::queue<int> q;
    q.push(start);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (const auto& nxt : graph[cur]) {
            auto [to, dx, dy] = nxt;
            if (coords[to].x != INF) {
                continue;
            }

            coords[to].x = coords[cur].x + dx;
            coords[to].y = coords[cur].y + dy;

            q.push(to);
        }
    }
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N, M;
    std::cin >> N >> M;

    graph.resize(N + 1);
    int a, b, dx, dy;
    for (int i = 0; i < M; i++) {
        std::cin >> a >> b >> dx >> dy;

        graph[a].emplace_back(Edge {b, dx, dy});
        graph[b].emplace_back(Edge {a, -dx, -dy});
    }

    coords.assign(N + 1, Coord {INF, INF});

    coords[1] = {0, 0};
    bfs(1);

    for (int i = 1; i <= N; i++) {
        std::cout << coords[i].x << " " << coords[i].y << "\n";
    }

    return 0;
}