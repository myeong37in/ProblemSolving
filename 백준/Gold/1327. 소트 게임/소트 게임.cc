/*
풀이법은 명백하고, 저장을 해시로 하면 될 듯?
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <algorithm>

constexpr int POWER = 10;

int bfs(const std::vector<int>& start, int N, int K) {
    std::unordered_set<int> visited;
    std::queue<std::pair<std::vector<int>, int>> q;
    q.push({start, 0});
    int hash = 0;
    int mult = 1;
    for (int i = 0; i < N; i++) {
        hash += start[i] * mult;
        mult *= POWER;
    }
    visited.insert(hash);

    while (!q.empty()) {
        auto [seq, turn] = q.front();
        q.pop();

        bool is_sorted = true;
        int prev = seq.front();
        for (int i = 1; i < N; i++) {
            if (seq[i] < prev) {
                is_sorted = false;
                break;
            }
            prev = seq[i];
        }

        if (is_sorted) {
            return turn;
        }

        for (int i = 0; i < N - K + 1; i++) {
            std::vector<int> temp = seq;
            std::reverse(temp.begin() + i, temp.begin() + i + K);

            int hash = 0;
            int mult = 1;
            for (int j = 0; j < N; j++) {
                hash += temp[j] * mult;
                mult *= POWER;
            }

            if (visited.insert(hash).second == true) {
                q.push({temp, turn + 1});
            }
        }
    }

    return -1;
}

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, K;
    std::cin >> N >> K;

    std::vector<int> seq(N);
    for (int i = 0; i < N; i++) {
        std::cin >> seq[i];
    }

    int ans = bfs(seq, N, K);
    std::cout << ans;

    return 0;
}