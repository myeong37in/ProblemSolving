/*
Rabin-Karp를 배워 봅시다.

재귀 깊이 50만 되나? 스택 프레임으로 가자
*/

#include <iostream>
#include <vector>
#include <string>

struct Edge {
    int to;
    char ch;
};

struct Frame {
    int u, child_idx; // 다음에 방문할 자식 인덱스 저장
};

constexpr int MOD = 1e9 + 7;
constexpr int BASE = 998244353;

std::vector<std::vector<Edge>> graph;

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    graph.resize(N + 1);
    int u, v;
    char ch;
    for (int i = 0; i < N - 1; i++) {
        std::cin >> u >> v >> ch;
        graph[u].emplace_back(Edge {v, ch});
    }

    std::string pattern;
    std::cin >> pattern;

    int sz = pattern.size();
    long long multiplier = 1;
    long long pattern_hash = 0;
    for (int i = 0; i < sz; i++) {
        int val = pattern[i] - 'a' + 1;
        pattern_hash = (pattern_hash * BASE + val) % MOD;
        multiplier = (multiplier * BASE) % MOD;
    }

    int ans = 0;
    std::vector<Frame> st;
    st.emplace_back(Frame {1, 0});

    std::vector<long long> hash_stack = {0};
    while (!st.empty()) {
        auto& [u, idx] = st.back();

        if (idx < graph[u].size()) {
            auto& [to, ch] = graph[u][idx++];
            int val = (ch - 'a' + 1);

            long long new_hash = (hash_stack.back() * BASE + val) % MOD; // 이전 해시 * BASE + vaL
            hash_stack.emplace_back(new_hash);

            int depth = hash_stack.size() - 1;

            // 길이 sz의 접미사 해시와 패턴 비교
            if (depth >= sz) {
                long long cur = hash_stack[depth];
                long long prev = hash_stack[depth - sz];
                long long sub = (cur - (prev * multiplier % MOD) + MOD) % MOD;
                if (sub == pattern_hash) {
                    ans++;
                }
            }

            st.emplace_back(Frame {to, 0});
        }
        else { // u의 자식을 모두 처리한 경우 백트래킹
            if (hash_stack.size() > 1) { // 루트는 pop 안 함
                hash_stack.pop_back();
            }
            st.pop_back();
        }
    }

    std::cout << ans;

    return 0;
}