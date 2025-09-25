/*
(아마도) 출제자가 의도했을 것으로 추정되는 방법으로 풀어 봅시다.

O(2^M)
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;

    std::vector<std::pair<int, int>> chapters(M);
    for (int i = 0; i < M; i++) {
        std::cin >> chapters[i].first >> chapters[i].second;
    }

    int best = 0;
    for (int cnt = 1; cnt <= M; cnt++) {
        std::vector<int> selected(M);
        for (int i = M - 1; i >= M - cnt; i--) {
            selected[i] = 1;
        }

        do {
            int time = 0;
            int pages = 0;
            for (int i = 0; i < M; i++) {
                if (selected[i]) {
                    time += chapters[i].first;
                    pages += chapters[i].second;
                }
            }

            if (time > N) {
                continue;
            }

            best = std::max(best, pages);
        } while (std::next_permutation(selected.begin(), selected.end()));
    }

    std::cout << best;
    
    return 0;
}