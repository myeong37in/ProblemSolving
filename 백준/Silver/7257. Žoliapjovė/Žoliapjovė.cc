/*
활성 잔디의 개수를 유지하면 되겠군

정렬 후 이분 탐색으로 찾기
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    long long N;
    std::cin >> N;

    std::vector<long long> grass(N);
    std::vector<long long> psum(N + 1);
    for (int i = 0; i < N; i++) {
        std::cin >> grass[i];
    }

    std::sort(grass.begin(), grass.end());

    for (int i = 0; i < N; i++) {
        psum[i + 1] = psum[i] + grass[i];
    }

    long long M;
    std::cin >> M;

    long long active = N; // 살아 있는 잔디 수
    long long cut_sum = 0;
    int cut = 0;
    for (int day = 1; day <= M; day++) {
        std::cin >> cut;
        cut_sum += cut;

        long long height = cut_sum - day;

        auto it = std::upper_bound(grass.begin(), grass.end(), height); // 살아남은 첫 번째 잔디의 위치
        int idx = it - grass.begin();

        active =  N - idx;
        if (active == 0) {
            std::cout << "0\n";
            continue;
        }

        long long sum_alive_a = psum[N] - psum[idx];
        std::cout << sum_alive_a - active * height << "\n";
    }
    
    return 0;
}