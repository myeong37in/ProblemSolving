/*
dp[i]: 합이 i가 되는 부분합 수
dp[0] = 1 (아무것도 안 넣음)
각 무게 i에 대해 물건의 무게가 w일 때 dp[i] = dp[i] + dp[i - w]

MLE 발생?? dp의 크기가 너무 크다.

meet in the middle
물건을 반으로 나눠서 각 집합에서 부분합을 구해 저장, 투 포인터로 개수 세기
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, C;
    std::cin >> N >> C;

    int A_size = N / 2;
    int B_size = N - A_size;
    
    std::vector<int> weight_A(N);
    std::vector<int> weight_B(N);
    for (int i = 0; i < A_size; i++) {
        std::cin >> weight_A[i];
    }
    for (int i = 0; i < B_size; i++) {
        std::cin >> weight_B[i];
    }

    std::vector<long long> sum_A;
    std::vector<long long> sum_B;

    // N이 30보다 작거나 같은 자연수 -> 각 weight_A, weight_B의 크기는 15 이하 -> bitmask로 부분합 구할 수 있음
    for (int mask = 0; mask < (1 << A_size); mask++) {
        long long partial_sum = 0;
        for (int i = 0; i < A_size; i++) {
            if (mask & (1 << i)) {
                partial_sum += weight_A[i];
            }
        }
        sum_A.emplace_back(partial_sum);
    }

    for (int mask = 0; mask < (1 << B_size); mask++) {
        long long partial_sum = 0;
        for (int i = 0; i < B_size; i++) {
            if (mask & (1 << i)) {
                partial_sum += weight_B[i];
            }
        }
        sum_B.emplace_back(partial_sum);
    }
    
    std::sort(sum_A.begin(), sum_A.end());
    std::sort(sum_B.begin(), sum_B.end());

    long long answer = 0;
    for (int i = 0; i < sum_A.size(); i++) {
        answer += std::upper_bound(sum_B.begin(), sum_B.end(), C - sum_A[i]) - sum_B.begin();
    }

    std::cout << answer;

    return 0;
}