/*
무수한 33점 끝에 깨달은 것이 있다. 이건 값을 직접 계산하는 식으로 가면 풀 수 없음. Python으로 해도 마찬가지
*/

#include <iostream>
#include <vector>
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

    int prev = seq[0];
    long long answer = 0;
    std::vector<long long> multiple_count(N);
    for (int i = 1; i < N; i++) {
        int current = seq[i];
        long long multiple_of_current_to_reach_prev = std::ceil(std::log2((static_cast<double>(prev) / current))) + multiple_count[i - 1]; // 2배를 몇 번 해줘야 하는지

        if (multiple_of_current_to_reach_prev > 0) {
            multiple_count[i] = multiple_of_current_to_reach_prev;
            answer += multiple_of_current_to_reach_prev;
        }

        prev = current;
    }

    std::cout << answer;
    
    return 0;
}