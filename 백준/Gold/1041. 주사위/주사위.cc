/*
보이는 면의 수를 세보면

위
3면: 4
2면: (N - 2) * 4
1면: (N - 2)^2

옆
2면: (N - 2) * 4
1면: (N - 2)^2 * 4

아래(바닥은 안 보임)
2면: 4
1면: (N - 2) * 4

근데 전개도에 따라 꼭 최소 3개 면을 선택할 수 없을 수도 있음

전처리를 좀 해야 하나..?
*/

#include <iostream>
#include <vector>
#include <algorithm>

struct Pair {
    int a, b;
};

struct Triple {
    int a, b, c;
};

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long N;
    std::cin >> N;

    std::vector<long long> num(6);
    for (int i = 0; i < 6; i++) {
        std::cin >> num[i];
    }

    if (N == 1) {
        std::cout << num[0] + num[1] + num[2] + num[3] + num[4] + num[5] - *std::max_element(num.begin(), num.end());
        return 0;
    }

    // A: 0, B: 1, C: 2, D: 3, E: 4, F: 5
    // A-F, B-E, C-D면은 서로 인접하지 않다.
    std::vector<Pair> adj_pairs = {{0, 1}, {0, 2}, {0, 3}, {0, 4}, {1, 2}, {1, 3}, {1, 5}, {2, 4}, {2, 5}, {3, 4}, {3, 5}, {4, 5}};
    std::vector<Triple> adj_triples = {{0, 1, 2}, {0, 1, 3}, {0, 2, 4}, {0, 3, 4}, {1, 2, 5}, {1, 3, 5}, {2, 4, 5}, {3, 4, 5}};
    long long trip_minval = 9e18, pair_minval = 9e18;
    for (const auto& p : adj_triples) {
        auto [a, b, c] = p;
        int cur = num[a] + num[b] + num[c];
        if (cur < trip_minval) {
            trip_minval = cur;
        }
    }
    
    for (const auto& p : adj_pairs) {
        auto [a, b] = p;
        int cur = num[a] + num[b];
        if (cur < pair_minval) {
            pair_minval = cur;
        }
    }

    long long dice_minval = *std::min_element(num.begin(), num.end());

    long long up = 4 * trip_minval + (N - 2) * 4 * pair_minval + (N - 2) * (N - 2) * dice_minval;
    long long side = (N - 2) * 4 * pair_minval + (N - 2) * (N - 2) * 4 * dice_minval;
    long long down = 4 * pair_minval + (N - 2) * 4 * dice_minval;

    std::cout << up + side + down;

    return 0;
}