/*
pq Dijkstra
시간: (V+E)logV = (V+2T)logV = 6.14억
메모리: V+E = V+2T. int로 최소 400MB
-> 시간, 메모리 불가능

Dial
시간: VL + E = 0.75억
메모리: VL + E
-> 메모리 불가능. 근데 V+L+E 구현이라면 가능할지도?

인접 행렬 Dijkstra
시간: V^2 + E(입력 처리)
메모리: V^2
-> ㅇㅇ

vector<vector<int>>는 너무 느린가?? 1차원으로 해봅시다.

그래도 느린가? int까지는 필요 없으니 short로 해봅시다.

그래도 느리면 더 빠른 IO를 써야지. 저번에 봤던 신기한 로직을 써봅시다.

바이트 스트림을 읽어서 파싱
*/

#include <vector>

#include <cstdio>

struct FastInput {
    static constexpr int BUFSIZE = 1 << 20; // 1MB 단위
    int idx, size;
    char buf[BUFSIZE];

    FastInput() : idx(0), size(0) {}

    inline char Read() {
        if (idx >= size) {
            size = (int)fread(buf, 1, BUFSIZE, stdin);
            idx = 0;
            if (size == 0) return 0; // EOF
        }
        return buf[idx++];
    }

    inline int Scan() {
        int x = 0;
        char c = Read();

        while (c < '0' || c > '9') {
            c = Read();
        }

        while ('0' <= c && c <= '9') {
            x = (x << 3) + (x << 1) + (c - '0'); // x = x * 10 + digit
            c = Read();
        }

        return x;
    }
};

int main(int argc, char* argv[]) {
    FastInput in;
    int N = in.Scan();

    constexpr short SHORT_INF = 30'000;
    constexpr int INT_INF = 2e9;
    // std::vector<std::vector<int>> adj(N + 1, std::vector<int> (N + 1, INF));
    std::vector<short> adj((N + 1) * (N + 1), SHORT_INF);

    auto GetIdx = [&](int u, int v) {
        return u * (N + 1) + v;
    };
    
    int T = in.Scan();

    int u, v;
    short d;
    while (T--) {
        u = in.Scan();
        v = in.Scan();
        d = static_cast<short>(in.Scan());

        // 중복 간선 고려
        adj[GetIdx(u, v)] = adj[GetIdx(v, u)] = std::min(adj[GetIdx(u, v)], d);
    }

    for (int i = 1; i <= N; i++) {
        adj[GetIdx(i, i)] = 0;
    }

    std::vector<int> dists(N + 1, INT_INF);
    std::vector<char> visited(N + 1, 0);
    
    int K = in.Scan();
    
    int dd;
    while (K--) {
        u = in.Scan();
        dd = in.Scan();
        dists[u] = std::min(dists[u], dd);
    }

    int D = in.Scan();
    
    for (int iter = 0; iter < N; iter++) {
        int u = -1;
        // 방문하지 않은 노드 중 최단 거리 노드 찾기
        for (int i = 1; i <= N; i++) {
            if (!visited[i] && (u == -1 || dists[u] > dists[i])) {
                u = i;
            }
        }

        if (u == -1 || dists[u] == INT_INF) {
            break;
        }

        // 답 발견 끝
        if (u == D) {
            break;
        }

        visited[u] = 1;

        int base = u * (N + 1);
        // 인접 노드 거리 relax
        for (int v = 1; v <= N; v++) {
            short w = adj[base + v];
            if (!visited[v] && w != SHORT_INF && (dists[u] + w < dists[v])) {
                dists[v] = dists[u] + w;
            }
        }
    }

    printf("%d", dists[D]);
    
    return 0;
}