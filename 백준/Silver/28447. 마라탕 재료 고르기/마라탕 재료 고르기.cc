/*
C(N, K)
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, K;
    std::cin >> N >> K;

    if (K == 1) {
        std::cout << 0;
        return 0;
    }

    std::vector<std::vector<int>> adj_mat(N, std::vector<int> (N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> adj_mat[i][j];
        }
    }

    std::vector<bool> ids(N);
    for (int i = N - 1; i >= N - K; i--) {
        ids[i] = true;
    }

    int best = -2e9;
    do {
        std::vector<int> selected;
        for (int i = 0; i < N; i++) {
            if (ids[i]) {
                selected.emplace_back(i);
            }
        }

        int sum = 0;
        for (int i = 0; i < K - 1; i++) {
            for (int j = i + 1; j < K; j++) {
                sum += adj_mat[selected[i]][selected[j]];
            }
        }
        best = std::max(best, sum);
    } while (std::next_permutation(ids.begin(), ids.end()));

    std::cout << best;

    return 0;
}