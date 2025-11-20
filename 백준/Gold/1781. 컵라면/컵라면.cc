/*
데드라인 오름차순으로 정렬

보상량의 최소 힙을 만들고 문제들을 하나씩 먹으면서 먹은 문제의 개수(힙의 크기)가 데드라인보다 커지면 힙에서 그만큼 버린다.

완성
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<std::pair<int, int>> seq(N);

    int d, p;
    for (int i = 0; i < N; i++) {
        std::cin >> d >> p;
        seq[i] = {d, p};
    }

    std::sort(seq.begin(), seq.end(), [](const auto& a, const auto& b) {
        return a.first < b.first;
    });

    std::priority_queue<int, std::vector<int>, std::greater<>> pq;
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        auto [deadline, profit] = seq[i];
        pq.push(profit);
        sum += profit;

        while (pq.size() > deadline) {
            sum -= pq.top();
            pq.pop();
        }
    }

    std::cout << sum;

    return 0;
}