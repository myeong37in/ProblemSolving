#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

struct Query {
    int l, r, idx;
};

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, t;
    std::cin >> n >> t;

    std::vector<int> seq(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> seq[i];
    }

    std::vector<Query> queries(t);
    for (int i = 0; i < t; i++) {
        std::cin >> queries[i].l >> queries[i].r;
        queries[i].idx = i;
    }

    int bucket_size = std::sqrt(n);
    std::sort(queries.begin(), queries.end(), [&](const Query& a, const Query& b) {
        if (a.l / bucket_size == b.l / bucket_size) {
            return a.r < b.r;
        }
        return a.l < b.l;
    });

    int start = 1, end = 0;
    long long res = 0; // 이렇게 하면 매번 구간 안 봐도 될 듯
    std::vector<long long> ans(t);
    constexpr int MAX = 1e6;
    std::vector<int> freqs(MAX + 1);
    for (const auto& [l, r, id] : queries) {
        while (l > start) { // 왼쪽 끝 축소
            int& cur = freqs[seq[start]];
            res -= 1LL * cur * cur * seq[start];
            cur--;
            res += 1LL * cur * cur * seq[start];
            start++;
        }
        while (l < start) { // 왼쪽 끝 확장
            start--;
            int& cur = freqs[seq[start]];
            res -= 1LL * cur * cur * seq[start];
            cur++;
            res += 1LL * cur * cur * seq[start];
        }

        while (r > end) { // 오른쪽 끝 확장
            end++;
            int& cur = freqs[seq[end]];
            res -= 1LL * cur * cur * seq[end];
            cur++;
            res += 1LL * cur * cur * seq[end];
        }
        while (r < end) { // 오른쪽 끝 축소
            int& cur = freqs[seq[end]];
            res -= 1LL * cur * cur * seq[end];
            cur--;
            res += 1LL * cur * cur * seq[end];
            end--;
        }

        ans[id] = res;
    }

    for (const long long& n : ans) {
        std::cout << n << "\n";
    }

    return 0;
}