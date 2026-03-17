/*
우선 기차를 나열

i번 기차가 가운데에 온다고 하면,

i번보다 왼쪽에 배치할 수 있는 기차는 i번 기차보다 수가 큰 것들
-> 순서를 바꿀 수 없으므로 LIS의 길이가 최대 왼쪽에 올 수 있는 기차 개수임

i번보다 오른쪽에 배치할 수 있는 기차는 i번 기차보다 수가 작은 것들
-> 순서를 바꿀 수 없으므로 LDS임.

2000개의 기차에 대해 O(N^2 logN)으로 해결 가능할 듯
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    std::cin >> N;

    std::vector<int> seq(N);
    for (int i = 0; i < N; i++) {
        std::cin >> seq[i];
    }

    int best = 0;
    for (int m = 0; m < N; m++) {
        // LIS의 길이 구하기
        std::vector<int> lis_len = {seq[m]};
        std::vector<int> lds_len = {seq[m]};
        for (int l = m + 1; l < N; l++) {
            if (seq[l] < seq[m]) {
                continue;
            }

            if (seq[l] > lis_len.back()) {
                lis_len.emplace_back(seq[l]);
            }
            else {
                auto it = std::lower_bound(lis_len.begin(), lis_len.end(), seq[l]);
                lis_len[it - lis_len.begin()] = seq[l];
            }
        }

        // LDS의 길이 구하기
        for (int r = m + 1; r < N; r++) {
            if (seq[r] > seq[m]) {
                continue;
            }

            if (seq[r] < lds_len.back()) {
                lds_len.emplace_back(seq[r]);
            }
            else {
                auto it = std::lower_bound(lds_len.begin(), lds_len.end(), seq[r], std::greater<int>());
                lds_len[it - lds_len.begin()] = seq[r];
            }
        }

        // m 중복 빼기
        best = std::max(best, static_cast<int>(lis_len.size() + lds_len.size() - 1));
    }

    std::cout << best;
    
    return 0;
}