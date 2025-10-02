/*
덱으로 하면 될 듯

시간 시뮬 돌려도 되고
*/

#include <iostream>
#include <vector>
#include <deque>

int main(int argc, char* argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, W, L;
    std::cin >> N >> W >> L;

    std::vector<int> trucks(N);
    for (int i = 0; i < N; i++) {
        std::cin >> trucks[i];
    }

    std::deque<std::pair<int, int>> deq;
    int on_bridge = 0;
    int time = 1;
    int idx = 0;
    int cnt = 0;
    while (true) {
        if (!deq.empty() && deq.front().first <= time) {
            on_bridge -= deq.front().second;
            deq.pop_front();
            cnt++;
        }

        if (cnt == N) {
            break;
        }

        if (idx < N && on_bridge + trucks[idx] <= L) {
            deq.push_back({time + W, trucks[idx]});
            on_bridge += trucks[idx];
            idx++;
        }
        
        time++;
    }

    std::cout << time;

    return 0;
}