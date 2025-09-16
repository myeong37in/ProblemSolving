/*
끝점 기준 정렬 후 시작점 최소 힙에

힙의 top이 철로 시작 현재 선분이 포함되지 않으면 시작 옮기기
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

struct Segment {
    int start, end;
};

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<Segment> vec(n);
    for (int i = 0; i < n; i++) {
        std::cin >> vec[i].start >> vec[i].end;
        if (vec[i].start > vec[i].end) {
            std::swap(vec[i].start, vec[i].end);
        } 
    }

    int d;
    std::cin >> d;

    std::sort(vec.begin(), vec.end(), [](const Segment& a, const Segment& b) {
        return a.end < b.end;   
    });

    int best = 0;
    std::priority_queue<int, std::vector<int>, std::greater<>> pq;
    for (int i = 0; i < n; i++) {
        const auto& [start, end] = vec[i];
        pq.push(start);
        while (!pq.empty() && pq.top() < end - d) {
            pq.pop();
        }

        best = std::max(best, static_cast<int>(pq.size()));
    }

    std::cout << best;

    return 0;
}