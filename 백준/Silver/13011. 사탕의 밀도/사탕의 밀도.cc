/*
정답일 때 밀도를 x라고 하면

summation from i = 0 to i = N - 1, abs(C[i] * x - W[i])을 최소화하는 x가 답임.

최대 50개의 절댓값 식에 대해, W[i] / C[i] 순으로 정렬하고

양수와 음수의 경계를 수식의 항을 기준으로 나누면 x의 범위가 나오고 그때 얻는 수식에서 x의 범위에 따라 최솟값을 구할 수 있음

예시 입력 3에서
3
10 20 40
4000 2000 1000

abs(10x - 4000) + abs(20x - 2000) + abs(40x - 1000)을 최소화

10x - 4000 >= 0일 때, 전체 식은 70x - 7000, x >= 400

x = 400일 때 최솟값 21,000

10x - 4800 < 0 && 20x - 2000 >= 0 -> 100 <= x < 400일 때

-(10x - 4000) + 20x - 2000 + 40x - 1000 = 50x + 1000

x = 100일 때 최솟값 6000

20x - 2000 < 0 && 40x - 1000 >= 0 -> 25 <= x < 100일 때

-(10x - 4000) - (20x - 2000) + 40x - 1000 = 10x + 5000

x = 25일 때 최솟값 5250

40x - 1000 < 0 -> x < 25일 때

-70x + 7000. 최솟값 5250(보다 약간 큰 값)
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    std::cin >> N;

    std::vector<std::pair<double, double>> baskets(N);
    for (int i = 0; i < N; i++) {
        std::cin >> baskets[i].first;
    }
    for (int i  = 0; i < N; i++) {
        std::cin >> baskets[i].second;
    }

    std::sort(baskets.begin(), baskets.end(), [](const auto& a, const auto& b) {
        return a.second / a.first > b.second / b.first;
    });

    double ans = 2e12;
    // 모든 항이 양수일 때부터 모든 항이 음수일 때까지 하나씩
    for (int neg_term_cnt = 0; neg_term_cnt <= N; neg_term_cnt++) {
        double C_total = 0, W_total = 0;
        double min_x = 0, max_x = 2e9;

        // 음수인 항은 부호를 뒤집어서 더함. 밀도의 최댓값이 정해짐
        for (int i = 0; i < neg_term_cnt; i++) {
            C_total -= baskets[i].first;
            W_total -= baskets[i].second;
            max_x = std::min(max_x, baskets[i].second / baskets[i].first);
        }

        // 양수인 항은 그대로 더함. 밀도의 최솟값이 정해짐
        for (int i = neg_term_cnt; i < N; i++) {
            C_total += baskets[i].first;
            W_total += baskets[i].second;
            min_x = std::max(min_x, baskets[i].second / baskets[i].first);
        }

        ans = std::min(ans, C_total * min_x - W_total);
    }

    std::cout << std::fixed << std::setprecision(9) << ans; 

    return 0;
}