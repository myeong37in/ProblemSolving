/*
최선: 자신만 +500점
최악: 다른 사람 +500점 -> 자신만 -500점

O(N^2) 비교
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

struct Beekeeper {
    std::string name;
    int score;
};

static inline bool Cmp(const Beekeeper& a, const Beekeeper& b) {
    if (a.score == b.score) {
        return a.name < b.name;
    }
    return a.score > b.score;
}

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<Beekeeper> beekeepers(n);
    for (int i = 0; i < n; i++) {
        std::cin >> beekeepers[i].name;

        int total = 0, b;
        for (int j = 0; j < 5; j++) {
            std::cin >> b;
            total += b;
        }

        beekeepers[i].score = total;
    }

    for (int i = 0; i < n; i++) {
        beekeepers[i].score += 500; // +500점 가정
        int rank = 1;
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }

            if (!Cmp(beekeepers[i], beekeepers[j])) {
                rank++;
            }
        }

        std::cout << rank << " ";

        beekeepers[i].score -= 1000; // -500점 가정
        rank = 1;
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }

            if (!Cmp(beekeepers[i], beekeepers[j])) {
                rank++;
            }
        }

        std::cout << rank << "\n";

        beekeepers[i].score += 500; // 원위치
    }

    return 0;
}