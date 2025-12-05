/*
나머지?
*/

#include <iostream>
#include <vector>

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<int> seq(N);
    for (int i = 0; i < N; i++) {
        std::cin >> seq[i];
    }

    int T;
    std::cin >> T;

    int best_rem = 2e9, best_H;
    for (int i = 0; i < N; i++) {
        int rem = T % seq[i];
        if (best_rem > rem) {
            best_rem = rem;
            best_H = seq[i];
        }
    }

    std::cout << best_H;

    return 0;
}