/*
a값에 대해 정렬, b값 기준 최대 힙에 넣으면서 M - a보다 큰 값은 빼주면 힙의 크기가 사람 수가 될 것
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;

    std::vector<std::pair<int, int>> seq;
    int a, b;
    for (int i = 0; i < N; i++) {
        std::cin >> a >> b;

        // 불가능
        if (a + b > M) {
            continue;
        }

        seq.emplace_back(a, b);
    }

    std::sort(seq.begin(), seq.end(), [](const auto& a, const auto& b) {
        return a.first < b.first;
    });

    std::priority_queue<int> pq;

    int sz = seq.size();
    int ans = 0;
    // 하나씩 순회할 때마다 필요한 a를 준다고 가정, 이때까지 M - a보다 많이 필요했던 사람들은 빠져야 함
    for (int i = 0; i < sz; i++) {
        auto& [a, b] = seq[i];
        
        while (!pq.empty() && pq.top() > M - a) {
            pq.pop();
        }

        pq.push(b);

        ans = std::max(ans, static_cast<int>(pq.size()));
    }

    std::cout << ans;

    return 0;
}