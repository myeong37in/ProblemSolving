/*
문자열 -> 정수 대응

Dijkstra

50% 할인 이거 뭔가 불안한데..
*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>

struct Edge {
    int dest;
    double cost;
};

auto cmp = [](const Edge& a, const Edge& b) {
    return a.cost > b.cost;
};

std::vector<std::vector<std::pair<int, double>>> subway, bus, taxi, airplane;
std::vector<std::vector<std::pair<int, double>>> ktx, strain, vtrain, saemaeul;
std::vector<std::vector<std::pair<int, double>>> cheongchun, mugunghwa;

int idx = 0; // distinct 도시 수

static double NaeilDijkstra(int s, int e) {
    std::vector<double> dists(idx, 2e9);
    
    std::priority_queue<Edge, std::vector<Edge>, decltype(cmp)> pq(cmp);
    pq.push({s, 0});
    dists[s] = 0;
    while (!pq.empty()) {
        auto [cur, sum] = pq.top();
        pq.pop();

        if (cur == e) {
            return sum;
        }

        if (dists[cur] < sum) {
            continue;
        }

        // 무료
        for (auto& [dest, cost] : mugunghwa[cur]) {
            if (dists[dest] > sum) {
                dists[dest] = sum;
                pq.push({dest, sum});
            }
        }
        for (auto& [dest, cost] : saemaeul[cur]) {
            if (dists[dest] > sum) {
                dists[dest] = sum;
                pq.push({dest, sum});
            }
        }
        for (auto& [dest, cost] : cheongchun[cur]) {
            if (dists[dest] > sum) {
                dists[dest] = sum;
                pq.push({dest, sum});
            }
        }

        // 반값
        for (auto& [dest, cost] : strain[cur]) {
            if (dists[dest] > sum + cost / 2) {
                dists[dest] = sum + cost / 2;
                pq.push({dest, sum + cost / 2});
            }
        }
        for (auto& [dest, cost] : vtrain[cur]) {
            if (dists[dest] > sum + cost / 2) {
                dists[dest] = sum + cost / 2;
                pq.push({dest, sum + cost / 2});
            }
        }

        // 할인 X
        for (auto& [dest, cost] : subway[cur]) {
            if (dists[dest] > sum + cost) {
                dists[dest] = sum + cost;
                pq.push({dest, sum + cost});
            }
        }
        for (auto& [dest, cost] : bus[cur]) {
            if (dists[dest] > sum + cost) {
                dists[dest] = sum + cost;
                pq.push({dest, sum + cost});
            }
        }
        for (auto& [dest, cost] : taxi[cur]) {
            if (dists[dest] > sum + cost) {
                dists[dest] = sum + cost;
                pq.push({dest, sum + cost});
            }
        }
        for (auto& [dest, cost] : airplane[cur]) {
            if (dists[dest] > sum + cost) {
                dists[dest] = sum + cost;
                pq.push({dest, sum + cost});
            }
        }
        for (auto& [dest, cost] : ktx[cur]) {
            if (dists[dest] > sum + cost) {
                dists[dest] = sum + cost;
                pq.push({dest, sum + cost});
            }
        }
    }

    return -1;
}

static double NormalDijkstra(int s, int e) {
    std::vector<double> dists(idx, 2e9);
    
    std::priority_queue<Edge, std::vector<Edge>, decltype(cmp)> pq(cmp);
    pq.push({s, 0});
    dists[s] = 0;
    while (!pq.empty()) {
        auto [cur, sum] = pq.top();
        pq.pop();

        if (cur == e) {
            return sum;
        }

        if (dists[cur] < sum) {
            continue;
        }

        for (auto& [dest, cost] : mugunghwa[cur]) {
            if (dists[dest] > sum + cost) {
                dists[dest] = sum + cost;
                pq.push({dest, sum + cost});
            }
        }
        for (auto& [dest, cost] : saemaeul[cur]) {
            if (dists[dest] > sum + cost) {
                dists[dest] = sum + cost;
                pq.push({dest, sum + cost});
            }
        }
        for (auto& [dest, cost] : cheongchun[cur]) {
            if (dists[dest] > sum + cost) {
                dists[dest] = sum + cost;
                pq.push({dest, sum + cost});
            }
        }
        for (auto& [dest, cost] : strain[cur]) {
            if (dists[dest] > sum + cost) {
                dists[dest] = sum + cost;
                pq.push({dest, sum + cost});
            }
        }
        for (auto& [dest, cost] : vtrain[cur]) {
            if (dists[dest] > sum + cost) {
                dists[dest] = sum + cost;
                pq.push({dest, sum + cost});
            }
        }
        for (auto& [dest, cost] : subway[cur]) {
            if (dists[dest] > sum + cost) {
                dists[dest] = sum + cost;
                pq.push({dest, sum + cost});
            }
        }
        for (auto& [dest, cost] : bus[cur]) {
            if (dists[dest] > sum + cost) {
                dists[dest] = sum + cost;
                pq.push({dest, sum + cost});
            }
        }
        for (auto& [dest, cost] : taxi[cur]) {
            if (dists[dest] > sum + cost) {
                dists[dest] = sum + cost;
                pq.push({dest, sum + cost});
            }
        }
        for (auto& [dest, cost] : airplane[cur]) {
            if (dists[dest] > sum + cost) {
                dists[dest] = sum + cost;
                pq.push({dest, sum + cost});
            }
        }
        for (auto& [dest, cost] : ktx[cur]) {
            if (dists[dest] > sum + cost) {
                dists[dest] = sum + cost;
                pq.push({dest, sum + cost});
            }
        }
    }

    return -1;
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N, R;
    std::cin >> N >> R;

    std::unordered_map<std::string, int> str_to_idx;
    std::string str;
    for (int i = 0; i < N; i++) {
        std::cin >> str;
        if (str_to_idx.find(str) == str_to_idx.end()) {
            str_to_idx[str] = idx++;
        }
    }

    int M;
    std::cin >> M;

    if (M == 1) {
        std::cout << "No";
        return 0;
    }

    std::vector<int> route(M);
    for (int i = 0; i < M; i++) {
        std::cin >> str;
        route[i] = str_to_idx[str];
    }

    int K;
    std::cin >> K;

    subway.resize(idx); bus.resize(idx), taxi.resize(idx), airplane.resize(idx), ktx.resize(idx);
    strain.resize(idx), vtrain.resize(idx), saemaeul.resize(idx), cheongchun.resize(idx), mugunghwa.resize(idx);

    std::string type, s, e;
    double cost;
    for (int i = 0; i < K; i++) {
        std::cin >> type >> s >> e >> cost;
        if (type == "Subway") {
            subway[str_to_idx[s]].emplace_back(str_to_idx[e], cost);
            subway[str_to_idx[e]].emplace_back(str_to_idx[s], cost);
        }
        else if (type == "Bus") {
            bus[str_to_idx[s]].emplace_back(str_to_idx[e], cost);
            bus[str_to_idx[e]].emplace_back(str_to_idx[s], cost);
        }
        else if (type == "Taxi") {
            taxi[str_to_idx[s]].emplace_back(str_to_idx[e], cost);
            taxi[str_to_idx[e]].emplace_back(str_to_idx[s], cost);
        }
        else if (type == "Airplane") {
            airplane[str_to_idx[s]].emplace_back(str_to_idx[e], cost);
            airplane[str_to_idx[e]].emplace_back(str_to_idx[s], cost);
        }
        else if (type == "KTX") {
            ktx[str_to_idx[s]].emplace_back(str_to_idx[e], cost);
            ktx[str_to_idx[e]].emplace_back(str_to_idx[s], cost);
        }
        else if (type == "S-Train") {
            strain[str_to_idx[s]].emplace_back(str_to_idx[e], cost);
            strain[str_to_idx[e]].emplace_back(str_to_idx[s], cost);
        }
        else if (type == "V-Train") {
            vtrain[str_to_idx[s]].emplace_back(str_to_idx[e], cost);
            vtrain[str_to_idx[e]].emplace_back(str_to_idx[s], cost);
        }
        else if (type == "ITX-Saemaeul") {
            saemaeul[str_to_idx[s]].emplace_back(str_to_idx[e], cost);
            saemaeul[str_to_idx[e]].emplace_back(str_to_idx[s], cost);
        }
        else if (type == "ITX-Cheongchun") {
            cheongchun[str_to_idx[s]].emplace_back(str_to_idx[e], cost);
            cheongchun[str_to_idx[e]].emplace_back(str_to_idx[s], cost);
        }
        else {
            mugunghwa[str_to_idx[s]].emplace_back(str_to_idx[e], cost);
            mugunghwa[str_to_idx[e]].emplace_back(str_to_idx[s], cost);
        }
    }

    // 내일로 O
    double sum1 = 0;
    for (int i = 1; i < M; i++) {
        int s = route[i - 1];
        int e = route[i];

        if (s == e) {
            continue;
        }

        sum1 += NaeilDijkstra(s, e);
    }
    sum1 += R; // 티켓값

    // 내일로 X
    double sum2 = 0;
    for (int i = 1; i < M; i++) {
        int s = route[i - 1];
        int e = route[i];

        sum2 += NormalDijkstra(s, e);
    }

    std::cout << (sum1 < sum2 ? "Yes" : "No");

    return 0;
}