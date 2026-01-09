/*
단순 시뮬레이션인 듯

???
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int T;
    std::cin >> T;

    while (T--) {
        int W, N;
        std::cin >> W >> N;

        std::vector<std::pair<int, int>> seq(N);
        for (int i = 0; i < N; i++) {
            std::cin >> seq[i].first >> seq[i].second;
        }

        // ????
        // std::sort(seq.begin(), seq.end(), [](const auto& a, const auto& b) {
        //     return a.first < b.first;
        // });

        int sum = 0, prev_pos = 0, cap = 0;
        for (int i = 0; i < N; i++) {
            auto [x, w] = seq[i];

            sum += x - prev_pos;
            if (cap + w > W) { // 2번 경우
                sum += 2 * x; // 갔다오기
                
                if (w == W) { // 싣고 돌아가기
                    sum += x;
                    prev_pos = 0;
                }
                else { // 싣고 다음으로
                    cap = w;
                    prev_pos = x;
                }
            }
            else if (cap + w == W) { // 1번 경우, 싣고 돌아가기
                sum += x;
                prev_pos = 0;
                cap = 0;
            }
            else { // 싣고 다음으로
                cap += w;
                prev_pos = x;
            }
        }

        sum += prev_pos; // 마지막에 돌아오기

        std::cout << sum << "\n";
    }
    
    return 0;
}