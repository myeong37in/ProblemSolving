/*
=1781?

강의를 d 오름차순으로 정렬, 하나씩 p 오름차순의 힙에 추가하면서 추가한 강의의 d보다 힙의 크기가 커지면 버리기
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

struct Lecture {
    int d, p;
};

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<Lecture> lectures(n);
    
    int d, p;
    for (int i = 0; i < n; i++) {
        std::cin >> lectures[i].p >> lectures[i].d;
    }

    std::sort(lectures.begin(), lectures.end(), [](const auto& a, const auto& b) {
        return a.d < b.d;
    });

    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        const auto [d, p] = lectures[i];
        pq.push(p);
        ans += p;

        while (pq.size() > d) {
            ans -= pq.top();
            pq.pop();
        }
    }

    std::cout << ans;

    return 0;
}