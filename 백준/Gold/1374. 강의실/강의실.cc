#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

struct Class {
    int start, end;
};

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    int n, s, e;
    std::vector<Class> classes(N);
    for (int i = 0; i < N; i++) {
        std::cin >> n >> s >> e;
        classes[i] = {s, e};
    }

    std::sort(classes.begin(), classes.end(), [](const Class& a, const Class& b) {
        if (a.start == b.start) {
            return a.end < b.end;
        }
        return a.start < b.start;
    });

    std::priority_queue<int, std::vector<int>, std::greater<>> pq;
    int ans = 0;
    for (auto& [start, end] : classes) {
        if (!pq.empty() && pq.top() <= start) {
            pq.pop();
        }

        pq.push(end);
        ans = std::max(ans, static_cast<int>(pq.size()));
    }

    std::cout << ans;

    return 0;
}