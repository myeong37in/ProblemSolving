#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m, k;
    std::cin >> n >> m >> k;

    int p, c;
    std::vector<int> cards_ans(m + 1); // c번 카드에 대한 답
    std::vector<int> cards_tagged(m + 1); // c번 카드가 어디서 마지막에 찍혔는지
    for (int i = 0; i < k; i++) {
        std::cin >> p >> c;

        if (cards_tagged[c] == 0) {
            cards_tagged[c] = p;
            continue;
        }

        if (cards_tagged[c] == p) {
            // 같은 곳
            cards_ans[c] += 100;
            cards_tagged[c] = 0;
        }
        else {
            cards_ans[c] += std::abs(cards_tagged[c] - p);
            cards_tagged[c] = 0;
        }
    }

    for (int c = 1; c <= m; c++) {
        if (cards_tagged[c]) {
            cards_ans[c] += 100;
        }
    }

    for (int c = 1; c <= m; c++) {
        std::cout << cards_ans[c] << " ";
    }
    
    return 0;
}