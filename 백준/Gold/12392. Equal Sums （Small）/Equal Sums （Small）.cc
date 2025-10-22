/*
N is exactly equal to 20 <- 그럼 N을 왜 주는 거지..?

C(0, 20) + C(1, 20) + C(2, 20) + ... C(20, 20) = 2^20.

subset의 최댓값은 100만, 100만 조합임
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        int N;
        std::cin >> N;

        std::vector<std::vector<int>> dat(1e6 + 1);
        std::vector<int> seq(N);
        for (int i = 0; i < N; i++) {
            std::cin >> seq[i];
        }

        // 이렇게 하면 될 것 같은데
        bool found = false;
        std::cout << "Case #" << tc << ":\n";
        for (int len = 1; len <= N - 1; len++) {
            std::vector<int> selected(N);
            for (int i = N - 1; i >= N - len; i--) {
                selected[i] = 1;
            }

            do {
                std::vector<int> subset;
                int subset_sum = 0;
                for (int i = 0; i < N; i++) {
                    if (selected[i]) {
                        subset_sum += seq[i];
                        subset.emplace_back(seq[i]);
                    }
                }
                
                if (!dat[subset_sum].empty()) {
                    found = true;
                    for (const int& n : dat[subset_sum]) {
                        std::cout << n << " ";
                    }
                    std::cout << "\n";
                    for (const int& n : subset) {
                        std::cout << n << " ";
                    }
                    break;
                }

                dat[subset_sum] = subset;
            } while (std::next_permutation(selected.begin(), selected.end()));

            if (found) {
                break;
            }
        }
    
        if (!found) {
            std::cout << "Impossible";
        }
        std::cout << "\n";
    }

    return 0;
}