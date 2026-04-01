/*
시뮬레이션 문제 같군요

레일은 앞에서 빼고 뒤로 넣어야 하므로 deque

한 번에 우선순위 하나만 보면 된다. 우선순위 별로 몇 개씩 있는지 저장해 두고 적재된 것들에서 개수를 세면 될 듯
*/

#include <iostream>
#include <vector>
#include <deque>

int main(int argc, char* argv[]){
    // std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    std::cin >> N >> M;

    std::deque<std::pair<int, int>> deq;
    std::vector<int> priority_cnts(M + 1);
    int P, W;
    for (int i = 0; i < N; i++) {
        std::cin >> P >> W;
        deq.push_back({P, W});
        priority_cnts[P]++;
    }

    int target_priority = M; // 현재 적재해야 하는 컨테이너의 우선순위
    int ans = 0;
    int cur_priority_cnt = 0; // 현재 적재된 우선순위가 target_priority인 컨테이너가 몇 개인지
    std::deque<std::pair<int, int>> loaded; // 적재된 컨테이너들
    while (target_priority > 0) {
        // "낮은 우선순위의 컨테이너들이 모두 적재되지 않은 상태에서 높은 우선순위의 컨테이너가 온다면 레일의 처음으로 보낸다."
        while (!deq.empty() && deq.front().first != target_priority) {
            ans += deq.front().second;
            deq.push_back(deq.front());
            deq.pop_front();
        }

        auto& container = deq.front();
        std::vector<std::pair<int, int>> tmp; // 예시에서의 '나머지 공간'. 무거운 컨테이너가 들어왔을 때 가벼운 컨테이너 임시 저장

        // "우선순위는 같으나, 무게가 가벼운 컨테이너가 먼저 적재돼 있을 경우, 가벼운 컨테이너가 무거운 컨테이너 위로 갈 수 있도록 컨테이너를 빼내고 다시 적재한다. 이 과정을, 가벼운 컨테이너가 모두 빠질 때까지 반복한다.""
        while (!loaded.empty() && loaded.back().first == container.first && loaded.back().second < container.second) {
            ans += loaded.back().second;
            tmp.emplace_back(loaded.back());
            loaded.pop_back();
        }

        // 현재 들어온 컨테이너 적재
        ans += container.second;
        loaded.push_back(container);
        deq.pop_front();

        // 가벼운 컨테이너들 다시 적재
        for (int i = static_cast<int>(tmp.size()) - 1; i >= 0; --i) {
            ans += tmp[i].second;
            loaded.push_back(tmp[i]);
        }

        cur_priority_cnt++;

        // 이 우선순위의 컨테이너를 모두 규칙에 맞게 쌓았음. 다음으로
        if (cur_priority_cnt == priority_cnts[target_priority]) {
            cur_priority_cnt = 0;
            target_priority--;
        }
    }

    std::cout << ans;

    return 0;
}