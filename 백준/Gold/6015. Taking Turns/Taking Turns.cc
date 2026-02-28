#include <iostream>
#include <vector>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<long long> seq(N + 2);
    for (int i = 1; i <= N; i++) {
        std::cin >> seq[i];
    }

    std::vector<long long> cow1(N + 2), cow2(N + 2);
    long long best_val = -1;
    int best_idx = N + 1;

    for (int i = N; i >= 1; i--) {
        long long cur = seq[i] + cow2[i + 1];

        if (cur >= best_val) {
            best_val = cur;
            best_idx = i;
        }

        cow1[i] = best_val;
        cow2[i] = cow1[best_idx + 1];
    }

    std::cout << cow1[1] << " " << cow2[1];

    return 0;
}