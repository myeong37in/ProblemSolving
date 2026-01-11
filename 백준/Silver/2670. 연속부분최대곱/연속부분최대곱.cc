/*
완전 탐색으로 갑시다
*/

#include <iostream>
#include <vector>
#include <iomanip>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<double> seq(N);
    for (int i = 0; i < N; i++) {
        std::cin >> seq[i];
    }

    double best = 0;
    for (int s = 0; s < N; s++) {
        double cur = 1;
        for (int e = s; e < N; e++) {
            cur *= seq[e];
            best = std::max(best, cur);
        }
    }

    std::cout << std::fixed << std::setprecision(3) << best;

    return 0;
}