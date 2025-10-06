/*
조건
A에서 1인 bit가 B에서 1인 bit 모두에 포함되어야 함
    A | B = B

선택 가능한 버튼은 켜야 하는 bit 조합 need에서 1인 bit만을 1인 bit로 포함해야 함
    어떤 버튼 a_i에 대해 a_i | need = need면 a_i는 선택 가능
    모든 선택 가능 버튼 a_1, a_2, ..., a_k에 대해, (a_1 | a_2 | ... | a_k) & need = need

만족 안 하면 불가능

bit는 최대 30개니까 최대 30번이면 충분
*/

#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, A, B;
    std::cin >> n >> A >> B;

    std::vector<int> btns(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> btns[i];
    }

    if ((A | B) != B) {
        std::cout << -1;
        return 0;
    }

    std::vector<std::pair<int, int>> valid_btns;
    for (int i = 1; i <= n; i++) {
        if ((btns[i] | B) == B) {
            valid_btns.emplace_back(btns[i], i);
        }
    }

    int need = (B & (~A));
    int all_btns_or = 0;
    for (int i = 0; i < valid_btns.size(); i++) {
        all_btns_or |= valid_btns[i].first;
    }

    if ((all_btns_or & need) != need) {
        std::cout << -1;
        return 0;
    }

    // 켜야 하는 비트를 하나 이상 켜는 버튼을 선택
    std::vector<int> ans;
    while (need != 0) {
        for (int i = 0; i < valid_btns.size(); i++) {
            if ((need & valid_btns[i].first) > 0) {
                ans.emplace_back(valid_btns[i].second);
                need = need & (~valid_btns[i].first); // 선택한 버튼의 비트는 필요 비트에서 끄기
                break;
            }
        }
    }

    std::cout << ans.size() << "\n";
    for (const int& n : ans) {
        std::cout << n << " ";
    }

    return 0;
}