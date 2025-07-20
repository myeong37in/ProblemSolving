// https://www.acmicpc.net/problem/1007
// 벡터 매칭
// 골드 2

/*
점의 개수가 20보다 작거나 같다. 점 N개를 을 출발점 N/2개와 도착점 N/2개로 나눈다. 
벡터의 합은 모든 출발점-도착점이 이루는 벡터의 x좌표 증가량과 y좌표 증가량을 합한 것이다.
즉, (도착점x - 출발점x) + (도착점y - 출발점y)를 모든 조합에서 합하면 된다.
최대 경우의 수: C(20,10) = 184756

모든 좌표의 x좌표 합을 a, 선택한 요소들의 x좌표 합을 b, 선택되지 못한 요소들의 x좌표 합을 c라고 하면
c = a - b
구하는 것: b - c = 2b - a
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

std::vector<std::pair<int, int>> coords;
std::vector<double> results;

// 백트래킹으로 NC2개의 조합을 구하여 각 조합에 대해 벡터의 합의 길이를 계산, results에 저장하는 함수
void Combination(std::vector<std::pair<int, int>>& selected, int idx, const int& max, const int& sum_x, const int& sum_y) {
    if (selected.size() == max) {
        std::pair<int, int> answer = {0, 0};
        for (const auto& p : selected) {
            answer.first += p.first;
            answer.second += p.second;
        }

        answer.first = 2 * answer.first - sum_x;
        answer.second = 2 * answer.second - sum_y;
        results.emplace_back(std::sqrt(1LL * answer.first * answer.first + 1LL * answer.second * answer.second));

        return;
    }

    for (int i = idx; i < coords.size(); i++) {
        selected.emplace_back(coords[i]);
        Combination(selected, i + 1, max, sum_x, sum_y);
        selected.pop_back();
    }
}

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;

    while (T--) {
        int N;
        std::cin >> N;

        coords.assign(N, std::pair<int, int> {});
        int sum_x = 0;
        int sum_y = 0;
        for (int i = 0; i < N; i++) {
            std::cin >> coords[i].first >> coords[i].second;
            sum_x += coords[i].first;
            sum_y += coords[i].second;
        }

        std::vector<std::pair<int, int>> selected;
        Combination(selected, 0, N / 2, sum_x, sum_y);

        std::cout << std::fixed << std::setprecision(12) << *std::min_element(results.begin(), results.end());

        std::cout << "\n";
        results.clear();
    }

    return 0;
}