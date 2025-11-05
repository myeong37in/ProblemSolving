/*
정렬도 필요 없네

이분 탐색 O(M logN)
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct State {
    int stat;
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
    }

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