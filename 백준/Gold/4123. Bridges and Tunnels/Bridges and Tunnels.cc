/*
거리 2개지 뭐

O(p*(n+m)*log(n))
*/

#include <iostream>
#include <vector>
#include <queue>

struct Edge {
    int to, dist;
    char type;
};

struct State {
    int to;
    long long out_dist, total_dist;
};

auto cmp = [](const State& a, const State& b) {
    if (a.out_dist == b.out_dist) {
        return a.total_dist > b.total_dist;
    }
    return a.out_dist > b.out_dist;
};

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m, p;
    std::cin >> n >> m >> p;

    constexpr long long INF = 9e18;
    // first: 실외 거리, second: 총 거리 
    std::vector<std::pair<long long, long long>> dists;

    std::vector<std::vector<Edge>> graph(n);
    int u, v, d;
    char type;
    for (int i = 0; i < m; i++) {
        std::cin >> u >> v >> d >> type;

        graph[u].emplace_back(Edge {v, d, type});
        graph[v].emplace_back(Edge {u, d, type});
    }

    int s, e;
    for (int i = 0; i < p; i++) {
        std::cin >> s >> e;
        dists.assign(n, {INF, INF});

        std::priority_queue<State, std::vector<State>, decltype(cmp)> pq(cmp);
        pq.push({s, 0, 0});
        dists[s].first = 0;
        dists[s].second = 0;

        while (!pq.empty()) {
            auto [cur, out_dist, total_dist] = pq.top();
            pq.pop();

            if (dists[cur].first != out_dist || dists[cur].second != total_dist) {
                continue;
            }

            for (auto& [to, dist, type] : graph[cur]) {
                long long out_ndist = out_dist;
                long long total_ndist = total_dist;

                if (type == 'O') {
                    out_ndist += dist;
                    
                }
                total_ndist += dist;

                if (dists[to].first < out_ndist || (dists[to].first == out_ndist && dists[to].second <= total_ndist)) {
                    continue;
                }

                dists[to].first = out_ndist;
                dists[to].second = total_ndist;

                pq.push({to, out_ndist, total_ndist});
            }
        }

        if (dists[e].first == INF) {
            std::cout << "IMPOSSIBLE\n";
        }
        else {
            std::cout << dists[e].first << " " << dists[e].second << "\n";
        }
    }
    
    return 0;
}