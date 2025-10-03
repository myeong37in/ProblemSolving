#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<int> seq(N);
    for (int i = 0; i < N; i++) {
        std::cin >> seq[i];
    }

    std::sort(seq.begin(), seq.end());

    int best = 0;
    long long sum = 0;
    if (N & 1) {
        best = (N - 1) / 2;
    }
    else {
        int idx = N / 2;
        long long cur = 0;
        for (int i = 0; i < N; i++) {
            cur += std::abs(seq[i] - seq[idx]);
        }
        idx--;
        sum = cur;
        best = idx;

        cur = 0;
        for (int i = 0; i < N; i++) {
            cur += std::abs(seq[i] - seq[idx]);
        }

        if (cur < sum) {
            best = idx;
        }
    }

    std::cout << seq[best];

    return 0;
}