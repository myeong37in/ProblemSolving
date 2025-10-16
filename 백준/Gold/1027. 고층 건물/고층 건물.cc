/*
기울기

double 15자리정도면 되겠지
*/

#include <iostream>
#include <vector>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<double> seq(N);
    for (int i = 0; i < N; i++) {
        std::cin >> seq[i];
    }

    int best = 0;
    for (int s = 0; s < N; s++) {
        // 좌
        double slope = 0;
        int cur = 0;
        if (s > 0) {
            slope = -(seq[s - 1] - seq[s]);
            cur++;
            for (int e = s - 2; e >= 0; e--) {
                if (-(seq[e] - seq[s]) / (s - e) < slope) { // 기울기가 단조 감소해야 가능
                    slope = -(seq[e] - seq[s]) / (s - e);
                    cur++;
                }
                else {
                    continue;
                }
            }
        }
        
        slope = 0;
        // 우
        if (s + 1 < N) {
            slope = seq[s + 1] - seq[s];
            cur++;
            for (int e = s + 2; e < N; e++) {
                if ((seq[e] - seq[s]) / (e - s) > slope) { // 기울기가 단조 증가해야 가능
                    slope = (seq[e] - seq[s]) / (e - s);
                    cur++;
                }
                else {
                    continue;
                }
            }
        }

        best = std::max(best, cur);
    }

    std::cout << best;

    return 0;
}