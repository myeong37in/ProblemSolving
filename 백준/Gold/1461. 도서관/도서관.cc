/*
왼쪽(음수 좌표)에서 끝내는 것과 오른쪽(양수 좌표)에서 끝내는 것의 차이를 보면 됨

절댓값 크기 순으로 x1, x2, x3, x4가 있다고 하고 M = 3이라면 x2, x3, x4를 가져가야 2 * x1의 추가 이동이 붙으므로 최소 이동
-> 절댓값 크기 내림차순으로 M개씩 가져가는 것이 이득

왼쪽에서 끝내면 음수 좌표로 가장 큰 M개는 한 번만 이동, 오른쪽에서 끝내면 양수 좌표
*/

#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N, M;
    std::cin >> N >> M;

    std::vector<int> neg, pos;
    int n;
    for (int i = 0; i < N; i++) {
        std::cin >> n;
        if (n < 0) {
            neg.emplace_back(-n);
        }
        else {
            pos.emplace_back(n);
        }
    }

    std::sort(neg.begin(), neg.end(), std::greater<int>());
    std::sort(pos.begin(), pos.end(), std::greater<int>());

    if (neg.empty()) {
        // 음수 좌표 없음 -> 항상 오른쪽에서 끝
        int ans = pos[0];
        int idx = M;
        while (idx < pos.size()) {
            ans += 2 * pos[idx];
            idx += M;
        }

        std::cout << ans;
        return 0;
    }
    else if (pos.empty()) {
        // 양수 좌표 없음 -> 항상 왼쪽에서 끝
        int ans = neg[0];
        int idx = M;
        while (idx < neg.size()) {
            ans += 2 * neg[idx];
            idx += M;
        }

        std::cout << ans;
        return 0;
    }
    else {
        // 왼쪽에서 끝내는 경우
        int ans1 = neg[0];
        int idx = M;
        while (idx < neg.size()) {
            ans1 += 2 * neg[idx];
            idx += M;
        }

        idx = 0;
        while (idx < pos.size()) {
            ans1 += 2 * pos[idx];
            idx += M;
        }

        // 오른쪽에서 끝내는 경우
        int ans2 = pos[0];
        idx = M;
        while (idx < pos.size()) {
            ans2 += 2 * pos[idx];
            idx += M;
        }

        idx = 0;
        while (idx < neg.size()) {
            ans2 += 2 * neg[idx];
            idx += M;
        }

        std::cout << std::min(ans1, ans2);
    }
    
    return 0;
}