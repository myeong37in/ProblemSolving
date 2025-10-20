/*
정렬하고 앞으로 동률 탐색
*/

#include <iostream>
#include <vector>
#include <algorithm>

struct Medals {
    int idx, gold, silver, bronze;
};

int main(int argc, char* argv[]){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, K;
    std::cin >> N >> K;

    std::vector<Medals> ranks;
    int idx, gold, silver, bronze;
    for (int i = 0; i < N; i++) {
        std::cin >> idx >> gold >> silver >> bronze;
        ranks.emplace_back(Medals {idx, gold, silver, bronze});
    }

    std::sort(ranks.begin(), ranks.end(), [](const Medals& a, const Medals& b) {
        if (a.gold == b.gold) {
            if (a.silver == b.silver) {
                return a.bronze > b.bronze;
            }
            return a.silver > b.silver;
        }
        return a.gold > b.gold;
    });

    for (int i = 0; i < N; i++) {
        if (ranks[i].idx == K) {
            while (i > 0 && ranks[i - 1].gold == ranks[i].gold && ranks[i - 1].silver == ranks[i].silver && ranks[i - 1].bronze == ranks[i].bronze) {
                i--;
            }
            
            std::cout << i + 1;
            break;
        }
    }

    return 0;
}