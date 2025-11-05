/*
정렬 + 이분 탐색 O((N + M) logN)
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct State {
    int stat, order;
    std::string title;
};

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;

    std::vector<State> vec(N);
    for (int i = 0; i < N; i++) {
        std::cin >> vec[i].title >> vec[i].stat;
        vec[i].order = i;
    }

    std::sort(vec.begin(), vec.end(), [](const State& a, const State& b) {
        if (a.stat == b.stat) {
            return a.order < b.order;
        }
        return a.stat < b.stat;
    });

    int n;
    for (int i = 0; i < M; i++) {
        std::cin >> n;

        int idx = std::lower_bound(vec.begin(), vec.end(), n, [](const State& a, int k) {
            return a.stat < k;
        }) - vec.begin();
        std::cout << vec[idx].title << "\n";
    }

    return 0;
}